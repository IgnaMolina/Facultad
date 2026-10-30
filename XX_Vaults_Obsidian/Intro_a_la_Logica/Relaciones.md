-  Prelude.
	- Podemos definir el concepto de relación de diversas maneras; En matemática, una relación es el resultado de comparar dos cantidades expresadas en números, dados A,B decimos que R es una relación binaria de **A** y **B** sii **R $\subseteq$ A x B**. En definitiva, para esta materia, una relación es un conjunto matemático muy concreto.
		- Dado R $\subseteq$ A x B escribimos aRb para denotar (a,b) $\in$ R y usamos $a \not Rb$ para denotar (a,b) $\notin$  R.
	- Si **R** es una relación entre **A** y **B** decimos que *x* esta relacionado con *y* si **(x,y) $\in$ R** y lo denotamos como **x ~ y**. Sea **A = B** solemos decir que **R** es una relación sobre **A**. 
	- Existen tres tipos de relaciones; las *funciones*, las **relaciones de orden** y las **relaciones de equivalencia**. En esta materia nos centramos en estas ultimas, que son relaciones sobre un ismo conjunto.
	
- Propiedades de las relaciones:
	- Def 2.1: Sea **R** una relación sobre un conjunto A. Decimos que **R** es:
		- *Reflexiva* sii para todo *a* en **A**, *a ~ a*.
		- *Simétrica* sii para todo *a,b $\in$ A*, *a ~ b* implica que *b ~ a*. 
		- *Antisimétrica* sii para todo *a,b $\in$ A, a ~ b y b ~ a* implica que a = b.
		- *Transitiva* sii para todo *a, b y c, a ~ b y b ~ c* implica que *a ~ c*.
		- O en criollo podemos decir que es **reflexiva** cuando tenes la equivalencia **R =(5,5), (3,3), (-1,-1)**; **Simétrica** si tenes **R =(5,5), (3,3), (-1,-1), (3,-1), (-1,3)**; **transitiva** cuando tenes **R =(5,5), (3,3), (-1,-1), (3,-1), (-1,3), (5,3), (3,5), (-1,5), (5,-1)**.
	
- Relación divide y modulo:
	- Sea **R** la relación sobre N dada por *a ~ b* sii *a* divide a *b*:
		- Es reflexiva: *a = a.1*, luego *a* divide a *a* para todo *a* $\in$ N;
		- No es simétrica, pues: 2 divide a 4 pero 4 no a 2.
		- Es antisimétrica: si *a* divide a *b* entonces *b* = *a.m* para algún *m $\in$ Z, m > 0*. 
		- Es transitiva: mucho texto.
		- En resumen la relación **divide** es **reflexiva, antisimétrica y transitiva**.
	- Considerando ahora *A = Z* y R es la relación dada por *a ~ b* sii *a* y *b* tienen la misma paridad.
		- Notamos que si *a* y *b* son pares o impares, *a-b* siempre va a ser par, si tienen distinta paridad, *a-b* es impar, por lo que **R = {(m,n) : |m-n}**. Es reflexiva, simétrica, no es antisimétrica y es transitiva, por lo cual la relación **modulo 2** es **reflexiva, simétrica y transitiva**.
	
- Relación de equivalencia:
	- Por definición, una relación  $\widetilde{-}$  sobre un conjunto *A* es de *equivalencia* si es reflexiva, simétrica y transitiva. Sobre cualquier conjunto, la relación igual es trivialmente una relación de equivalencia, las relaciones, como vimos antes, de igual paridad lo son, por ende podemos decir que la relación *modulo k* es una relación de equivalencia.
	- Def: sea $\widetilde{-}$ una relación de equivalencia sobre un conjunto A y sea x un elemento de A. La *clase de equivalencia de x se denota por [x] y es el conjunto: [x] = {y | y $\in$ A e y $\widetilde{-}$ x}*. La simetría hace que la propiedad y $\widetilde{-}$ x pueda ser remplazada por x $\widetilde{-}$ y, obteniendo el mismo conjunto.
	- Def: Sea $\widetilde{-}$ una relación de equivalencia en un conjunto A y sea x, y elementos de A, entonces: 
		1. [X]=[Y] sii x $\widetilde{-}$ y.
		2. si no son $\widetilde{-}$ entonces [X] e [Y] son disjuntas. 
	- Def: Una **partición** de un conjunto A es una familia de subconjuntos no vacíos de A que son disjuntos entre sí y cuya unión es todo A, por ejemplo *A = {a, b, c}* podrida ser:
		1. P1: {a}, {b}, {c};
		2. P2: {a}, {b, c};
		3. P3: {a, b, c};
	- Def: sea $\equiv$ una relación de equivalencia sobre un conjunto A no vacío. La familia de clases de equivalencia es una partición de A.
	
- Relaciones de orden:
	- Por definición, una relación de orden parcial **R** sobre un conjunto es una relación que es: reflexiva, antisimétrica y transitiva.
	
- Para mas data loca consultar [[Notas_de_clase]] o a la imagen [[Notas_de_clase.svg]]