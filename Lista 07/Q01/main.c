#include <stdio.h>

#define N 20

int main()
{
  int i, y=0, j, a=0;
  int L[N]={2,1,2,0,0,2,1,2,0,1,2,2,2,0,0,0,1,0,0,1};
  int L2[N];

  for(j=0 ; j<3 ; j++)//A analise será feita 3 vezes; 0, 1 e 2
  {
    for(i=0 ; i<N ; i++)//Percorre a lista inteira
    {
      if(L[i]==j)//Na ordem 0, 1 e 2
      {
        L2[y]=j;//A posição i
        y++;
      }
    }
  }

  for(i=0 ; i<N ; i++)
  {
    printf("%i ", L2[i]);
  }

  return 0;
}