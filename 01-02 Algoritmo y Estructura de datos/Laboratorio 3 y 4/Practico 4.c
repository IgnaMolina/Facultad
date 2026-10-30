#include <stdio.h>
#include <stdbool.h>
/*Ejercicio 1
int main (void){
int z, x, y;
printf("porfi da un valor para z,x,y \n");
scanf("%d %d %d", &z, &x, &y);

int arr [3]= {z,x,y};
z = arr[1];
x = arr[2];
y = arr[0];
printf("los nuevos valores son: %d %d %d \n",z,x,y);
    return 0;
}*/
/*Ejercicio 2
int main(void){
int x,y;
printf("asigne un valor para x,y \n");   
scanf("%d %d",&x,&y);
int temp1, temp2;
temp1 = x+1;
temp2 = x+y;
x = temp1;
y = temp2;
printf("los nuevos valroes son: %d, %d\n",x,y); 
}*/
//Ejercicio 3

//Ejercicio 5

/*int suma_hasta(int n){

int suma, i;

suma = 0;
i = 1;

while (i<=n)
{
suma = suma+i;
i = i+1;
}
return suma;
}


int main (){
int n = 0;
int suma = 0;
printf("asigna un valor n: \n");
scanf ("%d",&n);
suma = suma_hasta(n);
return 0;
}*/

//Ejercicio 6

void intercambiar(int tam, int a[], int i, int j){

int tam;
int lista [tam];
int posicioni;
int posicionj;
int posicionii;
int posicionjj;


int posicioni = lista [posicioni];
int posicionj = lista [posicionj];

lista [posicionii] = posicioni;
lista [posicionjj] = posicionj;
return lista; 
}
int main (){

int tam;
int posicioni;
int posicionj;
int posicionii;
int posicionjj;

  printf("Ingrese el tamaño de la lista: ");
    scanf("%d", &tam);

    int lista[tam]; // Declarar el arreglo con el tamaño dado

    printf("Ingrese los elementos de la lista:\n");
    for (int i = 0; i < tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &lista[i])


}

