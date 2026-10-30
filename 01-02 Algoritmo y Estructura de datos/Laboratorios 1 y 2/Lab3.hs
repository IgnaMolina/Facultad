esCero :: Int -> Bool
esCero 0 = True
esCero _ = False

esCero2 :: Int -> Bool
esCero2 n | n==0 = True
          | n/=0 = False

esCero3 :: Int -> Bool
esCero3 0 = True
esCero3 n = False

esPositivo :: Int -> Bool
esPositivo x = x > 0

esVocal :: Char -> Bool
esVocal 'a' = True
esVocal 'e' = True
esVocal 'i' = True
esVocal 'o' = True
esVocal 'u' = True
esVocal n = False

valorAbsoluto :: Int -> Int
valorAbsoluto n | n>=0 = n               
                | n<0 = -n
                 
productoria :: [Int] -> Int
productoria [] = 1
productoria (n:ns) = n * productoria ns

 
 
todoIguales :: [Int] -> Bool
todoIguales [] = True
todoIguales (x:[]) = True
todoIguales (x:(y:ys)) = x==y && todoIguales (y:ys)

--4)
maximo :: [Int] -> Int
maximo [] = error "La lista está vacía."
maximo xs = maximum xs

minimo :: [Int] -> Int
minimo [] = error "La lista está vacía."
minimo xs = minimum xs

compara :: [Int] -> [Int] -> Bool
compara (x:xs) (y:ys)  | maximo xs >= minimo ys = False
                       | maximo xs < minimo ys = True
                       
-- xs = [−3, 9, 8], ys = [6, 7, 8]. =False

--5)

todos :: [Bool] -> Bool
todos [] = True
todos(x:xs) = x == todos xs && x == True


porDos :: [Int] -> [Int]
porDos [] = []
porDos (x:xs) = x*2 : porDos xs

map1 :: (a -> b) -> [a] -> [b]
map1 f [] = []
map1 f (x:xs) = f x : map1 f xs



sonmenoresa3 :: [Int] -> [Bool]
sonmenoresa3 [] = []
sonmenoresa3 (x:xs) = (x<3) : sonmenoresa3 xs

filter1 :: (a -> Bool) -> [a] -> [a]
filter1 f [] = []
filter1 f (x:xs) | f x = x : filter1 f xs
                 | otherwise = filter1 f xs

--6) a) n es el elemento mas grande de la lista xs



--masGrande :: Int -> [Int] -> Bool
--masGrande n [] = False
--masGrande n (x:xs) = n > x 
--where pertenece :: Int -> [Int] -> Bool
      --pertenece n [] = False
      --pertenece n (x:xs) | n == x = True
                   --        | otherwise : pertenece xs
                           
  
--7) a) paratodo’ :: [a] -> (a -> Bool) -> Bool
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] f = True
paratodo' (x:xs) f = f x && paratodo' xs f 

-- existe :: [a] -> (a -> 

-- hayMultiplo :: Int -> [Int] -> Bool

existe' :: [a] -> (a -> Bool) -> Bool
existe' [] f = False
existe' (x:xs) f = f x || existe' xs f

--9b

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n (x:xs) = existe' xs esMultiplo
  where esMultiplo x = x `mod` n == 0
  
  -- SEGUNDO PRACTICO --
  
  --1)
  
  --2)
data Dia = Lunes | Martes | Miercoles |Jueves | Viernes | Sabado | Domingo deriving (Eq, Show)
  
queHagodia :: Dia -> String
queHagodia Domingo = "Descanso"
queHagodia Sabado = "Descanso"
queHagodia _ = "Trabajo"
  
  --5c 
 
type Altura = Int
type NumCamiseta = Int

data Zona = Arco | Defensa | Mediocampo | Delantera
data TipoReves = DosManos | UnaMano
data Modalidad = Carretera | Pista | Monte | BMX
data PiernaHabil = Izquierda | Derecha

type ManoHabil = PiernaHabil

data Deportista = Ajedrecista
                |Ciclista Modalidad
                |Velocista Altura
                |Tenista TipoReves ManoHabil Altura 
                |Futbolista Zona NumCamiseta PiernaHabil Altura 

  --c
contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas ((Velocista a):xs) = 1 + contar_velocistas xs
contar_velocistas (_:xs) = contar_velocistas xs






