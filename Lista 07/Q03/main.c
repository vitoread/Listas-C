//Incompleto
#include <stdio.h>

#define M 4
#define N 5

int main() 
{
  int K = M + N;
  long int L1[M]={10,30,50,70};
  long int L2[N]={20,40,60,80,90};
  long int L3[K];
  int i, y, a, temp;

  //Juntamos em uma lista L3 as listas L1 e L2
  y=0;
  for( i=0 ; y<M ; i++)
  {
    L3[i]=L1[y];
    y++;
  }
  y=0;
  for( i=i ; y<N ; i++)
  {
    L3[i]=L2[y];
    y++;
  }  

  //Imprimos a lista L3 inicial
  printf("\n\n");
  for( i=0 ; i<K ; i++)
  {
    printf("%li ", L3[i]);
  } 

  //Colocamos a lista L3 em ordem crescente
  for (i=0;i<K; i++)
  {
    for(y=i+1;y<K;y++)
    {
      if (L3[i]>L3[y])
      {
          temp=L3[i];
          L3[i]=L3[y];
          L3[y]=temp;
      }
    }
  }

  //Imprimos a lista L3 final
  printf("\n\n");
  for( i=0 ; i<K ; i++)
  {
    printf("%li ", L3[i]);
  } 
}