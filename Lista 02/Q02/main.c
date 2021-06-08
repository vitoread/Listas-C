#include <stdlib.h>
#include <stdio.h>


int main() 
{
  float N[8];
  float soma;
  float media;
  int nAcima = 0;
  int nAbaixo = 0;
  int i, a;

  printf("Digite 8 notas:\n");
  for ( i=0 ; i<8 ; i++)
  {
    scanf("%f", &N[i]);
  }

  for ( i=0 ; i<8 ; i++)
  {
    soma = soma + N[i];
  }

  media = soma / 8;

  for ( i=0 ; i<8 ; i++)
  {
    if ( N[i] > media)
    {
      nAcima++;
    }

    if ( N[i] < media)
    {
      nAbaixo++;
    }
  }
  printf ("\nA média dos alunos é %f\n\n", media);
  printf ("%i alunos ficaram acima da média\n", nAcima);
  printf ("%i alunos ficaram abaixo da média\n", nAbaixo);
}