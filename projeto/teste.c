#include <stdio.h>

int sortear_numero(){
  srand(time(NULL));
  return rand() % 50; 
}

int main(){

    int numero = sortear_numero();

    printf("%d\n", numero);

    return 0;
}