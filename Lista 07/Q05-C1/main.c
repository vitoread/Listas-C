#include <stdlib.h>
#include <stdio.h>

#define N 20

int main()
{
  int i, j, k, aux;
  int L[N] = {10,20,9,19,8,18,7,17,6,16,5,15,4,14,3,12,2,13,1,11};

  //Mesmo código da ordenação da bolha
  //Únicas diferenças são as condições de posições pares e impares
  //E a comparação que agora é "L[j-2]" evitando ou impar ou par
  for (k=0; k<N-1; k++)
  {
    if(k%2==0)
    {
      for (j=N-1; j>k; j--)
      {
        if(j%2==0)
        {
          if ( L[j] < L[j-2] )
          {
            aux = L[j]; 
            L[j] = L[j-2]; 
            L[j-2] = aux;
          }
        }
      }
    }

    if(k%2!=0)
    {
      for (j=N-1; j>k; j--)
      {
        if(j%2!=0)
        {
          if ( L[j] < L[j-2] )
          {
            aux = L[j]; 
            L[j] = L[j-2]; 
            L[j-2] = aux;
          }
        }
      }
    } 

  }

  for(i=0 ; i<N ; i++)//Imprime tudo
  {
    printf("%i ", L[i]);
  }

  return 0;
}