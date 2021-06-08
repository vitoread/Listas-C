#include <stdlib.h>
#include <stdio.h>

int main()
{
  int C[6];
  int i;

  printf("Digite 6 números:\n");
  for ( i=0 ; i<6 ; i++)
  {
    scanf("%i", &C[i]);
  }

  printf("A ordem invertida é:");

  for ( i=5 ; i>=0 ; i--)
  {
    printf("\n%i", C[i]);
  }
}