#include <stdio.h>
#include <stdlib.h>

typedef struct s_pair_t pair_t;

struct s_pair_t {
  int fst;
  int snd;
};

pair_t pair_new(int x, int y){
  pair_t p;
  
  p = malloc(sizeof(pair_t));
  p -> fst = malloc(sizeof(fst));
  p -> fst = x;
  p -> snd = malloc(sizeof(snd));
  p -> snd = y;
}

int pair_first (pair_t p){
  printf("el primero es %d",par -> fst);

}

int pair_second(pair_t p);{
  printf("El segundo es: %d", par-> snd);
}

pair_t pair_swapped(pair_t p){
 int temp = 0;
 temp = p -> snd;
 p -> snd = p-> fst;
 p -> fst = temp;
}

void pair_destroy(pair_t p){
  free(p->x);
  free(p->y);
  free(p);
}

