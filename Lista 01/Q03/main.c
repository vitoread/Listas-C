#include <stdio.h>

int u, v, x, y, z;
int temp;

int main ()
{
  printf ("Digite 4 números iguais e 1 diferente:\n");
  scanf ("%i %i %i %i %i", &u, &v, &x, &y, &z);

  if ( u != v )
  {
    if(u != x)
    {
      printf ("O diferente está na primeira posição");
    }  
  }

  if ( v != x)
  {
    if(v != u)
    {
      printf ("O diferente está na segunda posição");
    } 
  }

  if ( x != v && x != u)
  {
    if(x != u) 
    {
      printf ("O diferente está na terceira posição");
    }  
  }

  if ( y != u)
  {
    if(y != v)
    {
      printf ("O diferente está na quarta posição");
    }  
  }

  if ( z != u && z != v)
  {
    if(z != v)
    {  
      printf ("O diferente está na quinta posição");
    }
  }

}