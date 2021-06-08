#include <stdio.h>
#include <stdlib.h>

int main()
{
  //Define-se a lista de números e o número a ser analisado
  int L[10] = {9, 2, 5, 8, 17, 11, 3, 20, 15, 31};
  int X = 8;
  //A variavel 'maior' irá guardar o maior numero menor que X
  //Caso ela permaneça em 0 até o final, não existe tal numero
  int i, maior=0;

  for(i=0 ; i<10 ; i++)//Um For que analisa toda a lista
  {
    /* Se o X for maior que o atual termo da lista ao mesmo tempo que o atual termo da lista for maior que o ultimo termo aferido, executa-se: */
    if(X>L[i] && L[i]>maior)
    {
      maior = L[i]; // 'maior' toma o atual termo da lista
    }
  }

  if(maior==0)//Como explicado, se não houver tal termo, permanece 0
  {
    printf("O maior numero menor que X não existe");
  }
  else //Em qualquer outro caso, existirá um maior número menor que X
  {
    printf("O maior numero menor que X eh %i", maior);
  }

}