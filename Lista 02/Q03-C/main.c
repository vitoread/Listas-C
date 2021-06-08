#include <stdlib.h>
#include <stdio.h>

int main()
{
  //Dependendo do número de termos, altera-se um pouco.
  //Se impares, o paço entre as contagens é igual.
  //Se pares, a contagem secundária incia 1 unidade depois.
  int C[7];
  int C2[7];
  int i, y;
  
  printf("Digite 7 números:\n");
  for ( i=0, y=0 ; i<7 ; i++, y++)
  {
    scanf("%i", &C[i]);
    C2[y] = C[i];
  }

  printf("Invertendo a ordem somente dos pares, temos:");

  for( i=0, y=6 ; i<7 && y>=0 ; i++, y--)
  {
    if( (i+1) % 2 == 0 )
    {
      printf("\n%i", C2[y]);
    }
      
    else    
    {
      printf("\n%i", C[i]);
    }   
  }
}