#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int M = 4;
    int A[M][M];
    int B[M-1][M-1];
    int i, l, j, a, b, aux;
    int det1, det2, det3, detA;
    int det[4];

    printf("Digite os termos de uma matriz 4x4: \n");
    for( i=0 ; i<M ; i++ )
    {
        for( j=0 ; j<M ; j++ )
        {
            scanf("%i", &A[i][j]);
        }
    }

    for( j=0 ; j<4 ; j++)
    {
        //Vamos criar uma nova matriz 3x3 eliminando as colunas e linhas indicadas
        for( i=0 ; i<M-1 ; i++ )
        {
            aux=0;
            for( l=0 ; l<M-1 ; l++ )
            {
                if(j==0) //Linha 0 Coluna 0
                {
                    B[i][l]=A[i+1][l+1];
                }
                if(j==1) //Linha 0 Coluna 1
                {
                    if(l==1)
                    {
                        aux++;
                    }
                    B[i][l]=A[i+1][l+aux];
                }               
                if(j==2) //Linha 0 Coluna 2
                {
                    if(l==2)
                    {
                        aux++;
                    }
                    B[i][l]=A[i+1][l+aux];
                }
                if(j==3) //Linha 0 Coluna 3
                {
                    B[i][l]=A[i+1][l]; 
                }                                
            }
        }

        // eliminando linha 0 coluna 0
        det1 = (B[1][1]*B[2][2])-(B[1][2]*B[2][1]); //calcula a determinante
        // eliminado linha 0 coluna 1
        det2 = (B[1][0]*B[2][2])-(B[1][2]*B[2][0]); //calcula a determinante
        // eliminando linha 0 coluna 2
        det3 = (B[1][0]*B[2][1])-(B[1][1]*B[2][0]); //calcula a determinante
        // final
        det[j] = (B[0][0]*det1) - (B[0][1]*det2) + (B[0][2]*det3); //calcula o final
    }

    //Calcula segundo a equação e imprime
    detA = (A[0][0]*det[0]) - (A[0][1]*det[1]) + (A[0][2]*det[2]) - (A[0][3]*det[3]);
    printf("\nDeterminante: %i\n", detA);

    return 0;
}