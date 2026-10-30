.section .maze, "aw"
.align 3
.global laberinto 
.section .data
   // _stack_ptr: .dword _stack_end
    estado: .dword 0x4e45204f4745554a, 0x21214f5352554320
    _stack_ptr: .dword _stack_end   // Get the stack pointer value from memmap definitio
    //_stack_ptr: .dword _stack_end

// ------------- Modificar para agregar datos constantes --------------

// --------------------------------------------------------------------

.section .text
        ldr     x1, _stack_ptr  // Load stack pointer to X1
        mov     sp, x1          // Move stack pointer to the sp register
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
//Iniciamos valores
    ldr x11, =laberinto
    add x11, x11, #0x2000
    mov sp, x11

    add x1, xzr, xzr 
    mov x5, #0
    mov x2, #0
loop:
    ldrb w10, [x0,x5]      // traemos el valor de x5 a w10 dentro del laberinto x0
    cmp w10, 0x58          // comparamos w10 = 0x58 (vemos si es igual a 'X')
    b.eq nuestrax
    cmp w10, 0x6f          // comparamos para ver si es un bonus
    b.eq bonus
    cmp w10, 0x40          // comparamos para ver si es un portal
    b.eq portal
    cmp w10, 0x4a          // comparo para ver si es la j, mi final del mapa
    b.eq estado1
    
    add x5, x5, #1         // Sumamos al final para avanzar en la próxima vuelta
    b loop

// guardo la posicion de 'x'
nuestrax: mov x9, x5
    add x5, x5, #1         // Avanzamos al siguiente tras guardar para evitar bucle
    b loop
// sumamos 1 al contador de bonus x2
bonus:add x2, x2,#1
    add x5, x5, #1         // Avanzamos al siguiente para evitar bucle
    b loop
// almacenamos la direccion del portal
portal:cbnz x3, portal2
    mov x3, x5
    add x5, x5, #1         // Avanzamos al siguiente
    b loop
portal2:mov x4,x5
    add x5, x5, #1         // Avanzamos al siguiente
    b loop

estado1:
    mov x14, #2             // inicializo el estado de x14 en 2 (Modo Bonus)
    mov x12, 0x58           // Mantenemos la 'X' en x12
    mov x6, #0              // Limpiamos la espalda

sensor:
    //Si todavía quedan bonus (x2 != 0), ignoramos olímpicamente la meta
    cbnz x2, evaluar_modos  
    
    // Si entramos acá es porque x2 == 0. Ahora sí buscamos la meta '#'
    mov w13, 0x23           
    b busqueda_meta

evaluar_modos:
    cmp x14, #2
    b.eq modo_bonus
    cmp x14, #1
    b.eq modo_espacio
    b retroceder_pila       

modo_bonus:
    mov w13, 0x6f           // Buscamos bonus ('o')
    b busqueda_lados

modo_espacio:
    mov w13, 0x20           // Buscamos espacio vacío (' ')
    b busqueda_lados

busqueda_meta:
    // Revisamos los 4 lados rápido buscando la meta '#'
    add x11, x9, #1
    ldrb w10, [x0, x11]
    cmp w10, w13
    b.eq ganar_juego        
    
    sub x11, x9, #1
    ldrb w10, [x0, x11]
    cmp w10, w13
    b.eq ganar_juego
    
    add x11, x9, #16
    ldrb w10, [x0, x11]
    cmp w10, w13
    b.eq ganar_juego
    
    sub x11, x9, #16
    ldrb w10, [x0, x11]
    cmp w10, w13
    b.eq ganar_juego

    // Si la meta no está al lado, saltamos a evaluar los movimientos normales
    b evaluar_modos

busqueda_lados:
    // 1. Derecha
    add x11, x9, #1
    cmp x11, x6
    b.eq izquierda
    ldrb w10, [x0, x11]
    cmp w10, w13
    b.eq if                 
izquierda:
    // 2. Izquierda
    sub x11, x9, #1
    cmp x11, x6
    b.eq abajo
    ldrb w10, [x0, x11]
    cmp w10, w13
    b.eq if
abajo:
    // 3. Abajo
    add x11, x9, #16
    cmp x11, x6
    b.eq arriba
    ldrb w10, [x0, x11]
    cmp w10, w13
    b.eq if
arriba:
    // 4. Arriba
    sub x11, x9, #16
    cmp x11, x6
    b.eq fin_arriba         
    ldrb w10, [x0, x11]
    cmp w10, w13
    b.eq if

fin_arriba:
    // Si ya buscó espacios vacíos (0x20) por los 4 lados y no encontró:
    cmp w13, 0x20
    b.ne seguir_decremento  
    
    // Si x2 == 0 (no quedan bonus), activamos el MODO ESCAPE sobre los puntos '.'
    cbz x2, modo_escape     
    b seguir_decremento

modo_escape:
    mov w13, 0x2e           // Cambiamos el objetivo a puntos
    b busqueda_lados        // Volvemos a revisar los 4 lados con este nuevo objetivo

seguir_decremento:
    sub x14, x14, #1        // Decrementamos el controlador (De Bonus a Espacio, o a Callejón)
    b sensor                // Volvemos arriba

// Movimiento General
if:
    mov x6, #0              // limpio la espalda x6
    sub sp, sp, #16         // reservamos 16 bytes en la pila real
    str x9, [sp, #0]        // guardamos nuestra posición actual en la stack
    mov w15, 0x2a           // ponemos en w15 un asterisco '*'
    strb w15, [x0, x9]      // lo escribo en la posición vieja en el mapa
    
    ldrb w10, [x0, x11]     // Evaluamos qué hay en el destino antes de pisarlo
    cmp w10, 0x6f           // ¿Es un bonus?
    b.eq bonus1      

    // Movimiento Normal (Espacio vacío o Punto del modo escape)
    mov x9, x11             // actualizo x9 con la posición de destino x11
    strb w12, [x0, x9]      // escribo en el mapa la 'X' (w12)
    add x1, x1, #1          // sumamos un paso al contador general
    mov x14, #2             // Reseteamos el sensor a buscar bonus en la nueva casilla
    b sensor

retroceder_pila:
    mov x6, x9              // salvamos el valor de x9 en x6 para usarlo como "espalda"
    mov w15, 0x2e           // Clausuramos este callejón muerto con un punto '.'
    strb w15, [x0,x9]       // lo escribimos en el mapa
    
    ldr x9, [sp, #0]        // POP: recuperamos la posición anterior de la pila real
    add sp, sp, #16         // devolvemos los 16 bytes al puntero sp
    
    strb w12, [x0, x9]      // redibujamos la 'X' en la posición recuperada
    mov x14, #2             // actualizo x14 a 2 para volver a evaluar el entorno
    b sensor

bonus1:
    sub x2, x2, #1          // Restamos uno al contador de bonus recogidos
    mov x9, x11             // actualizo x9 con la posición del bonus recogido
    strb w12, [x0, x9]      // escribo la 'X' pisando el bonus en el mapa
    add x1, x1, #1          // sumamos el paso
    mov x14, #2             // Reseteamos el sensor a modo bonus
    b sensor

ganar_juego:
    mov x9, x11             // Damos el paso final hacia la meta
    strb w12, [x0, x9]      // Dibujamos la X arriba de la meta #
    add x1, x1, #1          // Sumamos el último paso

end: b end

// --------------------------------------------------------------------
    
infloop: b infloop
