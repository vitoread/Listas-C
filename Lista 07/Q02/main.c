#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() 
{
  int i, y, aux;
  int L[N]={1,2,3,4,5,6,7,8,9,10};//Lista ordenada

  for( i=0 ; i<N-1 ; i++ )//Percorre a lista
  {
    //Rand funciona como jogar uma moeda
    if(rand()%2==0)//Par
    {
      //Troca o número atual pelo ultimo da lista
      aux = L[N-1];
      L[N-1]=L[i];
      L[i] = aux;
    }
    if(rand()%2!=0)//Impar
    {
      //Troca o número atual pelo proximo
      aux = L[i+1];
      L[i+1]=L[i];
      L[i] = aux;
    }
  }

  for( i=0 ; i<N ; i++ )//Imprime tudo
  {
    printf("%i ", L[i]);
  } 

  return 0;
}