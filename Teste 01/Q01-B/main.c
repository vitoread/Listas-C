#include <stdio.h>
#include <stdlib.h>

int main()
{
  int X, Y;
  int i, y, mdc=1;

  //Iniciamos digitando os 2 numeros para calcular o MDC
  printf("Digite 2 numeros inteiros positivos: \n");
  scanf("%i %i", &X, &Y);

  //Começando pelo 2 e incrementando até o valor de um dos números
  for(i=2 ; i<X ; i++ )
  {
    /*Esse for serve exclusivamente para executar as divisões o máximo de vezes possível, pois existem casos que os números podem ser divididos pelo mesmo primo mais de uma vez.*/
    for(y=0 ; X%i==0 && Y%i==0 ; y++)
    {
      if(i%2!=0 || i==2)//Aqui verificamos se esse número é impar ou igual a 2
      {
        if(X%i==0 && Y%i==0)//Aqui verificamos se ele divide sem resto os 2 números juntos
        {
          X = X/i; //Dividimos e adotamos o novo valor de X
          Y = Y/i; //Dividimos e adotamos o novo valor de Y
          mdc = mdc * i; //MDC é a multiplicação entre os valores que dividiram ambos os termos
        }
      }
    }
  }

  printf("O MDC eh %i", mdc); //Imprimos o valor do MDC
  return 0;
}