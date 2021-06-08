#include <stdio.h>

int main ()
{
  int N=10;
  int L[10]={1,2,4,3,5,6,7,8,9,10};
  int i=0, y=1, temp=0;

  for( y=1 ; y<=N-i ; y++)
  {
    if(L[i]>L[i+y])
    {
      temp = L[i+y];
      L[i+y] = L[i];
      L[i] = temp;
    }
    if(y==N-i)
    {
      i++;
      y=0;
    }
  }
  
  for( i=0 ; i<N ; i++)
  {
    printf("%i ", L[i]);
  }
  
}