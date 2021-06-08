#include <stdio.h>

#define M 10

int main() 
{
  int N = M;
  long int L[M]={10,20,30,4,50,6,70,80,90,100};
  int i, y;
  int x = 10;

  //Procuramos números que sejam o dobro de X até o fim da lista
  //Imprimimos e paramos caso ache
  i=0;
  while(i<N)
  {
    if(L[i]==x*2)
    {
      printf("\nExiste o dobro de X está na lista.\n\n");
      break;
    }
    else if(i==N-1)
    {
      printf("\nNão existe o dobro de X na lista.\n\n");
    }
    i++;
  }

  //Procuramos pares que somados sejam X em toda a lista
  //Imprimimos e paramos caso ache
  i=0;
  for( y=1 ; y<=N-i ; y++)
  {
    if(L[i]+L[i+y]==x)
    {
      printf("Existe um par cujo a soma é X.\n\n");
      break;
    }
    if(y==N-i)
    {
      i++;
      y=0;
    }
    if(i==N-1)
    {
      printf("Não existe par cujo a soma é X.\n\n");
      break;
    }
  }

}
