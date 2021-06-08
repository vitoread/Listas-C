#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Define-se previamente uma lista com qualquer tamanho e com termos inteiros positivos diferentes de zero */
  int L[10] = {3,2,5,2,1,4,3,5,1,3};
  int i, y;
  int cont=0;

  /* Analisaremos cada termo da lista com os proximos e a cada número repetido que encontrarmos substituiremos ele por zero,essa foi a estrategia que pensei para que no final tenhamos somente 1 número de cada na lista L para colocarmos na lista A */
  for(i=0 ; i<10 ; i++)
  {
    for(y=i+1 ; y<10 ; y++) //Analisando o termo i com os seguintes
    {
      if(L[i]==0)//Se um número zero previamente colocado for encontrado
      {
        break; // Interrompemos o for, para que ele não seja comparado
      }
      if(L[i]==L[y]) // Caso eles sejam iguais
      {
        L[y]=0; //Os duplciados se tornam Zero
        cont++; //A cada zero colocado na lista, fazemos uma contagem
      }
    }
  }
  //Depois de substituir todos os duplicados por zeros, criaremos a lista A
  // a Lista A tem o tamanho da lista L menos a contagem de 0 substituidos
  int a = 10 - cont; 
  int A[a];

  /* Realizamos outro loop, para que cada termo da Lista A tome um número diferente de zero da lista L */
  i=0;
  for(y=0 ; y<10 ; y++)
  {
    if(L[y]!=0) //Se o termo em L for diferente de 0
    {
      A[i]=L[y]; //O termo em A toma esse valor
      i++; //E pulamos para o proximo termo de A somente quando um termo for alocado
    }
  }

  //Um simples For imprimindo os termos da nova Lista A
  printf("Lista A:\n");
  for(i=0; i<a ; i++)
  {
    printf("%i\n", A[i]);
  }

  return 0;
}