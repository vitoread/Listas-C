#include <stdlib.h>
#include <stdio.h>

int main()
{
  int C[7];
  int i, M, M2 = 0;

  printf("Digite 7 números:\n");
  for ( i=0 ; i<7 ; i++)
  {
    scanf("%i", &C[i]);
  }

  M = C[0];
  for ( i=1 ; i<7 ; i++)
  {
    if ( C[i] > M )
    {
      M = C[i];
    }
  }
  
  for ( i=0 ; i<7 ; i++)
  {
    if ( C[i] > M2 && C[i] != M)
    {
      M2 = C[i];
    }
  }

  printf ("O segundo maior é o: %i", M2);
}