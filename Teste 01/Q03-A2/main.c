#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char texto[100] = "nem semente sem casca nem casca sem semente dizem os sinos de sao clemente";
  char palavra[100]="\0";

  int tam=strlen(texto);
  int tam2;
  int i=0, y, l, aux, cont=0, teste=0;

  /* Percorremos o texto até o primeiro espaço, que simboliza o fim da primeira palavra. Em tese, o fim de qualquer palavra poderia também ser um ponto ou uma vírgula, mas adotei somente o espaço para o exemplo */
  for( l=0 ; l<=tam ; l++)
  {
    if(texto[l]!=' ' || l==tam)
    {
      //Colocamos o texto até o espaço na variável palavra
      palavra[i]=texto[l];
      i++;
    }
    else
    {  
      /* Esta linha serve para apagar caracteres a mais, provenientes de palavras maiores que vieram anterioremetne */
      palavra[i]='\0';
      //Aferimos o tamanho da nova palavra
      tam2=strlen(palavra);
      i=0;
      //Mesmo conceito da busca de palavras em um texto
      //No entanto, ele não interrompe a analise ao encontrar
      //Continua até o final em um mesmo ciclo e ao encontrar mais de uma vez, interrompe
      for( i=l ; i<tam ; i++)
      {
        /*Essse if verifica se o digito anterior ao inicio da palavra é um ' ', para não pegar palavras no meio de outras. ex: alto e planaltos */
        if(texto[i-1] == ' ')
        {
          /* Este if verifica se o final do tamanho da palavra é um ' ' ou se é o fim do texto, para que não aconteça o mesmo do ultimo if. ex: sem e semente */
          if(texto[i+tam2] == ' ' || i+tam2==tam)
          {
            for( y=0 ; y<tam2 ; y++)
            {
              if(palavra[y] == texto[i])
              {
                aux=1;//Enquanto a igualdade for verdadeira, aux sempre é 1
                i++;
              }
              else
              {
                aux=0;//Caso seja desfetia, aux torna-se 0, e o contador não incrementa
                break;
              }
            }
          }
        }

        if(aux==1)//Caso a palavra seja econtrada, contador+1
        {
          cont++;
        }
        
        if(cont>1)//Somente se o contador encontrou + de 1 vez
        {
          cont=0;
          i=0;
          teste++;//O mais importante é esse, que se encontrar pelo menos um caso, incrementa
          break;
        }
        if(cont<=1 && i==tam-1)//Somente se o contador não encontrar mais de uma vez e quando tiver certeza que de que ja foi analisado até o final
        {
          cont=0;
          i=0;
          //Note que aqui não existe 'teste++'
          break;
        }

      }      
    }
  }

  if(teste==0)//Se 'teste' não foi incrementado nenhuma vez, não existem repetições.
  {
    printf("Não existem casos de palavras repetidas no texto.\n");
  }
  if(teste>0)//Se 'teste' foi incrementado ao menos uma vez, existem.
  {
    //Alguma palavra de todo o texto foi encontrada repetida
    printf("Existe pelo menos um caso de palavra repetida no texto.\n");
  }

  return 0;
}