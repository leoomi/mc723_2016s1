#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>

int primo(int teste, int primos[], int n)
{
  int i;
  int sqr = sqrt(teste);

  for(i = 0; i < n && primos[i] <= sqr; i++)
    if (teste % primos[i] == 0)
      return 0;
  return 1;
}

main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  int i, j;
  int resultado;

  int *primos = malloc (n * sizeof(int)); //Vetor de numeros primos achados ate o momento.

  for (i = 0; i < n; i++){
      int flag = 1;
      int teste;
      if (i == 0)
	teste = 2;
      else 
	teste = primos[i - 1] + 1; //começa o laço com o ultimo numero primo achado + 1
      
      //laço para calcular proximo primo
      while(flag){
	if(primo(teste, primos, i)){
	  flag = 0;
	  primos[i] = teste;
	}
	teste++;
      }    
    }

  printf("%d", primos[i-1]);
}	
