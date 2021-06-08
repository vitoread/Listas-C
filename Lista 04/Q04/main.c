#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char texto[100] = "sem casca e sem semente dizem os sinos da são clemente clemente";
  char palavra[100] = "clemente";

  int tam = strlen(texto);
  int tam2 = strlen(palavra);
  int i, y, aux, cont;

  //Mesmo conceito da busca de palavras em um texto
  //No entanto, ele não interrompe a analise ao encontrar
  //Continua até o final em um mesmo ciclo e ao encontrar mais de uma vez, interrompe
  for( i=0 ; i<tam ; i++)
  {
    for( y=0 ; y<tam2 ; y++)
    {
      if(palavra[y] == texto[i])
      {
        aux=1;
        i++;
      }
      else
      {
        aux=0;
        break;
      }
    }

    if(aux==1)//Caso a palavra seja econtrada, contador+1
    {
      cont++;
    }
    if(cont>1)//Somente se o contador encontrou + de 1 vez
    {
      printf("A palavra '%s' está repetida no texto.", palavra);
      break;
    }
    if(cont<=1 && i==tam-1)//Somente se o contador não encontrar mais de uma vez e quando tiver certeza que de que ja foi analisado até o final
    {
      printf("A palavra '%s' não está repetida no texto.", palavra);
      break;
    }

  }
}