#include <stdlib.h>
#include <stdio.h>

#define N 20

int main()
{
  int i, j, k, aux;
  int L[N] = {10,27,9,31,8,28,7,39,6,70,5,19,4,88,3,15,2,29,1,80};

  //Mesmo código da ordenação da bolha
  //Únicas diferenças são as condições de posição par
  //E a comparação que agora é "L[j-2]"
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
  }

  for(i=0 ; i<N ; i++)//Imprime tudo
  {
    printf("%i ", L[i]);
  }

  return 0;
}