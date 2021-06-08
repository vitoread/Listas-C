#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char texto[500] = "Sem casca nem semente, dizem os sinos da São Clemente, esses vinténs são pra mim, cantam os sinos da São Martim, e o culpado, quem é, afinal, perguntam os sinos do Tribunal, a culpa é da Judite, respondem os sinos de Shoreditch.";


  int i, y=0, pos=0;
  int tam = strlen(texto);

  for( i = 0 ; pos+29 < tam ; i++)//Defio para o for realizar o loop até a posição 30
  {
    if(texto[pos + 29] == ' ')//Se a ultima posição limite for um espaço
    { 
      texto[pos + 29] = '\n';//Sem problema, nos imprimiremos a linha
      pos += 30;//Faz com que a nova posição inicial seja o proximo char
    }
    else //Caso o ultimo não seja um espaço, significa que existe uma palavra
    {
      for( y = pos+29; y > 0 ; y--)//A partir da ultima posição limite
      { 
        if(texto[y] == ' ')//Retornaremos char por char até achar um ' '
        { 
          texto[y] = '\n';//Se for encontrado, substituir por uma quebra
          pos = y + 1;//A nova posição é a partir do ponto de quebra+1
          break;//Interrompe o for
        }
      }
    }
  }

  printf("%s", texto);
}