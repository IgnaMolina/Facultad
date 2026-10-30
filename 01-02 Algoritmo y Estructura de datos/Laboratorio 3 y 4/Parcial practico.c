#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/* Ejercicio 1

int main() {
    // Definición de variables iniciales
    int X, Y, Z;

    // Pedir al usuario los valores
    printf("Ingrese los valores para X, Y y Z (con Y > 0):\n");
    scanf("%d %d %d", &X, &Y, &Z);

    // Verificar la precondición Y > 0
    assert(Y > 0);

    // Asignar los valores iniciales a las variables de trabajo
    int x = X;
    int y = Y;
    int z = Z;
    // Verificar la precondición inicial: x = X, y = Y, z = Z
    assert(x == X && y == Y && z == Z);

    // Crear variables temporales para los valores de x, y, z
    int temx = x;
    int temy = y;
    int temz = z;

    // Asignaciones según la asignación múltiple dada en el ejercicio
    x = y;
    y = temx + temy - z;
    z = temx * (1 + temy * temy);

    // Verificar la postcondición: x = Y, y = X + Y - Z, z = X * (1 + Y^2)
    assert(x == Y && y == X + Y - Z && z == X * (1 + Y * Y));

    // Imprimir los valores finales
    printf("Los valores finales de x, y, z son: %d, %d, %d\n", x, y, z);

    return 0;
}*/

/* Ejercicio 2

char vocales[] = {'a', 'e', 'i', 'o', 'u'};
void llena_con_char(char a[], int tam) {
    // Iterar sobre cada posición del arreglo para llenarlo con caracteres
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el caracter para la posición %d: ", i);
        scanf(" %c", &a[i]);  
    }
}

bool hay_mas_de_2_consonantes(char a[], int tam){
int contador_consonantes = 0;

for (int i = 0; i < tam; i++)
{
     if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) 
     {
     if (!(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' ||   a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')) {   
     contador_consonantes++;
     }
    
}

}
}

int main(){
    //Def de vairiable a
    int tam = 5;
    char a[tam];

    llena_con_char(a, tam);

    printf("Arreglo lleno: ");
    for (int i = 0; i < tam; i++)
    {
        printf("'%c'",a[i]);

    }
    printf("\n");
    
   if (hay_mas_de_2_consonantes(a, tam))
   {
    printf("hay mas de dos consonantes. \n");

   }else{
    printf("no hay mas de dos consonantes. \n");
   }
    

    
return 0;
}*/


//Parcial 2

/*Ejercicio 1


int main() {
    // Definición de variables x, y, z y variables temporales para las precondiciones
    int x, y, z;
    
    // Pedir al usuario los valores iniciales de x, y y z
    printf("Ingrese valores positivos para x, y y z:\n");
    scanf("%d %d %d", &x, &y, &z);

    // Guardar los valores iniciales para las postcondiciones
    int X = x;
    int Y = y;
    int Z = z;

    // Verificar las precondiciones: x, y, z deben ser mayores que 0
    assert(X > 0 && Y > 0 && Z > 0);

    // Asignación múltiple utilizando variables temporales
    int temp_x = y + z;
    int temp_y = z * x;
    int temp_z = x / y;

    // Asignar los nuevos valores a x, y y z
    x = temp_x;
    y = temp_y;
    z = temp_z;

    // Verificar las postcondiciones
    assert(x == Y + Z);
    assert(y == Z * X);
    assert(z == X / Y);

    // Imprimir los valores finales
    printf("Los valores finales son: x = %d, y = %d, z = %d\n", x, y, z);

    return 0;
}*/

/*Ejercicio 2
void llenar_con_temperaturas(float a[], int tam){
  //Pedido de los valores del arreglo
  for (int i = 0; i < tam; i++)
  {
    printf("Por favor asigne la temperatura deseada del arreglo en la posicion %d: \n", i);
    scanf("%f",&a[i]);
  }
  
}

bool hay_mas_de_2_altas(float a[], int tam){
  //Definicion de variable
  int contador = 0;

  for (int i = 0; i < tam; i++)
  {
    if (a[i]>=0)
    {
        contador ++;
    }   
  }

}
int main(){
  //Declaracion de variables
  int tam = 5;
  float a[tam];
  int contador;

  //Llamamos a la variable  
  llenar_con_temperaturas(a, tam);

  //Impresion del arreglo
  printf("Arreglo lleno: ");
  for (int i = 0; i < tam; i++)
  {
     printf("'%f'",a[i]);
  }
    printf("\n");
  //Llamamos la segunda variable
  if(hay_mas_de_2_altas(a, tam) && contador >= 2){
    printf("True \n");
  }else
  {
    printf("False \n");
  }
  
  return 0;
}*/

//Ejercicio 3

/*Definir la estructura
typedef struct {
int cuantas_bajas;
int cuantas_medias;
int cuantas_altas;
} s_temperaturas;

void LLenar_temperaturas(float a[], int tam){
//Pedido de los valores del arreglo
  for (int i = 0; i < tam; i++)
  {
    printf("Por favor asigne la temperatura deseada del arreglo en la posicion %d: \n", i);
    scanf("%f",&a[i]);
  }
}
s_temperaturas totales(float a[], int tam){
   s_temperaturas conteos = {0,0,0};
   for (int i = 0; i < tam; i++)
   {
    if (a[i]< 15)
    {
      conteos.cuantas_bajas ++; 
    }else if (a[i]>=15 && a[i] <= 30)
    {
      conteos.cuantas_medias ++;
    }else if (a[i]> 30)
    {
      conteos.cuantas_altas ++;
    }   
   }
 return conteos;
}
int main (){
int tam = 4;
float a[tam];


LLenar_temperaturas(a, tam);

s_temperaturas resultados = totales(a, tam);

printf("Temperatura baja: %d \n", resultados.cuantas_bajas);
printf("Temperatura media: %d \n", resultados.cuantas_medias);
printf("Temperatura alta: %d \n", resultados.cuantas_altas);
}
*/

/*Ejercicio 1
int main(){
  //definicion de variables
  int i,j,k;
  //preguntar al suuario los valroes
  printf("Por favor asigna el valor para las variables i,k,k: \n");
  scanf("%d %d %d", &i, &j, &k);
  //Verificamos la pre
  assert(i > 0 && j > 0 && k > 0);

  int I = i;
  int J = j;
  int K = k;
  assert(i ==I && j == J && k == K);

  // creamos variables temproales
  int tempi = I * J;
  int tempj = J * k;
  int tempk = K * I;
  //Hacemos el cmabio de valores
  i = tempi;
  j = tempj;
  k = tempk;

  //Verificamos el post
  assert(i == I * J);
  assert(j == J * k);
  assert(k == K * I);|
  //imprimimos los resultados
  printf("los nuevos valores de i,j,k son : %d %d %d\n",i,j,k);
  return 0;
}*/

/*Ejercicio 2-a

void llena_con_notas(int a[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Ingrese la nota para la posición %d: ", i);
        scanf("%d", &a[i]);
    }
}

//Parte b

bool hay_mas_de_3_aprobados(int a[], int tam){

  int contador = 0;
  for (int i = 0; i < tam; i++)
  {
    if (a[i]>= 6 && a[i]<= 10)
    {
      contador ++;
    }
    
  }
  return contador > 3;
}

int main(){
  int tam = 5;
  int a[tam];
  //Llamamos a las variables
  llena_con_notas(a, tam);

  if (hay_mas_de_3_aprobados)
  {
    printf("True\n");
  }else{
      printf ("false \n");
    }
    
  
  printf("\n");
  


  return 0;
}*/

/*|Ejercicio 3

typedef struct {
int cuantos_aprobados;
int cuantos_promocionados;
bool hay_promocionados;
} s_resultado;

void llena_con_notas(int a[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Ingrese la nota para la posición %d: ", i);
        scanf("%d", &a[i]);
    }
}


s_resultado resultados(int a[], int tam) {
    s_resultado contador = {0, 0, false};
    
    for (int i = 0; i < tam; i++) {
        // Contar los aprobados
        if (a[i] >= 6 && a[i] <= 10) {
            contador.cuantos_aprobados++;
        }
        // Contar los promocionados y marcar si hay al menos uno
        if (a[i] >= 8 && a[i] <= 10) {
            contador.cuantos_promocionados++;
            contador.hay_promocionados = true;
        }
    }
    return contador;
}

int main(){
  int tam = 4;
  int a[tam];

  llena_con_notas(a, tam);

  s_resultado total = resultados(a, tam);
  printf("Hay %d aprobados \n", total.cuantos_aprobados);
  printf("Hay %d promocionados \n", total.cuantos_promocionados);
  printf("Hay %s promocionados \n", total.hay_promocionados ? "True" : "False");



  return 0;
}*/

//Ejercicio 2


//Ejercicio 1

/*int main (){
  //Declaracion de variables
  int x, y, z;
  //Le pedimos al usuario las variables
  printf("Por favor asigna los valores para x,y,z: \n");
  scanf("%d %d %d",&x, &y, &z);
  //Comprobamos 
  assert(x > 0 && z > 0);

  int X = x;
  int Y = y;
  int Z = z;

  //Verificamos la pre
  assert(x == X && y == Y && z == Z);

  //creamos variables temproales
  int tempx = Y + Z;
  int tempy = X + Z;
  int tempz = X + Y;

  int tx = Y;
  int ty = Z;
  int tz = X;
  //Hacemos el cambio de valroes

  if (X >= Z )
  {
    x = tempx;
    y = tempy;
    z = tempz;

  //verificamos la post
  assert(x == Y + Z);
  assert(y == X + Z);
  assert(z == X + Y);
  }else if (X < Z)
  {
    x = tx;
    y = ty;
    z = tz;

  //verificamos la post
  assert(x == Y);
  assert(y == Z);
  assert(z == X);
  }
  //imprimimos el resutlado
  printf("Los nuevos valores son %d, %d, %d \n",x, y, z);
  return 0;
}*/

//Ejercicio 2

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// Definición de la estructura datos
struct datos {
    bool es_divisible_por_2;
    int menor_divisible_por_2;
};

// Implementación de la función hay_divisible
struct datos hay_divisible(int tam, int a[]) {
    // Verificar que el tamaño del arreglo sea al menos 2
    assert(tam >= 2);

    struct datos resultado;
    resultado.es_divisible_por_2 = false;       // Inicialmente asumimos que no hay divisibles por 2
    resultado.menor_divisible_por_2 = INT_MAX;  // Asumimos que no hay ningún divisible por 2

    // Recorrer el arreglo una vez
    for (int i = 0; i < tam; i++) {
        if (a[i] % 2 == 0) { // Comprobamos si el número es divisible por 2
            resultado.es_divisible_por_2 = true;  // Actualizamos a true si encontramos un divisible por 2
            if (a[i] < resultado.menor_divisible_por_2) {
                resultado.menor_divisible_por_2 = a[i]; // Actualizamos el menor número divisible por 2
            }
        }
    }

    return resultado;
}

int main() {
    int tam = 5;
    int a[] = {3, 5, 8, 6, 7};

    // Llamamos a la función hay_divisible y obtenemos el resultado
    struct datos resultado = hay_divisible(tam, a);

    // Mostramos los resultados
    printf("Hay divisible por 2: %s\n", resultado.es_divisible_por_2 ? "True" : "False");
    printf("Menor divisible por 2: %d\n", resultado.menor_divisible_por_2);

    return 0;
}
