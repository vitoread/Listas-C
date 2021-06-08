#include <stdlib.h>
#include <stdio.h>

#define N 15

int main()
{
  int i, j, k, aux;
  int L[N] = {5,15,25,4,14,24,3,13,23,2,12,22,1,11,21};

  //Mesmo código da ordenação da bolha
  //Únicas diferenças são as condições de posições
  // 0, 3, 6, 9, 12 ... //Resto 0 ao dividir por 3 e pos 0
  // 1, 4, 7, 10, 13 ... //Resto 1 ao dividir por 3 e pos 1
  // 2, 5, 8, 11, 14 ... //Resto 2 ao dividir por 3 e pos 2
  for (k=0; k<N-1; k++)
  {
    if(k%3==0) //Resto 0
    {
      for (j=N-1; j>k; j--)
      {
        if(j%3==0) //Resto 0
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

    if(k%3==1 || k==1) //Resto 1
    {
      for (j=N-1; j>k; j--)
      {
        if(j%3==1 || j==1) //Resto 1
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

    if(k%3==2 || k==2) //Resto 2
    {
      for (j=N-1; j>k; j--)
      {
        if(j%3==2 || j==2) //Resto 2
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