#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//Aproximando Raíz de 2

int main()
{
  float x = 2;
  float a = 0;
  float m;
  int i, y;

  printf("Digite a quantidade de aproximações:\n");
  scanf("%i", &y);

  for( i=0 ; i<y ; i++)
  {
    m = (a+x)/2;
    if(m*m>2)
    {
      x = m;
      // Se passar do valor estipulado, ele fará a média com a soma do mesmo número, o que dará o proprio número anterior ao limite.
    }
    else
    {
      a = m;
      //Caso ainda possa se continuar aproximando, ele continuará somando o novo valor a 2, obtendo novas médias.
    }
  }

  printf("\nA aproximação da Raíz de 2 é:\n%f", m);

}