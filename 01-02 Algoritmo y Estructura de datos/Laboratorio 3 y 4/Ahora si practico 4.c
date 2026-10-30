#include <stdio.h>

/* Función para intercambiar los elementos en las posiciones i y j
void intercambiar(int tam, int a[], int i, int j) {
    if (i >= 0 && i < tam && j >= 0 && j < tam) { // Comprobar que las posiciones estén en el rango
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    } else {
        printf("Error: Las posiciones deben estar en el rango de 0 a %d.\n", tam - 1);
    }
}

int main() {
    int tam;

    // Solicitar el tamaño del arreglo
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tam);

    if (tam <= 0) {
        printf("Error: El tamaño del arreglo debe ser positivo.\n");
        return 1;
    }

    int a[tam];

    // Solicitar los elementos del arreglo
    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    int i, j;

    // Solicitar las posiciones a intercambiar
    printf("Ingrese la primera posición a intercambiar (0 a %d): ", tam - 1);
    scanf("%d", &i);
    printf("Ingrese la segunda posición a intercambiar (0 a %d): ", tam - 1);
    scanf("%d", &j);

    // Realizar el intercambio
    intercambiar(tam, a, i, j);

    // Imprimir el arreglo modificado
    printf("El arreglo modificado es:\n");
    for (int k = 0; k < tam; k++) {
        printf("%d ", a[k]);
    }
    printf("\n");

    return 0;
}*/

/*Ejercicio 7
void pedir_arreglo(int tam, int arreglo[]);
void imprimir_arreglo (int tam, int arreglo[]);

int main (){
int tam;
printf("asigne el tamaño del arreglo: \n");
scanf("%d", &tam);
int arreglo[tam];

pedir_arreglo(tam, arreglo);

imprimir_arreglo( tam, arreglo);

return 0;

}

void pedir_arreglo(int tam, int arreglo[]){

printf("Ingrese el valor arreglo \n");
for (int i = 0; i < tam; i++)
{
    printf("elemento %d:",i+1);
    scanf("%d",&arreglo[i]);
}
}

void imprimir_arreglo (int tam, int arreglo[]){

    for (int k = 0; k < tam; k++) {
        printf("%d ", arreglo[k]);
    }
    printf("\n"); 
}
*/
/*Ejercio 8

#define TAM 5  // Definimos un tamaño constante para el arreglo

// Prototipo de la función que suma los elementos del arreglo
int sumatoria(int tam, int a[]);

// Prototipo de la función para pedir los valores del arreglo
void pedir_arreglo(int tam, int a[]);

int main() {
    int a[TAM];  // Declaramos el arreglo con tamaño constante TAM

    // Llenamos el arreglo con valores ingresados por el usuario
    pedir_arreglo(TAM, a);

    // Calculamos la suma del arreglo usando la función sumatoria
    int suma = sumatoria(TAM, a);

    // Imprimimos la suma de los elementos del arreglo
    printf("La suma de los elementos del arreglo es: %d\n", suma);

    return 0;
}

void pedir_arreglo(int tam, int a[]) {
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el valor para a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

int sumatoria(int tam, int a[]) {
    int suma = 1;
    for (int i = 0; i < tam; i++) {
        suma += a[i];  // Sumamos cada elemento del arreglo
    }
    return suma;  // Retornamos la suma total
}
*/

/* Ejercicio 9
struct div_t {
int cociente;
int resto;
};

// Prototipo de la función que realiza la división
struct div_t division(int x, int y);

int main() {
    int x, y;

    // Pedir los dos números al usuario
    printf("Ingrese el dividendo (entero no negativo): ");
    scanf("%d", &x);
    printf("Ingrese el divisor (entero positivo): ");
    scanf("%d", &y);

    // Verificar que el divisor no sea cero
    if (y == 0) {
        printf("Error: El divisor no puede ser cero.\n");
        return 1;  // Salir del programa con código de error
    }

     // Realizar la división
    struct div_t resultado = division(x, y);

    // Imprimir el cociente y el resto
    printf("Cociente: %d\n", resultado.cociente);
    printf("Resto: %d\n", resultado.resto);

    return 0;
}

struct div_t division(int x, int y) {
    struct div_t resultado;
    resultado.cociente = x / y;  // División entera
    resultado.resto = x % y;     // Resto de la división
    return resultado;
}
*/

/*Ejercicio 10
#include <stdbool.h>

#define TAM 5  // Definimos un tamaño constante para el arreglo

// Prototipo de la función que verifica si todos los elementos son pares
bool todos_pares(int tam, int a[]);

// Prototipo de la función que verifica si existe un múltiplo de m en el arreglo
bool existe_multiplo(int m, int tam, int a[]);

// Prototipo de la función para pedir los valores del arreglo
void pedir_arreglo(int tam, int a[]);

int main() {
    int a[TAM];
    int opcion, m;

    // Llenamos el arreglo con valores ingresados por el usuario
    pedir_arreglo(TAM, a);

    // Mostrar opciones para el usuario
    printf("Seleccione la función a ejecutar:\n");
    printf("1. Verificar si todos los elementos son pares\n");
    printf("2. Verificar si existe un múltiplo de un número dado\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        if (todos_pares(TAM, a)) {
            printf("Todos los elementos del arreglo son pares.\n");
        } else {
            printf("No todos los elementos del arreglo son pares.\n");
        }
    } else if (opcion == 2) {
        printf("Ingrese el valor de m: ");
        scanf("%d", &m);
        if (existe_multiplo(m, TAM, a)) {
            printf("Existe al menos un múltiplo de %d en el arreglo.\n", m);
        } else {
            printf("No hay múltiplos de %d en el arreglo.\n", m);
        }
    } else {
        printf("Opción no válida.\n");
    }

    return 0;
}

void pedir_arreglo(int tam, int a[]) {
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el valor para a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

bool todos_pares(int tam, int a[]) {
    for (int i = 0; i < tam; i++) {
        if (a[i] % 2 != 0) {  // Si algún elemento es impar, retorna false
            return false;
        }
    }
    return true;  // Si todos son pares, retorna true
}

bool existe_multiplo(int m, int tam, int a[]) {
    for (int i = 0; i < tam; i++) {
        if (a[i] % m == 0) {  // Si encontramos un múltiplo de m, retorna true
            return true;
        }
    }
    return false;  // Si no hay múltiplos de m, retorna false
} */

//Ejercio 11

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define TAM 5  // Tamaño constante del arreglo

/* Prototipos de las funciones
int minimo_pares(int tam, int a[]);
int minimo_impares(int tam, int a[]);
void pedir_arreglo(int tam, int a[]);
bool existe_par(int tam, int a[]);
bool existe_impar(int tam, int a[]);

int main() {
    int a[TAM];

    // Pedimos al usuario los elementos del arreglo
    pedir_arreglo(TAM, a);

    // Verificamos si hay elementos pares o impares
    bool hay_pares = existe_par(TAM, a);
    bool hay_impares = existe_impar(TAM, a);

    // Calculamos y mostramos el mínimo par si existen pares en el arreglo
    if (hay_pares) {
        int min_par = minimo_pares(TAM, a);
        printf("El mínimo par es: %d\n", min_par);
    } else {
        printf("No hay elementos pares en el arreglo.\n");
    }

    // Calculamos y mostramos el mínimo impar si existen impares en el arreglo
    if (hay_impares) {
        int min_impar = minimo_impares(TAM, a);
        printf("El mínimo impar es: %d\n", min_impar);
    } else {
        printf("No hay elementos impares en el arreglo.\n");
    }

    // Calculamos el mínimo global
    if (hay_pares && hay_impares) {
        int min_total = (minimo_pares(TAM, a) < minimo_impares(TAM, a)) ? minimo_pares(TAM, a) : minimo_impares(TAM, a);
        printf("El elemento mínimo del arreglo es: %d\n", min_total);
    } else if (hay_pares) {
        printf("El elemento mínimo del arreglo es el mínimo par: %d\n", minimo_pares(TAM, a));
    } else if (hay_impares) {
        printf("El elemento mínimo del arreglo es el mínimo impar: %d\n", minimo_impares(TAM, a));
    } else {
        printf("No hay elementos en el arreglo.\n");
    }

    return 0;
}

void pedir_arreglo(int tam, int a[]) {
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el valor para a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

int minimo_pares(int tam, int a[]) {
    int min_par = INT_MAX;
    for (int i = 0; i < tam; i++) {
        if (a[i] % 2 == 0 && a[i] < min_par) {
            min_par = a[i];
        }
    }
    return min_par;
}

int minimo_impares(int tam, int a[]) {
    int min_impar = INT_MAX;
    for (int i = 0; i < tam; i++) {
        if (a[i] % 2 != 0 && a[i] < min_impar) {
            min_impar = a[i];
        }
    }
    return min_impar;
}

bool existe_par(int tam, int a[]) {
    for (int i = 0; i < tam; i++) {
        if (a[i] % 2 == 0) {
            return true;
        }
    }
    return false;
}

bool existe_impar(int tam, int a[]) {
    for (int i = 0; i < tam; i++) {
        if (a[i] % 2 != 0) {
            return true;
        }
    }
    return false;
}*/

/*#include <stdio.h>

typedef struct _persona {
    char *nombre;
    int edad;
    float altura;
    float peso;
} persona_t;

// Función que calcula el peso promedio
float peso_promedio(unsigned int longitud, persona_t arr[]) {
    float suma_peso = 0.0;
    for (unsigned int i = 0; i < longitud; i++) {
        suma_peso += arr[i].peso;
    }
    return suma_peso / longitud;
}

// Función que encuentra la persona de mayor edad
persona_t persona_de_mayor_edad(unsigned int longitud, persona_t arr[]) {
    persona_t mayor = arr[0];
    for (unsigned int i = 1; i < longitud; i++) {
        if (arr[i].edad > mayor.edad) {
            mayor = arr[i];
        }
    }
    return mayor;
}

// Función que encuentra la persona de menor altura
persona_t persona_de_menor_altura(unsigned int longitud, persona_t arr[]) {
    persona_t menor_altura = arr[0];
    for (unsigned int i = 1; i < longitud; i++) {
        if (arr[i].altura < menor_altura.altura) {
            menor_altura = arr[i];
        }
    }
    return menor_altura;
}

int main(void) {
    persona_t p1 = {.nombre="Paola", .edad=21, .altura=1.85, .peso=75};
    persona_t p2 = {.nombre="Luis", .edad=54, .altura=1.75, .peso=69};
    persona_t p3 = {.nombre="Julio", .edad=40, .altura=1.70, .peso=80};

    unsigned int longitud = 3;
    persona_t arr[] = {p1, p2, p3};

    printf("El peso promedio es %.2f\n", peso_promedio(longitud, arr));

    persona_t p = persona_de_mayor_edad(longitud, arr);
    printf("El nombre de la persona con mayor edad es %s\n", p.nombre);

    p = persona_de_menor_altura(longitud, arr);
    printf("El nombre de la persona con menor altura es %s\n", p.nombre);

    return 0;
}*/


