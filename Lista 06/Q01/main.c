#include <stdio.h>

#define M 9

int main() 
{
  int N = M;
  long int L[M]={10, 30, 50, 70, 90, 20, 40, 60, 15};
  int i, y, temp;
  int x = 45;
  int pos = 60;

  //Imprimos a lista inicial
  printf("\n\n");
  for( i=0 ; i<N ; i++)
  {
    printf("%li ", L[i]);
  }

  //Procuramos o elemento armazenado em POS e substituimos por X
  i=0;
  while(i<N)
  {
    if(L[i]==pos)
    {
      L[i] = x;
      break;
    }
    i++;
  }

  //Colocamos a lista em ordem crescente
  for (i=0;i<N; i++)
  {
    for(y=i+1;y<N;y++)
    {
      if (L[i]>L[y])
      {
          temp=L[i];
          L[i]=L[y];
          L[y]=temp;
      }
    }
  }

  //Imprimos a lista final
  printf("\n\n");
  for( i=0 ; i<N ; i++)
  {
    printf("%li ", L[i]);
  }
}
