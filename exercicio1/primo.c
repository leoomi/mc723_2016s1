#include <stdio.h>

int primo(int n)
{
  int i;

  for(i = 2; i < n; i ++)
    if (n % i == 0)
      return 0;
  
  return 1;
}

main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  int i, primos = 1;

  for (i = 3; i < n+1; i = i + 2){
    if (primo(i))
      primos++;
  }
  
  printf("Existem %d primos entre 1 e %d.", primos, n);
}	
	
