#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
   int i = 3;
    Node *a_node; //lo declaras como Node pq si fuer aun int no podes usar a_node ->, otra forma seria List a_node
    List my_list;
    
    my_list = malloc(sizeof(Node));
    a_node = my_list;//aca no va &my_list, List my_list;es un alias de Node y ya es un puntero
    i = i-1; // Este es el primero Nodo
    while(i>0){
        a_node->data = i*10;
        a_node -> next = malloc(sizeof(struct Node));//la flecha dice "a_node es el puntero al nodo, a_node -> next significa "anda al vagon actual y entra a su enchufe para el siguiente vagon""
        a_node = a_node -> next;//a_node va a contener el gancho de a_node -> next
        i = i-1;
    }
    //termino el nodo, el 'ultimo vagon' este tiene que ser NULL
    a_node -> data = 0;
    a_node -> next = NULL;
    a_node = NULL;

    return my_list;
}

/**
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    Node *a_node;
    a_node = xs;//Esto aca dice a_node apunta a xs, '&' se usa cuando guardas la direccion de memoria nomas.
    xs = xs-> next;
    free (a_node);// Cuando haces free liberas la memoria, si usas malloc obligatoriamente tenes que liberar la memoria al final
    a_node = NULL;// si bien liberamos la memoria no borra lo que tiene a_node, con null lo haces

    return xs;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);

    return 0;
}
