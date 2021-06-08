#include <stdio.h>

#define M 11

int main() 
{
  int N = M;
  long int L[M]={110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
  int i, y, temp;
  int x = 55;

  //Imprimos a lista inicial
  printf("\n\n");
  for( i=0 ; i<N ; i++)
  {
    printf("%li ", L[i]);
  }
  
  //Toda vez que um número menor que X for encontrado
  //Ele é movido para o inicio
  i=0;
  while(i<N)
  {
    if(L[i]<x && i!=0)
    {
      for( y=i ; y>0 ; y--)
      {
        temp = L[y];
        L[y]=L[y-1];
        L[y-1] = temp;
      }
    }
    i++;
  }  

  //Imprimos a lista final
  printf("\n\n");
  for( i=0 ; i<N ; i++)
  {
    printf("%li ", L[i]);
  }   
}