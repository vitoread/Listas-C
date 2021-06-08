#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//Aproximando o valor de Pi

int main()
{
  int i;
  float soma = 0;
  float pi2, pi;
  float valor = 3.141592;
  float m, a;

  //Quanto maior o numero de somas, mais ele se aproxima do valor de Pi.
  for ( i=1 ; i<1000; i++)
  {
    soma = soma + (1 / pow(i,2));
  }

  pi2 = soma * 6;
  pi = sqrt(pi2);

  printf("\nAproximação de Pi:");
  printf("\n%f", pi);

}