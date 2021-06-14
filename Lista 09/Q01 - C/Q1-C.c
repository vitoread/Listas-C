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
        {"Juquinha", "Bianca", "Caetano", "Pepeta", passarinho, macho, 1, 5, 0.5, nao_se_aplica},
        {"Biju", "Aninha", "Fumaca", "Anabela", gato, macho, 3, 1, 3.2, nao},
        {"Cuca", "Sra Silva", "desconhecido", "Dengosa", cobra, femea, 45, 3, 18.0, nao_se_aplica},
        {"Sansao", "Sr Luis", "Juquinha", "Anabela", cachorro, macho, 2, 9, 3.2, nao},
        {"Cuca", "Sr Silva", "desconhecido", "Fiona", peixe, macho, 1, 1, 0.2, nao_se_aplica},
        {"Boneca", "Zequinha", "Sansao", "Anabela", gato, femea, 1, 1, 0.2, sim},
        {"Pipoca", "Lalau", "Biju", "Catuta", cachorro, macho, 1, 1, 0.2, sim},
        {"Mosquito", "Lalau", "Sansao", "Boneca", cachorro, macho, 1, 1, 0.2, sim},
        {"Espeto", "Lalau", "Mosquito", "Catuta", cachorro, macho, 1, 1, 0.2, sim},
};

struct animal X;
int i, j, M = N;
int C[N], nC, aux;

int main()
{
    //Consulta
    system("cls");
    printf("Consulta ao banco de dados de animais: ");
    printf("\n(1)Consultar se existem mais cachorros com pulgas do que gatos com pulgas"); 
    printf("\n(2)Encerrar");
    printf("\nDigite: "); scanf("%d", &aux);
    system("cls");
    
    if(aux==1)
    {
        //Analise
        int contdog = 0;
        int contcat = 0;
        for (i=0; i<M; i++)
        {
            if  ( ( B[i].tipo == gato) && ( B[i].tem_pulgas == sim) )
            {
                contcat++;
            }
            if  ( ( B[i].tipo == cachorro) && ( B[i].tem_pulgas == sim) )
            {
                contdog++;
            }                        
        } 

        //Resultados
        printf("Resultados da consulta:\n");

        printf("\nNumero de cachorros com pulgas: %d\n", contdog);
        printf("Numero de gatos com pulgas: %d\n", contcat);
        printf("\nConclusao:\n");
        if(contdog>contcat) printf("\nExistem mais cachorros com pulgas do que gatos com pulgas.\n\n");
        else printf("\nNao existem mais cachorros com pulgas do que gatos com pulgas.\n\n");
    }
    return 0;
}