#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int M = 3;
    int A[M][M];
    int i, j, det1, det2, det3, detA;

    printf("Digite os termos de uma matriz 3x3:\n");
    for( i=0 ; i<M ; i++ )
    {
        for( j=0 ; j<M ; j++ )
        {
            scanf("%i", &A[i][j]);
        }
    }

    // eliminando linha 0 coluna 0
    det1 = (A[1][1]*A[2][2])-(A[1][2]*A[2][1]); //calcula a determinante
    // eliminado linha 0 coluna 1
    det2 = (A[1][0]*A[2][2])-(A[1][2]*A[2][0]); //calcula a determinante
    // eliminando linha 0 coluna 2
    det3 = (A[1][0]*A[2][1])-(A[1][1]*A[2][0]); //calcula a determinante
    // final
    detA = (A[0][0]*det1) - (A[0][1]*det2) + (A[0][2]*det3); //calcula o final

    printf("A determinante eh: %i", detA);
}