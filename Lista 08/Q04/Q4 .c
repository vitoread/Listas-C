#include <stdlib.h>
#include <stdio.h>

#define M 2

int main()
{
    int i,j,k,l;
    float x,y,z,w;
    float fator;

    for( l=0 ; l<2 ; l++)
    {
        float A[M][M+1] = { { 1, 2},
                             { 3, 4}
                           };
        if(l==0) //Define as 2 divisões da matriz identidade
        {
            A[0][2]=1;
            A[1][2]=0;
        }
        if(l==1) //Define as 2 divisões da matriz identidade
        {
            A[0][2]=0;
            A[1][2]=1;   
        }

        // ETAPA 1: zerando abaixo da diagonal
        for (i=0; i<M-1; i++)
        {
            for (j=i+1; j<M; j++)
            {
                fator = - A[i][i] / A[j][i];
                for (k=0; k<=M; k++)
                {
                    A[j][k] = A[i][k] + fator * A[j][k];
                }
            }
        }

        // ETAPA 2: zerando acima da diagonal
        for (i=M-1; i>0; i--)
        {
            for (j=i-1; j>=0; j--)
            {
                fator = - A[i][i] / A[j][i];
                for (k=0; k<=M; k++)
                {
                    A[j][k] = A[i][k] + fator * A[j][k];
                }
            }
        }

        // ETAPA 3: colocando 1’s na diagonal
        for (i=0; i<M; i++)
        {
            fator = 1 / A[i][i];
            A[i][i] = fator * A[i][i];
            A[i][M] = fator * A[i][M];
        }

        if(l==0) //Define as 2 variaveis da parte 1
        {
            x = A[0][2];
            z = A[1][2];
        }
        if(l==1) //Define as 2 variaveis da parte 2
        {
            y = A[0][2];
            w = A[1][2];     
        }
    }

    //Imprime a matriz inversa
    printf("\nx y -> %5.2f %5.2f\n", x, y);
    printf("z w -> %5.2f %5.2f\n", z, w);
}