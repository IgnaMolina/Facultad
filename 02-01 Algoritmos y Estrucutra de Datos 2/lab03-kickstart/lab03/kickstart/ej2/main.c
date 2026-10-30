/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    /* Completar aquí:
       Al finalizar la ejecución las variables deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42


       Las restricciones son:
       - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
       - Se pueden agregar líneas de código, pero no modificar las que ya existen.
       - Se pueden declarar hasta 2 punteros.
       AYUDA: podes usar GDB para consultares valores de variables y la dirección de memoria donde estan alojadas.
    */

       //Creo un puntero para x
    int *p=NULL; //Se recomienda igualarlo a null, el puntero apunta a un espacio que no se puede tocar
    p = &x;//aca apunto a la direccion de x
    *p = 9;//aca le cambio el valor sin tocar x "donde apunta p pone un 1"

    person_t *pun = &m; //aca asigno el puntero *pun a la struct person_t y al espacio &m
    (*pun).age = 100; //aca (*pun).age entra en el espacio del struct age y pone un 100
    (*pun).name_initial = 'F';// aca pasa lo mismo pero con name_initial

    *(a+1) = 42;//esto no es un puntero,el nombre de un arreglo se comporta como un puntero al primer elemento, ya estaba declarado de antes,

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

