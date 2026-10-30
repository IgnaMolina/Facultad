#include <stdio.h>
//int main() {
 //   printf("Hola Juli 3 motivos de porque sos tan gay!\n");
   // printf("motivo 1: Sos negro? \n");
 //   printf("motivo 2: te gusta el poto de moly \n");
   // printf("motivo 3:te comiste tremendo trava \n");

   // return 0;
//}

// Laboratorio 1
/* 
int main(void) {
    int x, y, z;
    int resultado = (x * 3 + 1) / 5;
    int holi;

    printf("Ingrese un valor para x, y, z: \n");
    
    scanf("%d %d %d", &x, &y, &z);
 
    printf("x + y + z = %d \n", x + y + z );
    printf("z*z + y*45 - 15*x =  %d \n", z*z + y*45 - 15*x);1 
    printf("y-2 == (x*3+1)/5 e= %d \n", (y - 2 == resultado));
    printf ("y/(2*x) = %d \n", y/(x*2))
    holi = x * z;
    printf("holi = %d \n", holi);

    Condición y < z * x
    if (y < z * x) {
        printf("y es menor que z * x\n");
    } else {
        printf("y no es menor que z * x\n");
    }

    return 0;
}
*/

/*Laboratorio 2
int main(void) { 
  
  int x, y, z, b, w;
 
/* printf ("Asigne un valor a x \n");
  scanf ("%d", &x);

  if (x/4 == 0) {
       printf ("True \n");
   } else{
      printf ("False \n");
   }

   printf("asigne un valor a x, y, z\n");
   scanf("%d %d %d", &x, &y, &z);
   
   if (x + y == 0 && y - x == (-1)* x) {

     printf ("True \n");
 } 
 else{
    printf ("False \n");
   }



 return  0;
}
*/

/*Laboratorio 3

int main (void){

  int x;
  x = 5;

  printf("asigne un valor a x \n");
  scanf("%d", &x);
  printf("el valor de x es: %d \n", x);

  return 0;
}
*/

/*ejercicio b

int main (void){
   
   int x,y;
   printf("asigne un valor a x, y %d \n");
   scanf("%d %d", &x, &y);
   x = x+y;
   y = y+y;
   printf("los valores son %d %d \n", x, y);

  return 0;
}
*/

/*Laboratorio 4
int main (void){
   int x,y;
   printf("asigne un valor a y, x %d \n");
   scanf("%d %d", &y, &x);
   y = y+y ;
   x = x+y;
   printf("los valores son %d %d \n", y, x);
  return 0;
}
*/ 
/* Laboratorio 6
int main (void){
  
  int x,y,z,m;

  printf("asigne un valor a x, y, z, m %d \n");
  scanf("%d %d %d %d", &x, &y, &z, &m);
  if (x<y){ 
   m = x;
   // printf("entocnes x, y, z, m es = %d %d %d %d, \n", x, y, z, m);
  }else {
  m = y;
   // printf("entocnes x, y, z, m es = %d %d %d %d, \n", x, y, z, m);
  }

  if (m>=z)
  {
    m = z;
  }
  printf("entonces es %d %d %d %d \n", x, y, z, m);
  
  return 0;
}
*/

/*Ejemplo de repeticion


int main() {
    int N, count = 0;
    
    // Pedir al usuario que ingrese un número entero positivo
    printf("Introduce un número entero positivo N: ");
    scanf("%d", &N);
    
    // Asegurarse de que N > 0
    if (N <= 0) {
        printf("El número debe ser mayor que 0.\n");
        return 1; // Salida con código de error
    }
    
    // Bucle para contar los múltiplos de 6 entre 0 y N
    for (int i = 0; i <= N; i++) {
        if (i % 6 == 0) {
            count++;
        }
    }
    
    // Mostrar el resultado
    printf("Hay %d números entre 0 y %d que son múltiplos de 6.\n", count, N);
    
    return 0;
}
*/
//Lab 7
/* Ejercicio a
int main (void){
  
  int x;

  printf("Por favor asigne un valor distinto a 0 para x \n");
  scanf("%d", &x);

//Aseugrar que x es distinto a 0
  if (x == 0)
  {
    printf("te dije que sea distinto a 0 mamerto \n");
    return 1;
  }
  
 printf("estado inciial; x = %d \n", x);

 while (x != 0)
 {
   printf("antes de decrementar, x = %d \n", x);

   x = x-1;

   printf("despues de decrmenetar, x = %d \n", x);
 }
 
  printf("estado final de x = %d \n",x);
  

  return 0;
}
*/



/*int main (void){
   int x;
  printf("Por favor asigne un valor distinto a 0 para x \n");
  scanf("%d", &x);

//Aseugrar que x es distinto a 0
  if (x == 0)
  {
    printf("te dije que sea distinto a 0 mamerto \n");
    return 1;
  }
  printf("el valor de x = %d \n", x);
  while (x != 0)
  {
    x = 0;
  }
  printf("el valor final de x = %d \n", x);

  return 0; 
}*/

//Ejercicio e pq el resto son una verga

/*int main (void){
  int x;
  printf("Por favor asigne un valor distinto a 0 para x \n");
  scanf("%d", &x);

  if (x<0)
  {
    printf("el valor inicial de x es %d \n ",x);
    while (x<0)
    {
      x = x+1;
      printf("el valor sumado de x es %d \n ",x);
    }
    
  }else{
    printf("el valor inicial de x es %d \n ",x);
    while (x>0)
    {
     
     x = x-1;
    printf("el valor restado de x es %d \n ",x);
    }
    
  }
  

  return 0;
}*/

//Lab 8 - Ejercicio a
/*int main (void){
  int x, y, i;
  printf("Por favor asigne el valor a x,y,i \n");
  scanf ("%d %d %d", &x, &y, &i);

if (i == 0)
{
  while (x>= y)
  {
    x = x-y;
    i = i+1;
    y = y;
    printf("los nuevos valores de x,y e i son %d,%d,%d\n ",x,y,i);
  }
  printf("los valores finales de x, y e i son %d,%d;%d\n ",x,y,i);
}else{
  printf("no se pa andate a la v\n ");
}


  return 0;
}*/
//Ejercicio b

/*int main() {
    int x = 5;      // Inicialización de x
    int i = 0;      // Inicialización de i
    int res = 0;    // Inicialización de res (False)

    // Actualizamos las variables según el pseudocódigo
    i = 2;
    res = 1;        // res = True

    // Imprimir el estado inicial
    printf("Estado inicial: x = %d, i = %d, res = %d\n", x, i, res);

    // Bucle while que se ejecuta mientras i < x y res sea verdadero
    while (i < x && res) {
        // Estado antes de las operaciones dentro del ciclo
        printf("Antes de la operación: i = %d, res = %d\n", i, res);

        // Actualización de res usando XOR y la condición del módulo
        res = res ^ (x % i != 0);

        // Incrementar i
        i++;

        // Estado después de las operaciones dentro del ciclo
        printf("Después de la operación: i = %d, res = %d\n", i, res);
    }

    // Estado final
    printf("Estado final: x = %d, i = %d, res = %d\n", x, i, res);

    return 0;
}*/
//Ejercicio 9 8-a
/*
int main (void){
  int arr[4] = {2,10,10,-1,7};
  int i,s; 
  printf("Por favor asigne un valor para s e i \n");
  scanf("%d %d", &i,&s);
  i,s= 0,0;

   while (i<=4)
   {
    printf("el valor antes de la transforamcion de s e i son %d %d \n",s,i);
    i =i+1;
    s= s + arr[i];
    printf("el valor pos transformacion de s e i es = %d , %d \n",s,i);
   }
   printf("El valor final de s e i son %d %d \n",s,i);

  return 0;
}*/
int main(void){
 int i,c;
 int arr[4]={12,-9,10,-1};
  printf("Por favor asigne un valor para c e i \n");
  scanf("%d %d", &i,&c);
 i,c = 0,0;

 while (i<4)
 {
  printf("el valor antes de la transforamcion de c e i son %d %d \n",c,i);
  if (arr[1]>0)
  {
    c =c+1;
    printf("el valor pos transformacion de c e i es = %d , %d \n",c,i);
  }else{
    return 1;
  }
 }
  return 0; 
}