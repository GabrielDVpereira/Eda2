#include <stdio.h>
#include "helpers.h"


int separa (int *v, int l, int r){ 
  int i = l-1, j=r, c=*(v+r); 
  for(;;){
    while(less(*(v + ++i), c));
    while(less(c, *(v + --j))) if(j==l) break; 
    if(i >= j) break; 
    exch(*(v+i), *(v+j)); 
  }

  exch(*(v+i), *(v+r)); 
  return i; 
}


int main(){
  int v[7] = {20, 40, 80, 30, 15, 10, 45}; 
  printf("%d", separa(v, 0, 6)); 
  return 0; 
}