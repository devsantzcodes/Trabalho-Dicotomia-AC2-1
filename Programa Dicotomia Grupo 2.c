#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void alocaincognita(int grau, float **incognita);
float calculofuncao(float *incognita, int grau, float intervalo);
void alocasoma(int grau, float **soma);
int verificafuncao(float a, float b, float *incognita, int grau); //vai verificar se existe zero de função no intervalo indicado.

int main(){
    int g; //Variável referente ao grau da função.
    int i; // Variável para loop
    float *incognita = NULL;  //Variável para armazenar as incógnitas de cada grau da função.
    float a,b; //Intervalos da função;


    printf("Digite o grau da função: ");
    scanf("%i", &g);


    printf("\n");
    alocaincognita(g, &incognita);

    for(i=g;i>=0;i--){
        printf("Digite o (x^%i) valor : ", i);
        printf("\n");
        scanf("%f", (incognita+i));
    }

    printf("\n");

    printf("Digite o intervalo a");
    scanf("%f", &a);

    printf("\n");

    printf("Digite o intervalo b");
    scanf("%f", &b);

    printf("\n\nVerificando se há zeros de função no intervalo citado");


    if(verificafuncao(a, b, incognita, g) == 0){
        printf("Existe zero de função nos intervalos indicados.");
        system("pause");
    }else{
        printf("Não há zero da função nos intervalos indicados.");
    }
}

void alocaincognita(int grau, float **incognita){
    *incognita = (float*) realloc(*incognita, grau*sizeof(float));

    if(*incognita == NULL){
        printf("ERRO NO CÓDIGO (ALOCAR INCOGNITA)");
        system("pause");
        exit(1);
    }
}

void alocasoma(int grau, float **soma){
    *soma = (float*) realloc(*soma, grau*sizeof(float));

    if(*soma == NULL){
        printf("ERRO NO CÓDIGO (ALOCAR INCOGNITA)");
        system("pause");
        exit(1);
    }
}

float calculofuncao(float *incognita, int grau, float intervalo){
    int i;
    float *soma; //Somar cada grau da função
    float total=0;

    alocasoma(grau ,&soma);

    for(i=0;i<grau;i++){
        *(soma+i) = (intervalo+i)*pow(intervalo,i);//Vai realizar o cálculo do valor junto a incógnita e armazená-lo ao vetor soma em sua respectiva posição.
    }

    for(i=grau;i>=0; i++){
        total += *(soma+i);//Vai somar cada grau da função.
    }

    return total;
}

int verificafuncao(float a, float b, float *incognita, int grau){
    int verifica;

    if((calculofuncao(incognita,grau, a))*(calculofuncao(incognita,grau,b)) < 0)
        verifica=0;
    else
        verifica = -1;
}

