#include <stdio.h>

#define M 10

int main() 
{
  int N = M;
  long int L[M]={66,90,10,50,66,30,100,66,66,20};
  int i, y;
  int x = 66;

  //Imprimos a lista inicial
  printf("\n\n");
  for( i=0 ; i<N ; i++)
  {
    printf("%li ", L[i]);
  }

  //Toda vez que se encontrar um número igual a x
  //A lista é movida para a direita e x é posto no inicio
  i=0;
  while(i<N)
  {
    if(L[i]==x)
    {
      for( y=i ; y>=0 ; y--)
      {
        L[y]=L[y-1];
      }
      L[0]=x;
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