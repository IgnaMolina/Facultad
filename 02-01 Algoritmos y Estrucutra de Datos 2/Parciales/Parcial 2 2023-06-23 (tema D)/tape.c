#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "tape.h"

struct _s_node {
    tape_elem elem;
    struct _s_node *next;
};

typedef struct _s_node * node_t;

struct _s_tape {
    unsigned int size;
    node_t cursor;  // Puntero al elemento actual
    node_t start;   // Puntero al primer nodo de la cinta
};

static bool invrep(tape_t tape) {
    if( tape == NULL){
        return false;
    }
    if(tape -> size == 0){
        if (tape->start != NULL || tape->cursor != NULL) {
            return false; // Roto: size dice cero pero los punteros no son NULL
        }
// 3. Control de consistencia si tiene elementos
    if (tape->size > 0 && tape->start == NULL) {
        return false; // Roto: dice tener elementos pero no hay primer nodo
    }
    
    // 4. Recorremos la lista para validar el tamaño real y la existencia del cursor
    node_t actual = tape->start;
    unsigned int contador_nodos = 0;
    bool cursor_encontrado = false;
    
    while (actual != NULL) {
        contador_nodos++;
        
        // Si el cursor no es NULL, verificamos si coincide con el nodo actual
        if (tape->cursor == actual) {
            cursor_encontrado = true;
        }
        
        actual = actual->next; // Avanzamos al siguiente nodo
    }
    
    // 5. Control final de coherencia
    // A) El tamaño guardado debe coincidir con la cantidad real de nodos
    if (contador_nodos != tape->size) {
        return false;
    }
    
    // B) Si el cursor no es NULL, se tuvo que haber encontrado recorriendo la lista
    if (tape->cursor != NULL && !cursor_encontrado) {
        return false; // Roto: el cursor apunta a cualquier memoria colgada por ahí
    }
    
    // Si superó todas las pruebas, la cinta está en perfecto estado
    return true;
}
}

static node_t create_node(tape_elem e) {
    /* COMPLETAR */
    node_t newnode = malloc(sizeof(struct _s_node));
    assert(newnode != NULL); 
    return newnode;
}

static node_t destroy_node(node_t node) {
    free(node);
}

tape_t tape_create(void) {
    tape_t tape=NULL;
    /* COMPLETAR */
    assert(invrep(tape) && tape_is_empty(tape) && tape_at_start(tape));
    return tape;
}

tape_t tape_rewind(tape_t tape) {
    /* COMPLETAR */
}


bool tape_at_start(tape_t tape) {
    /* COMPLETAR */
}

bool tape_at_stop(tape_t tape) {
    /* COMPLETAR */
}

bool tape_is_empty(tape_t tape) {
    /* COMPLETAR */
}

unsigned int tape_length(tape_t tape) {
    /* COMPLETAR */
}

tape_t tape_step(tape_t tape) {
    /* COMPLETAR */
}

tape_t tape_insertl(tape_t tape, tape_elem e) {
    /* COMPLETAR */
}

tape_t tape_insertr(tape_t tape, tape_elem e) {
    assert(invrep(tape) && (!tape_at_stop(tape) || tape_is_empty(tape)));
    node_t new_node=create_node(e);
    if (tape->start!= NULL) {
        new_node->next = tape->cursor->next;
        tape->cursor->next = new_node;
        tape->cursor = new_node;
    } else {
        tape->start = new_node;
        tape->cursor = new_node;
    }
    tape->size++;
    assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape) && e == tape_read(tape));
    return tape;
}

tape_t tape_erase(tape_t tape) {
    /* COMPLETAR */
}

tape_elem tape_read(tape_t tape) {
    /* COMPLETAR */
}

void tape_dump(tape_t tape) {
    assert(invrep(tape));
    node_t node=tape->start;
    printf("#");
    while (node != NULL) {
        if (node != tape->cursor) {
            printf("-%c-", node->elem);
        } else {
            printf("-[%c]-", node->elem);
        }
        node = node->next;
    }
    if (tape->cursor==NULL) {
        printf("-[]-");
    }
    printf("#\n");
}

tape_t tape_copy(tape_t tape) {
    /* COMPLETAR */
}

tape_t tape_destroy(tape_t tape) {
    /* COMPLETAR */
}


