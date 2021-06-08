#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char texto[500] = "sem casca nem semente dizem os sinos da são clemente";
  char palavra1[100] = "semente";
  char palavra2[100] = "gerente";
  

  int tam1 = strlen(texto);
  int tam2 = strlen(palavra1);
  int tam3 = strlen(palavra2);
  int i=0, a=0, y=0, x=0, aux=0, cont=0;
  int i2=0, y2=0, x2=0, cont2=0, aux2;
  int teste=0, teste2=0, u;

  //A função strstr verifica no parâmetro 1 a existencia do parametro 2
  //Aqui verificamos sua existencia, para executar ou não o programa
  if(strstr(texto, palavra1))
  {
    teste=1;
  }
  else
  {
    teste=0;
  }

  //Aqui comparamos o tamanho das palavras a serem trocadas
  //Dependendo de seus tamanhos, a programação muda ente maior ou menor/igual
  if(tam3<=tam2)
  {
    teste2=1; 
  }
  else
  {
    teste2=0;
  }

  //Se a primeira verificação não for aferida, a palavra não está na frase
  //Caso seja encontrada, a programação é executada
  if(teste==0)
  {
    printf("A palavra indicada não está no texto");
  }
  else
  {
    //Se a palavra que substituirá for menor ou igual este if será executado.
    if(teste2==1)
    {
      for( i=0 ; i<tam1 ; i++) //Verificando em cada char da string
      {
        a=i;
        for( y=0 ; y<tam2 ; y++)//A ocorrencia de cada char da palavra
        {
          if(y==tam2-1)//Aqui o programa afere a posição do char inicial
          {
            x = a - tam2 + 1;//Salvando na variável x
          }
          if(palavra1[y]==texto[a])//Verificando onde a palavra está
          {
            a++;
          }
          else //Caso as igualdades sejam falsas, o for é quebrado
          {
            break;
          }
        }
      }

      for( i2=x ; y2<tam3 ; i2++ )//Começando no char inicial aferido em x
      {
        texto[i2]=palavra2[y2];//As posições no texto são trocadas pela palavra 2
        y2++;
        aux=i2+1;//Aqui verificamos o primeiro char depois da palavra trocada
      }
      x2 = tam2-tam3;//Assumimos x2 como o char imediatamente após a palavra 1
      for(cont2=aux ; cont2<tam1 ; cont2++)//A partir do final da palavra 2
      {
        texto[cont2] = texto[cont2+x2];//O resto do texto é movido 'x2' posições;
      }

      printf("%s", texto);// O texto remodelado é apresentado
    }
    //Se a palavra for maior, este else será executado
    else if(teste2==0)
    {
      for( i=0 ; i<tam1 ; i++) //Verificando em cada char da string
      {
        a=i;
        for( y=0 ; y<tam2 ; y++)//A ocorrencia de cada char da palavra
        {
          if(y==tam2-1)//Aqui o programa afere a posição do char inicial
          {
            x = a - tam2 + 1;//Salvando na variável x
          }
          if(palavra1[y]==texto[a])//Verificando onde a palavra está
          {
            a++;
          }
          else //Caso as igualdades sejam falsas, o for é quebrado
          {
            break;
          }
        }
      }
      x2 = tam3-tam2; //Verificando quanto espaço falta no texto
      for(aux2=0; aux2 < x2; aux2++)//Adicionando o espaço no final do texto
      {
        strcat(texto, " ");//Contatenar espaço ao final do texto
      }
      tam1 = strlen(texto);//Aferindo o novo tamanho
      for(cont2=tam1-1 ; cont2> x+tam3 ; cont2--)//A partir do final do texto
      { 
        //Movendo o texto para a direita até o limite da nova palavra
        texto[cont2] = texto[cont2-x2];
        texto[cont2-x2]= ' ';
      }
      for( i2=x ; y2<tam3 ; i2++ )//Começando no char inicial aferido em x
      {
        texto[i2]=palavra2[y2];//As posições no texto são trocadas pela palavra 2
        y2++;
      }      

      printf("%s", texto);// O texto remodelado é apresentado
    }
  }
}