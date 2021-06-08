#include <stdio.h>

int main ()
{
  int u, v, x, y, z;
  int temp;

  printf ("Digite 5 números:\n");
  scanf ("%i %i %i %i %i", &u, &v, &x, &y, &z);

  //O comando Meio pega 3 elementos e coloca o do meio na posição do meio.

  //U V X 
  if (u > v){
    temp = v;
    v = u;
    u = temp;
  }
  if (u > x){
    temp = x;
    x = u;
    u = temp;
  }
  
  //X Y Z
  if (x > y){
    temp = y;
    y = x;
    x = temp;
  }
  if (x > z){
    temp = z;
    z = x;
    x = temp;
  }
  //V X Y
  if (v > x){
    temp = x;
    x = v;
    v = temp;
  }
  if (v > y){
    temp = y;
    y = v;
    v = temp;
  }
  printf ("O elemento do meio é o número %i", x);
}