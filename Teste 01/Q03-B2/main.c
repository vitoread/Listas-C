#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char texto[500] = "Nem casca sem semente e nem semente sem casca dizem sem semente e sem casca os sinos de São Clemente.";
  char palavra1[100] = "semente"; //Ocorrência F
  char palavra2[100] = "casca"; //Ocorrência G
  int tam = strlen(texto);
  int tam1 = strlen(palavra1);
  int tam2 = strlen(palavra2);
  int i, y, l, a, aux, aux2=0, x, x2;

  printf("Texto Inicial: \n");
  printf("%s\n\n", texto);

  for(i=0 ; i<tam ; i++)
  {
    /////////////////////////////////// PROCURANDO OCORRENCIA F
    x=0;
    a=i;
    for( y=0 ; y<tam1 ; y++)//A ocorrencia de cada char da palavra
    {
      if(y==tam1-1)//Aqui o programa afere a posição do char inicial
      {
        x = a - tam1 + 1;//Salvando na variável x
      }
      if(palavra1[y]==texto[a])//Verificando onde a palavra está
      {
        aux=1; //Salva se até o final as igualdades se mantiveram
        a++;
      }
      else //Caso as igualdades sejam falsas, o for é quebrado
      {
        aux=0; //E a condição de troca é retirada
        break;
      }
    }
    /////////////////////////////////// TROCANDO F POR G
    if(tam1 >= tam2)//Se a palavra G for menor ou igual
    {
      l=0;
      if(aux==1)//Se a condição de troca é verdadeira
      {
        for( y=x ; l<tam2 ; y++ )//Começando no char inicial aferido em x
        {
          texto[y]=palavra2[l];//As posições no texto são trocadas pela palavra 2
          l++;
          aux2=y+1;//Aqui verificamos o primeiro char depois da palavra trocada
        }
        x = tam1-tam2;//Assumimos x como o char imediatamente após a palavra 1
        y=0;
        for(y=aux2 ; y<tam ; y++)//A partir do final da palavra 2
        {
          texto[y] = texto[y+x];//O resto do texto é movido 'x' posições;
        }
      }
    }
    if(tam1 < tam2)//Se a palavra G for maior
    {
      l=0;
      if(aux==1)//Se a condição de troca for verdadeira
      {
        x2 = tam2-tam1; //Verificando quanto espaço falta no texto
        for(y=0; y<x2; y++)//Adicionando o espaço no final do texto
        {
          strcat(texto, " ");//Adiciona espaço ao final do texto
        }
        tam = strlen(texto);//Aferindo o novo tamanho
        y=0;
        for(y=tam-1 ; y> x+tam2 ; y--)//A partir do final do texto
        { 
          //Movendo o texto para a direita até o limite da nova palavra
          texto[y] = texto[y-x2];
          texto[y-x2]= ' ';
        }
        y=0;
        for( y=x ; l<tam2 ; y++ )//Começando no char inicial aferido em x
        {
          texto[y]=palavra2[l];//As posições no texto são trocadas pela palavra 2
          l++;
        } 
      }    
    }
    /////////////////////////////////// PROCURANDO OCORRENCIA G
    tam = strlen(texto);
    aux=0;
    l=0;
    x=0;
    for( y=0 ; y<tam2 ; y++)//A ocorrencia de cada char da palavra
    {
      if(y==tam2-1)//Aqui o programa afere a posição do char inicial
      {
        x = a - tam2 + 1;//Salvando na variável x
      }
      if(palavra2[y]==texto[a])//Verificando onde a palavra está
      {
        aux=1; //Salva se até o final as igualdades se mantiveram
        a++;
      }
      else //Caso as igualdades sejam falsas, o for é quebrado
      {
        aux=0; //E a condição de troca é retirada
        break;
      }
    }
    /////////////////////////////////// TROCANDO G POR F
    if(tam2 < tam1)//Se a palavra F for maior
    {
      l=0;
      if(aux==1)//Se a condição de troca for verdadeira
      {
        x2 = tam1-tam2; //Verificando quanto espaço falta no texto
        for(y=0; y<x2; y++)//Adicionando o espaço no final do texto
        {
          strcat(texto, " ");//Adiciona espaço ao final do texto
        }
        tam = strlen(texto);//Aferindo o novo tamanho
        y=0;
        for(y=tam-1 ; y>x+tam1 ; y--)//A partir do final do texto
        { 
          //Movendo o texto para a direita até o limite da nova palavra
          texto[y] = texto[y-x2];
          texto[y-x2]= ' ';
        }
        y=0;
        for( y=x ; l<tam1 ; y++ )//Começando no char inicial aferido em x
        {
          texto[y]=palavra1[l];//As posições no texto são trocadas pela palavra 1
          l++;
        } 
      }
    }
    if(tam2 >= tam1)//Se a palavra F for menor ou igual
    {
      l=0;
      if(aux==1)//Se a condição de troca for verdadeira
      {
        for( y=x ; l<tam1 ; y++ )//Começando no char inicial aferido em x
        {
          texto[y]=palavra1[l];//As posições no texto são trocadas pela palavra 1
          l++;
          aux2=y+1;//Aqui verificamos o primeiro char depois da palavra trocada
        }
        x = tam2-tam1;//Assumimos x como o char imediatamente após a palavra 2
        y=0;
        for(y=aux2 ; y<tam ; y++)//A partir do final da palavra 2
        {
          texto[y] = texto[y+x];//O resto do texto é movido 'x' posições;
        }
      }
    }
    ///////////////////////////////////////////////
  }
  printf("Texto Final: \n");
  printf("%s\n\n", texto);

  return 0;
}