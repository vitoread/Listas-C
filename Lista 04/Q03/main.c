#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char texto[100] = "sem casca nem semente dizem os sinos da são clemente";

  int i, y, pos;
  int tam = strlen(texto);

  for( i = tam ; i >= 0 ; i--)//Iniciando do final do texto
  {
    if(texto[i] == ' ' | i==0)//Se econtramos um espaço ou chegarmos ao primeiro char da frase
    { 
      if(i==0)//Quando chegar a primeira letra da frase
      {
        i--;//Anulamos a soma do proximo for, para que o termo '0' seja analisado e impresso
      }
      for( y = i+1 ; y<tam ; y++)//A partir do espaço econtrado+1 começamo a imprimir a palavra
      {
        if(texto[y]==' ')//Se um novo espaço for achado, interrompe-se
        {
          break;
        }
        printf("%c", texto[y]);//Imprimindo char por char
      }
      printf(" ");//Imprim-se um espaço a cada passo do for
    }
  }
}

