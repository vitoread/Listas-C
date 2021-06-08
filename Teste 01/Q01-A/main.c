#include <stdio.h>
#include <stdlib.h>

int main()
{
  //Definindo as 4 váriaveis a serem analisadas e uma 'temp' auxiliar
  int X=4;
  int Y=3;
  int Z=5;
  int W=1;
  int temp;
  /* A minha ideia foi colocar os números em ordem crescente, e realizar comparações somente com o primeiro e o último, já que eles podem ter diferenças para mais ou para menos */

  /* Essa sequencia de if's realizam a ordem crescente, colocando sempre o menor em uma variável auxiliar, trazendo-os para a esquerda da lista */

  if (X > Y)
  {
    temp = Y; //Temporária toma o valor do menor
    Y = X; //O valor do maior vai para o lado direito
    X = temp; // O valor do menor vai para o lado esquerdo
  }
  if (X > Z)
  {
    temp = Z;
    Z = X;
    X = temp;
  }
  if (X > W)
  {
    temp = W;
    W = X;
    X = temp;
  }
  if (Y > Z)
  {
    temp = Z;
    Z = Y;
    Y = temp;
  }
  if (Y > W)
  {
    temp = W;
    W = Y;
    Y = temp;
  }
  if (Z > W)
  {
    temp = W;
    W = Z;
    Z = temp;
  } 

  /* Depois que os números são colocados em ordem crescente, seguindo a regra de que eles podem ser diferentes em 2, para mais ou para menos, comparamos: */
  if (Y-X>=2) //A subtração do segundo número com o primeiro
  {
    /* Se essa diferença for maior ou igual a 2, significa que o primeiro número é o distante, então imprimios seu valor */
    printf("O numero distante eh o %i", X);
  }
  if (W-Z>=2) //A subtração do quarto número com o terceiro
  {
    /* Se essa diferença for maior ou igual a 2, significa que o quarto número é o distante, então imprimios seu valor */
    printf("O numero distante eh o %i", W);
  }
  /* Como são apenas 4 termos, o distante só pode estar em uma das estremidadeas, ness caso, só 1 dos if's será executado. */

  return 0;
}