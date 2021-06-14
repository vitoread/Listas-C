#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int M = 3;
    int A[M][M+2];
    int i, j, soma1=0, soma2=0, det=0;

    printf("Digite os termos de uma matriz 3x3:\n");
    for( i=0 ; i<M ; i++ )
    {
        for( j=0 ; j<M ; j++ )
        {
            scanf("%i", &A[i][j]);
            A[i][j+3]=A[i][j];//Extende a matriz para realizar o calculo
        }
    }

    //Usando o "método da escola", calcula-se a determinante

    //Calcula a soma da esquerda para direita
    i=0;
    for( j=0 ; j<M ; j++ )
    {
        soma1+=(A[i][j])*(A[i+1][j+1])*(A[i+2][j+2]);
    }

    //Calcula a soma da direita para esquerda
    i=0;
    for( j=2 ; j<M+2 ; j++ )
    {
        soma2-=A[i][j]*A[i+1][j-1]*A[i+2][j-2];
    } 

    //Soma e imprime
    det=soma1+soma2;
    printf("\nDeterminante: %i\n", det);

    return 0;
}