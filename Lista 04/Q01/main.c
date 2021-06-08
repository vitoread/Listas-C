#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int i;
  char n[50] = "joana ganhou duas casa a rodo";
  int tam = strlen(n); 
  //Defino minha frase e o seu tamanho mínimo para limitar o programa

  for( i=0 ; i<tam ; i++ )
  {
    //Analisando char por char, se encontrar um espaço, pula linha
    if (n[i] == ' ')
    {
      printf("\n");
    }
    //Caso contrário, apenas imrpima o char
    else
    {
      printf("%c", n[i]);
    }
  }
}