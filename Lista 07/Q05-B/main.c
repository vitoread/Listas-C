#include <stdlib.h>
#include <stdio.h>

#define N 28

int main()
{
  int i, j, k, aux;
  int L[N] = {10,15,65,9,80,97,8,12,56,7,39,17,6,25,41,5,22,66,4,78,67,3,19,32,2,64,70,1};

  //Mesmo código da ordenação da bolha
  //Únicas diferenças são as condições de posições multiplas de 3
  //E a comparação que agora é "L[j-3]"
  for (k=0; k<N-1; k++)
  {
    if(k%3==0)
    {
      for (j=N-1; j>k; j--)
      {
        if(j%3==0)
        {
          if ( L[j] < L[j-3] )
          {
            aux = L[j]; 
            L[j] = L[j-3]; 
            L[j-3] = aux;
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