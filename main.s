.section .maze, "aw"
.align 3
.global laberinto 
.section .data
    _stack_ptr: .dword _stack_end
    estado: .dword 0x4e45204f4745554a, 0x21214f5352554320

// ------------- Modificar para agregar datos constantes --------------

// --------------------------------------------------------------------

.section .text
.global _start  

_start:
    ldr     x1, =_stack_ptr 
    ldr     x1, [x1]        
    mov     sp, x1
    mov x0, xzr
    mov x4, xzr
    ldr x0, =laberinto    

main:
// ------------- El código principal debe ir aqui abajo ---------------
//Busco la x
    mov x2, #0
    mov x3, #0
    mov x16, 0x6f           //Ponemos en x16 el bonus
 in_x_premio:
    add x3, x3, #1          //En x3 voy sumando desde la dir 00 hasta la ultima
    ldrb w4, [x0,x3]        //Almaceno el dato de x3 en x10
    cmp w4, 0x58            //Comparo para ver si es la 'X'
    b.eq in_1               //Si lo es, salto
    cmp w4, 0x6f            //Comparo para ver si es un bonus
    b.eq in_2               //Si lo es, salto
    cmp w4, 0x4a
    b.eq estado_def
    b in_x_premio
 in_1:
    mov x9,x3
    b in_x_premio
 in_2:
    add x2, x2, #1
    b in_x_premio

 estado_def:
    //Ahora definimos puntos cardinales: Norte (0), Oeste(1), Sur(2) y Este (3)
    mov x8, #0              //Inicializo en Norte
	 mov x19, 0x20 			 //x19 va a ser mi registro de comparacion, este debe ser variable dependiendo de que busco para moverme
 punto_Norte:
    //Miro a la derecha 
    add x11,x9,#1           
    ldrb w12, [x0,x11]      // Almaceno en w12  el contenido de x11
    mov x8, #3              // Si me muevo a la derehca mientras miro Norte, miro al Este
    cmp w12, w19 			    // Comparo que tengo, puede ser un espacio vacio o un asterisco
    b.eq if
    cmp w12, w16            // Comparo que tengo, puede ser la meta o un bonus, empezamos buscando el segundo
    b.eq bonus
    //Miro adelante 'Arriba'
    mov x8, #0
    sub x11,x9,#16
    ldrb w12, [x0,x11]
    cmp w12, w19           
    b.eq if
    cmp w12, w16
    b.eq bonus
    mov x8, #1
    b punto_Oeste

 punto_Oeste:
    //Miro a la derecha 'Arriba'
    sub x11, x9,#16
    ldrb w12, [x0,x11]
    mov x8, #0              // Si me muevo mirando al Oeste, miro al Norte
    cmp w12, w19
    b.eq if
    cmp w12, w16
    b.eq bonus
    //Miro adelante 'Izquierda'
    sub x11, x9, #1
    mov x8, #1
    ldrb w12, [x0,x11]
    cmp w12, w19
    b.eq if
    cmp w12, w16
    b.eq bonus
    mov x8, #2
    b punto_Sur

 punto_Sur:
    //Miro a la derecha 'Izquierda'
    sub x11, x9, #1
    ldrb w12, [x0,x11]
    mov x8, #1              // Si me muevo mirando al Sur, miro al Oeste
    cmp w12, w19
    b.eq if
    cmp w12, w16
    b.eq bonus
    //Miro adelante 'Abajo'
    add x11, x9, #16
    mov x8, #2
    ldrb w12, [x0,x11]
    cmp w12, w19
    b.eq if
    cmp w12, w16
    b.eq bonus
    mov x8, #3
    b punto_Este

 punto_Este:
    //Miro a la derecha 'Abajo'
    add x11, x9, #16
    ldrb w12, [x0,x11]
    mov x8, #2              // Si me movi mirnado al Este, miro al Sur
    cmp w12, w19
    b.eq if
    cmp w12, w16
    b.eq bonus
    //Miro adelante 'Derecha'
    add x11, x9, #1
    mov x8, #3
    ldrb w12, [x0,x11]
    cmp w12, w19
    b.eq if
    cmp w12, w16
    b.eq bonus
	//Para ver si estoy en callejon miro a la izquierda "Norte"
	sub x11,x9,#16
    ldrb w12, [x0,x11]
	cmp w12, w19 
	b.eq punto_Norte
	b callejon
 if:
    mov x15, #42			    //Ponemos en x15 un '*'
     mov w10, 0x58
     strb w10, [x0,x11]     //Movimiento de 'X'
     strb w15, [x0, x9]     //Dejamos nuestra miga en la posicion anterior a 'X'
     add x1, x1,#1          //Contador de pasos
     mov x9,x11             //Actualizo la posicion de x9 con la posicion acutal de 'X'          
     cmp w19, 0x20          //Si w19 es espacio libre voy directo a direccion, caso contrario voy a chequeo_casilla_libre
     b.eq direccion
	  b chequeo_casilla_libre

//Veo en que direccion quede
 direccion:
     cmp x8, 0
     b.eq punto_Norte
     cmp x8, 1
     b.eq punto_Oeste
     cmp x8, 2
     b.eq punto_Sur
     b punto_Este

//Loop que ordena callejon
  callejon:
	mov w19, #42			//Le asigno a x19 (mi variable de comparacion) asterisco
	mov x15, 0xB7			//Ponemos en x15 una '.'
	b punto_Norte
//Voy a ver si alguna casilla adyacente esta libre (unicamente en modo callejon)
  chequeo_casilla_libre:
	add x11, x9, #1
	ldrb w12, [x0,x11]
	cmp w12, 0x20
	b.eq estado_def
	sub x11, x9, #1
	ldrb w12, [x0,x11]
	cmp w12, 0x20
	b.eq estado_def
	add x11, x9, #16
	ldrb w12, [x0,x11]
	cmp w12, 0x20
	b.eq estado_def
	sub x11, x9, #16
	ldrb w12, [x0,x11]
	cmp w12, 0x20
	b.eq estado_def
   b direccion
 bonus:
   cmp w16, 0x23            //Puede verse estupido comparar si es la meta pero w16 se usa para meta y bonus, empiezo buscando bonus, una vez que x2 es cero cambio x16 y busco la meta, cuando la encuentre voy a meta
   b.eq meta
   sub x2, x2, #1           // X2 es mi registro contador de bonus, cada que encuentro uno debo tomarlo y restarle uno a ese contador, va desfasado, primero resta y despues mueve
   cbnz x2, if
   mov x16, 0x23
   b direccion
 meta:

// --------------------------------------------------------------------
    
infloop: b infloop
