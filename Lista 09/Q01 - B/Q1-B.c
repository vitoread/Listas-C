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
        {"Boneca", "Zequinha", "Sansao", "Anabela", gato, femea, 1, 6, 0.2, sim},
        {"Pipoca", "Lalau", "Biju", "Catuta", gato, macho, 1, 1, 0.2, sim},
        {"Mosquito", "Lalau", "Sansao", "Boneca", gato, macho, 2, 1, 0.2, sim},
        {"Espeto", "Lalau", "Mosquito", "Catuta", gato, macho, 1, 1, 0.2, sim},
};

struct animal X;
int i, j, M = N;
int C[N], nC, aux;

int main()
{
    //Consulta
    system("cls");
    printf("Consulta ao banco de dados de animais: ");
    printf("\n(1)Consultar o filho mais velho de Sansao, o gato"); 
    printf("\n(2)Encerrar");
    printf("\nDigite: "); scanf("%d", &aux);
    system("cls");

    if(aux==1)
    {
        //Analise
        nC = 0;
        int auxidade = 0;
        int auxmeses = 0;
        for (i=0; i<M; i++)
        {
            if( ( strncmp(B[i].pai, "Sansao", strlen(B[i].pai) ) == 0 ) && 
                ( B[i].tipo == gato) &&
                ( B[i].idade >= auxidade )             
              )
            {
                if(B[i].idade == auxidade && B[i].meses>auxmeses )
                {
                    auxmeses = B[i].meses;
                    auxidade = B[i].idade;
                    C[nC] = i;     
                }
                else
                {
                    auxmeses = B[i].meses;
                    auxidade = B[i].idade;
                    C[nC] = i;
                }
            }
        } 

        //Resultados
        printf("Resultados da consulta:\n");

        i=C[j];
        printf("Nome: %-10s %*c", B[i].nome, 4, ' ');
        printf("Dono: %-10s\n", B[i].dono);
        printf("Pai: %-10s %*c", B[i].pai, 5, ' ');
        printf("Mae: %-10s\n", B[i].mae);
        printf("Tipo: %d\n", B[i].tipo);
        if(B[i].sexo==1) printf("Sexo: M %*c", 13, ' ');
        else printf("Sexo: F %*c", 13, ' ');
        printf("Peso: %2.2f\n", B[i].peso);
        printf("Idade: %d A e %d M\n", B[i].idade, B[i].meses);
        if(B[i].tem_pulgas==1) printf("Tem pulgas: Sim\n");
        else if(B[i].tem_pulgas==2) printf("Tem pulgas: Nao\n");
        else printf("Tem pulgas: ---\n");
        printf("\n");

    }
    return 0;
}