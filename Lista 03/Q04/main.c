#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int N, D, aux, i;
    float r, t;
    
    printf("Digite um número: ");
    scanf("%d", &N);

    aux = 0;
    for(D = 2; D < N + 1; D++)
    { 
        if(N % D == 0)
        {
          aux = aux + 1;
        }
    }

    if(aux == 1)
    {
      if(N % 2 != 0 && N % 4 == 1)
      {
        for(i = 1; i < N; i++)
        {
          r = sqrt(i);
          if(r == (int)r) //Analisa se é quadrado perfeito
          { 
            t = sqrt(N - i);
            if(t == (int)t) //Analisa se é quadrado perfeito
            {
                printf("O número %d é resultado da soma dos seguintes quadrados perfeitos: %d e %d. \n", N, i, N - i);
                break;
            }
          }
        }
      }
      else
      {
        printf("%d nao atende ao requisito.\n", N);
      }
    }
    else
    {
      printf("%d nao atende ao requisito.\n", N);
    }
}