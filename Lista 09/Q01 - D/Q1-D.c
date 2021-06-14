#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 10

enum especie {nao_importa, gato, cachorro, passarinho, peixe, cobra};
enum opcao {n_importa, sim, nao, nao_se_aplica};
enum sexo {na_importa, macho, femea};

struct animal
{
    char nome[50];
    char dono[50];
    char pai[50];
    char mae[50];
    enum especie tipo;
    enum sexo sexo;
    int idade;
    int meses;
    float peso;
    enum opcao tem_pulgas;
};

struct animal B[N] = {
        {"Juquinha", "Bianca", "Bartolomeu", "Anabela", cobra, macho, 3, 8, 4.3, sim},
        {"Josefildo", "Bianca", "Caetano", "Pepeta", passarinho, macho, 1, 5, 0.5, nao_se_aplica},
        {"Biju", "Aninha", "Fumaca", "Anabela", passarinho, macho, 3, 1, 3.2, nao},
        {"Cuca", "Bianca", "desconhecido", "Dengosa", cobra, femea, 45, 3, 18.0, nao_se_aplica},
        {"Sansao", "Sr Luis", "Juquinha", "Anabela", passarinho, macho, 2, 9, 3.2, nao},
        {"Ricardo", "Sr Luis", "desconhecido", "Fiona", cobra, macho, 1, 1, 0.2, nao_se_aplica},
        {"Boneca", "Zequinha", "Sansao", "Anabela", passarinho, femea, 1, 1, 0.2, sim},
        {"Pipoca", "Sr Luis", "Biju", "Catuta", passarinho, macho, 1, 1, 0.2, sim},
        {"Mosquito", "Lalau", "Sansao", "Boneca", passarinho, macho, 1, 1, 0.2, sim},
        {"Espeto", "Sr Luis", "Mosquito", "Catuta", cobra, macho, 1, 1, 0.2, sim},
};

struct animal X;
int i, j, k, l, M = N;
int C[N], nC;
int D[N], nD;
int aux, cont=0;
int main()
{
    //Consulta
    system("cls");
    printf("Consulta ao banco de dados de animais: ");
    printf("\n(1)Consultar quantas pessoas possuem ao menos uma cobra e ao menos um passarinho"); 
    printf("\n(2)Encerrar");
    printf("\nDigite: "); scanf("%d", &aux);
    system("cls");
    
    if(aux==1)
    {
        //Analise
        nC = 0;
        for (i=0; i<M; i++)
        {
            if(B[i].tipo == passarinho )
            {
                C[nC] = i;
                nC++;
            } 
        } 
        nD = 0;
        for (i=0; i<nC; i++)
        {
            k = C[i];
            for (j=0; j<M; j++)
            {
                if(B[j].tipo == cobra && strncmp(B[j].dono, B[k].dono, strlen(B[j].dono)) == 0)
                {
                    D[nD] = j;
                    nD++; 
                } 
            } 
        }

        //Remover repeticoes
        for (i=0; i<nD; i++)
        {
            k = D[i];
            for (j=i+1; j<nD; j++)
            {
                l = D[j];
                if(strncmp(B[l].dono, B[k].dono, strlen(B[l].dono)) == 0)
                {
                    D[j] = -1;
                }
            }
        }
        
        //Contagem sem repeticoes
        for (i=0; i<nD; i++)
        {
            if(D[i]>=0)
            {
                cont++;
            }
        }

        //Resultados
        printf("Resultados da consulta:\n\n");
        if(cont==0)
        {
            printf("Nao existe nenhum Dono dentro dos requisitos.\n\n");
        }
        else if(cont==1)
        {
            printf("Existe %d Dono com pelo menos um passarinho e pelo menos uma cobra.\n\n", cont);
        }
        else
        {
            printf("Existem %d Donos com pelo menos um passarinho e pelo menos uma cobra.\n\n", cont);
        }
    }
    return 0;
}