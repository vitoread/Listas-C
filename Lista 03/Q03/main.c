#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//Encontrando Números Perfeitos

int main()
{
  int soma;
  int i, j;
  //O proposto era até 100, mas busquei encontrar mais números.
  for( i=1 ; i<=10000 ; i++ )
  {
    soma = 0;
    for( j=1 ; j<i ; j++ )
    {
      if(i%j==0)
      { 
        soma += j;
      }
    }
    if(soma == i)
    {
      printf("\nNúmero Perfeito: %i", i);
    }
  } 
}
