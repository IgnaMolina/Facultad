esCero :: Int -> Bool
esCero n | n==0 = True
         | n/=0 = False

esPositivo :: Int -> Bool 
esPositivo n | n>0 = True
             | n<=0 = False

esVocal :: Char -> Bool
esVocal 'a' = True
esVocal 'e' = True
esVocal 'i' = True
esVocal 'o' = True
esVocal 'u' = True
esVocal c = False

valorAbsoluto :: Int -> Int
valorAbsoluto n | n>=0 = n
                | n<0 = n*(-1)

productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs 

paraTodo :: [Bool] -> Bool
paraTodo [] = True
paraTodo (x:xs) | x==True = paraTodo xs
                | x==False = False

sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs



esmul :: Int -> Int -> Bool
esmul x y = mod y x == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo x ys = existe ys (esmul x)

{- Programar la funci ́on existeDivisor::Int-> [Int] -> Bool, que dado en entero n y una lista ls ,
devuelve True si y solo si, existe alg ́un elemento en ls que divida a na. -}


divide :: Int -> Int -> Bool
divide x y = mod x y == 0

existeDivisor :: Int-> [Int] -> Bool
existeDivisor n ls = existe ls (divide n)

{-Utilizando la funcion del apartado anterior, definı la funcion esPrimo:: Int -> Bool, que dado un entero
n, devuelve True si y solo si n es primo. Ayuda: En Haskell se puede escribir la lista que contiene el rango de
n ́umeros entre n y m como [n..m].
-}

esPrimo:: Int -> Bool
esPrimo n = existeDivisor n [2..n-1] == False

esprimo:: Int -> Int
esprimo n | existeDivisor n [2..n-1]  = 1
          | otherwise = n

{-factorial :: Int -> Int, que toma un n ́umero n y calcula n!.-}

factor :: Int -> Int
factor x = productoria [1..x] id

{-Programar la funci ́on multiplicaPrimos :: [Int] -> Int que calcula el producto de todos los n ́umeros
primos de una lista.-}

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos (x:xs) = productoria (x:xs) esprimo

{-Programar la funci ́on esFib :: Int -> Bool, que dado un entero n, devuelve True si y s ́olo si n est ́a en la
sucesi ́on de Fibonacci. Ayuda: Realizar una funci ́on auxiliar fib :: Int -> Int que dado un n devuelva el
n- ́esimo elemento de la sucesi ́on.-}

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = fib (x - 1) + fib (x - 2)

esFib :: Int -> Bool
esFib n = existe [0..n+1] (\x -> fib x == n)

{-Utilizando la funci ́on del apartado anterior, defin ́ı la funci ́on todosFib :: [Int] -> Bool que dada una
lista xs de enteros, devuelva si todos los elementos de la lista pertenecen (o no) a la sucesi ́on de Fibonacci.-}

todosFib :: [Int] -> Bool
todosFib xs = paratodo xs esFib
