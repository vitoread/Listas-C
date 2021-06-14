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
        {"Juquinha", "Sr Silva", "Bartolomeu", "Anabela", gato, macho, 3, 8, 4.3, sim},
        {"Valadao", "Bianca", "Caetano", "Pepeta", passarinho, macho, 1, 5, 0.5, sim},
        {"Biju", "Aninha", "Fumaca", "Anabela", gato, macho, 3, 1, 3.2, nao},
        {"Cuca", "Sra Silva", "desconhecido", "Dengosa", cobra, femea, 45, 3, 18.0, nao_se_aplica},
        {"Sansao", "Sr Luis", "Juquinha", "Anabela", gato, macho, 2, 9, 3.2, nao},
        {"Alexander", "Sr Silva", "desconhecido", "Fiona", peixe, macho, 1, 1, 0.2, nao_se_aplica},
        {"Boneca", "Zequinha", "Sansao", "Anabela", gato, femea, 1, 9, 0.2, sim},
        {"Pipoca", "Lalau", "Biju", "Catuta", gato, macho, 1, 1, 0.2, sim},
        {"Mosquito", "Lalau", "Sansao", "Boneca", gato, macho, 1, 4, 0.2, sim},
        {"Espeto", "Lalau", "Mosquito", "Catuta", gato, macho, 1, 1, 0.2, sim},
};

struct animal X;
int i, j, k, l, M = N;
int C1[N], nC1;
int C2[N], nC2;
int C3[N], nC3;
int aux, cont=0;

int main()
{
    //Consulta
    system("cls");
    printf("Consulta ao banco de dados de animais: ");
    printf("\n(1)Consultar possiveis erros nas informacoes"); 
    printf("\n(2)Encerrar");
    printf("\nDigite: "); scanf("%d", &aux);
    system("cls");

    if(aux==1)
    {  
        //Analise 1 - Macho Mae ou Femea Pai de alguem?
        nC1 = 0;
        for (i=0; i<M; i++)
        {
            if( B[i].sexo == 1 )
            {
                for (j=0; j<M; j++)
                {
                    if( strncmp( B[j].mae, B[i].nome, strlen(B[j].mae) ) == 0 )
                    {
                        C1[nC1] = i;
                        nC1++;
                    }
                }
            }

            if( B[i].sexo == 2 )
            {
                for (j=0; j<M; j++)
                {
                    if( strncmp( B[j].pai, B[i].nome, strlen(B[j].pai) ) == 0 )
                    {
                        C1[nC1] = i;
                        nC1++;
                    }
                }
            }
        } 
        
        //Analise 2 - Pai ou Mae mais novo que filho?
        nC2 = 0;
        for (i=0; i<M; i++)
        { 
            for (j=0; j<M; j++)
            {
                if( strncmp( B[j].mae, B[i].nome, strlen(B[j].mae) ) == 0 ||
                    strncmp( B[j].pai, B[i].nome, strlen(B[j].pai) ) == 0 
                  )
                {
                    if( B[i].idade < B[j].idade)
                    {
                        C2[nC2] = i;
                        nC2++;
                    }
                    else if(B[i].idade == B[j].idade && B[i].meses <= B[j].meses)
                    {
                        C2[nC2] = i;
                        nC2++;      
                    }
                }
            }
        }        

        //Analise 3 - Pai ou Mae de especie diferente?
        nC3 = 0;
        for (i=0; i<M; i++)
        {
            if( B[i].sexo == 1 )
            {
                for (j=0; j<M; j++)
                {
                    if( strncmp( B[j].pai, B[i].nome, strlen(B[j].pai) ) == 0 &&
                        B[i].tipo != B[j].tipo
                      )
                    {
                        C3[nC3] = i;
                        nC3++;
                    }
                }
            }

            if( B[i].sexo == 2 )
            {
                for (j=0; j<M; j++)
                {
                    if( strncmp( B[j].mae, B[i].nome, strlen(B[j].mae) ) == 0 &&
                        B[i].tipo != B[j].tipo
                    )
                    {
                        C3[nC3] = i;
                        nC3++;
                    }
                }
            }
        }

        //Remover repeticoes 1
        for (i=0; i<nC1; i++)
        {
            k = C1[i];
            for (j=i+1; j<nC1; j++)
            {
                l = C1[j];
                if(strncmp(B[l].nome, B[k].nome, strlen(B[l].nome)) == 0)
                {
                    C1[j] = -1;
                }
            }
        }

        //Remover repeticoes 2
        for (i=0; i<nC2; i++)
        {
            k = C2[i];
            for (j=i+1; j<nC2; j++)
            {
                l = C2[j];
                if(strncmp(B[l].nome, B[k].nome, strlen(B[l].nome)) == 0)
                {
                    C2[j] = -1;
                }
            }
        }

        //Remover repeticoes 3
        for (i=0; i<nC3; i++)
        {
            k = C3[i];
            for (j=i+1; j<nC3; j++)
            {
                l = C3[j];
                if(strncmp(B[l].nome, B[k].nome, strlen(B[l].nome)) == 0)
                {
                    C3[j] = -1;
                }
            }
        }

        //Resultados
        printf("Resultados da consulta:\n\n");

        //Resultados da Analise 1
        for (j=0; j<nC1; j++)
        {
            if(C1[j]>=0)
            {
                i=C1[j];
                if(B[i].sexo==1)
                {
                    printf("Problema no cadastro: \n");
                    printf("Animal Macho cadastrado como 'Mae'\n\n");
                    printf("Nome: %-10s %*c", B[i].nome, 4, ' ');
                    printf("Dono: %-10s\n", B[i].dono);
                    printf("Tipo: %d %*c", B[i].tipo, 13, ' ');
                    printf("Sexo: M %*c\n\n");
                    printf("\n");
                }
                else if(B[i].sexo==2)
                {
                    printf("Problema no cadastro: \n");
                    printf("Animal Femea cadastrado como 'Pai'\n\n");
                    printf("Nome: %-10s %*c", B[i].nome, 4, ' ');
                    printf("Dono: %-10s\n", B[i].dono);
                    printf("Tipo: %d %*c", B[i].tipo, 13, ' ');
                    printf("Sexo: F\n\n");
                    printf("\n");               
                }
            }
        }

        //Resultados da Analise 2
        for (j=0; j<nC2; j++)
        {
            if(C2[j]>=0)
            {
                i=C2[j];
                if(B[i].sexo==1)
                {
                    printf("Problema no cadastro: \n");
                    printf("Animal mais novo cadastrado como pai de um mais velho.\n\n");
                    printf("Nome: %-10s %*c", B[i].nome, 4, ' ');
                    printf("Dono: %-10s\n", B[i].dono);
                    printf("Tipo: %d %*c", B[i].tipo, 13, ' ');
                    printf("Sexo: M %*c\n\n");
                    printf("Idade: %d A e %d M\n", B[i].idade, B[i].meses);
                    printf("\n");
                }
                else if(B[i].sexo==2)
                {
                    printf("Problema no cadastro: \n");
                    printf("Animal mais novo cadastrado como mae de um mais velho.\n\n");
                    printf("Nome: %-10s %*c", B[i].nome, 4, ' ');
                    printf("Dono: %-10s\n", B[i].dono);
                    printf("Tipo: %d %*c", B[i].tipo, 13, ' ');
                    printf("Sexo: F\n\n");
                    printf("Idade: %d A e %d M\n", B[i].idade, B[i].meses);
                    printf("\n");               
                }
            }
        }

        //Resultados da Analise 3
        for (j=0; j<nC3; j++)
        {
            if(C3[j]>=0)
            {
                i=C3[j];
                if(B[i].sexo==1)
                {
                    printf("Problema no cadastro: \n");
                    printf("Animal cadastrado como pai de uma especie diferente.\n\n");
                    printf("Nome: %-10s %*c", B[i].nome, 4, ' ');
                    printf("Dono: %-10s\n", B[i].dono);
                    printf("Tipo: %d %*c", B[i].tipo, 13, ' ');
                    printf("Sexo: M %*c\n\n");
                    printf("\n");
                }
                else if(B[i].sexo==2)
                {
                    printf("Problema no cadastro: \n");
                    printf("Animal cadastrado como mae de uma especie diferente.\n\n");
                    printf("Nome: %-10s %*c", B[i].nome, 4, ' ');
                    printf("Dono: %-10s\n", B[i].dono);
                    printf("Tipo: %d %*c", B[i].tipo, 13, ' ');
                    printf("Sexo: F\n\n");
                    printf("\n");               
                }
            }
        }

        if(nC1==0 && nC2==0 && nC3==0)
        {
            printf("Nenhum problema de cadastro encontrado.\n\n");
        }
    }

    return 0;
}