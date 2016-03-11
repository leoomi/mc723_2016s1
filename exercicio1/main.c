#include <stdio.h>
#include <omp.h>

int primo(int n);

main(int argc, char* argv[])
{
  int n = atoi(argv[1]);
  int i, primos = 1;

  #pragma omp parallel for
  for (i = 3; i < n+1; i = i + 2){
    if (primo(i))
      primos++;
  }
  
  printf("Existem %d primos entre 1 e %d.", primos, n);
}	
