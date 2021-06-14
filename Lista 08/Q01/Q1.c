#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int M, N;
    printf("Digite os valores de M e N:\n");
    scanf("%i %i", &M, &N); 

    int A[M][N], B[N][M], C[M][M]; //Definem-se as matrizes e a matriz resultado
    int i, j, l;

    printf("Digite os termos da matriz A:\n");
    for( i=0 ; i<M ; i++ )
    {
        for( j=0 ; j<N ; j++ )
        {
            scanf("%i", &A[i][j]);
        }
    }

    printf("Digite os termos da matriz B:\n");
    for( i=0 ; i<N ; i++ )
    {
        for( j=0 ; j<M ; j++ )
        {
            scanf("%i", &B[i][j]);
        }
    }

    //Definindo a matriz resultado
    for( i=0 ; i<M ; i++ )
    {
        for( j=0 ; j<M ; j++ )
        {
            C[i][j]=0; //Zerando antes de somar
            for( l=0 ; l<N ; l++ )
            {
                C[i][j]+=A[i][l]*B[l][j]; //Multiplica os termos de A e B
            }
        }
    }

    //Imprimindo a matriz resultado
    printf("Matriz C:\n");
    for( i=0 ; i<M ; i++ )
    {
        for( j=0 ; j<M ; j++ )
        {
            printf("%i ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}