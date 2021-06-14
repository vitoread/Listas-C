#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 11

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
        {                                                                          },
        {"Boneca", "Sr Silva", "Bartolomeu", "Anabela", peixe, macho, 3, 8, 4.3, sim},
        {"Zive", "Bianca", "Caetano", "Pepeta", cobra, macho, 1, 5, 0.5, sim},
        {"Biju", "Aninha", "Fumaca", "Anabela", passarinho, macho, 3, 1, 3.2, nao},
        {"Bacana", "Sra Silva", "desconhecido", "Dengosa", gato, femea, 45, 3, 18.0, nao_se_aplica},
        {"Sansao", "Sr Luis", "Juquinha", "Anabela", gato, macho, 2, 9, 3.2, nao},
        {"Alexander", "Sr Silva", "desconhecido", "Fiona", gato, macho, 1, 1, 0.2, nao_se_aplica},
        {"Wagner", "Zequinha", "Sansao", "Anabela", cachorro, femea, 1, 1, 0.2, sim},
        {"Pipoca", "Lalau", "Biju", "Catuta", peixe, macho, 1, 1, 0.2, sim},
        {"Cascata", "Lalau", "Sansao", "Boneca", gato, macho, 1, 1, 0.2, sim},
        {"Valadao", "Lalau", "Mosquito", "Catuta", passarinho, macho, 1, 1, 0.2, sim},
};

struct animal X;
int i, j, k, l, M = N;
int C[N], nC;
int aux;

int main()
{
    //Consulta
    system("cls");
    printf("Consulta ao banco de dados de animais: ");
    printf("\n(1)Exibir toda a base de dados ordenada por tipo e em ordem alfabetica"); 
    printf("\n(2)Encerrar");
    printf("\nDigite: "); scanf("%d", &aux);
    system("cls");
    if(aux==1)
    {
        //Manipulacao por tipo
    	for(i=1; i<M; i++)
        {
            for(j=i+1;j<M;j++)
            {
                if(B[i].tipo > B[j].tipo )
                {
                    B[0]=B[i];
                    B[i]=B[j];
                    B[j]=B[0];
                }
            }
	    }  

        //Manipulacao por ordem alfabetica
    	for(i=1; i<M; i++)
        {
            for(j=i+1;j<M;j++)
            {
                if(B[i].tipo!=B[j].tipo)
                {
                    break;
                }
                if(strncmp(B[i].nome , B[j].nome, strlen(B[i].nome)) > 0 )
                {
                    B[0]=B[i];
                    B[i]=B[j];
                    B[j]=B[0];
                }
            }
	    }   
        //Resultados
        printf("Resultados da consulta:\n");
        for (j=1; j<M; j++)
        {
            printf("Nome: %-10s %*c", B[j].nome, 4, ' ');
            printf("Dono: %-10s\n", B[j].dono);
            printf("Pai: %-10s %*c", B[j].pai, 5, ' ');
            printf("Mae: %-10s\n", B[j].mae);
            if(B[j].tipo==1) printf("Tipo: Gato\n", B[j].tipo);
            else if(B[j].tipo==2) printf("Tipo: Cachorro\n");
            else if(B[j].tipo==3) printf("Tipo: Passarinho\n");
            else if(B[j].tipo==4) printf("Tipo: Fisch\n");
            else if(B[j].tipo==5) printf("Tipo: Cobra\n");
            if(B[j].sexo==1) printf("Sexo: M %*c", 13, ' ');
            else printf("Sexo: F %*c", 13, ' ');
            printf("Peso: %2.2f\n", B[j].peso);
            printf("Idade: %d A e %d M\n", B[j].idade, B[j].meses);
            if(B[j].tem_pulgas==1) printf("Tem pulgas: Sim\n");
            else if(B[j].tem_pulgas==2) printf("Tem pulgas: Nao\n");
            else printf("Tem pulgas: ---\n");
            printf("\n");
        }
    }
    return 0;
}