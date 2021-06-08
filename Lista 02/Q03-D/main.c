#include <stdlib.h>
#include <stdio.h>

int main()
{
  int C[8];
  int i, temp;

  // 1 2 3 4 5 6 7 8
  // 2 1 4 3 6 5 8 7
  // A B C D E F G H
  // 0 1 2 3 4 5 6 7
  // temp = A , A = B, B = temp
  
  printf("Digite 8 números:\n");

  for( i=0 ; i<8 ; i++)
  {
    scanf("%i", &C[i]);
  }

  for ( i=0 ; i<8 ; i=i+2 )
  {
    temp = C[i];
    C[i] = C[i+1];
    C[i+1] = temp; 
  }
  
  printf("A ordem trocada é:\n");
  for ( i=0 ; i<8 ; i++ )
  {
    printf("%i ", C[i]);
  }

}