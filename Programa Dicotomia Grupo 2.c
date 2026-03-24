#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura para representar o polinomio e seus coeficientes
typedef struct
{
    int grau;
    float *coef;
} Polinomio;

void alocaPolinomio(Polinomio *p, int grau);
float calculofuncao(Polinomio *p, float x);
int verificafuncao(Polinomio *p, float a, float b); // vai verificar se existe zero de função no intervalo indicado.

int main()
{
    Polinomio P; // Instancia da struct
    int i;       // Variável para loop
    float a, b;  // Intervalos da função;

    printf("Digite o grau da funssaum: ");
    scanf("%i", &P.grau);

    printf("\n");
    // Aloca memoria para os coeficientes na struct
    alocaPolinomio(&P, P.grau);

    for (i = P.grau; i >= 0; i--)
    {
        printf("Digite o (x^%i) valor : ", i);
        printf("\n");
        scanf("%f", &P.coef[i]);
    }

    printf("\n");

    printf("Digite o intervalo a: ");
    scanf("%f", &a);

    printf("\n");

    printf("Digite o intervalo b: ");
    scanf("%f", &b);

    printf("\n\nVerificando se ha zeros de funssaum no intervalo citado");

    int qtd = verificafuncao(&P, a, b);

    if (qtd > 0)
    {
        printf("\nExiste(m) %d zero(s) da funcao no intervalo.", qtd);
    }
    else
    {
        printf("\nNao ha zero da funcao no intervalo.");
    }

    // Boa pratica: liberar memoria e pausar no final
    free(P.coef);
    system("pause");
}

void alocaPolinomio(Polinomio *p, int grau)
{
    p->coef = NULL;
    // Para grau N, precisamos de N+1 coeficientes (0 a N)
    p->coef = realloc(p->coef, (grau + 1) * sizeof(float));

    if (p->coef == NULL)
    {
        printf("ERRO NO CODIGO (ALOCAR MEMORIA)");
        system("pause");
        exit(1);
    }
}

float calculofuncao(Polinomio *p, float x)
{
    int i;
    float resultado = 0;

    // Realiza o somatório: c0*x^0 + c1*x^1 + ...
    for (i = 0; i <= p->grau; i++)
    {
        resultado += p->coef[i] * pow(x, i);
    }

    return resultado;
}

int verificafuncao(Polinomio *p, float a, float b)
{
    float passo = 0.1;
    float x;
    int contador = 0;

    for (x = a; x < b; x += passo)
    {
        float proximo = x + passo;
        if (proximo > b)
            proximo = b;

        float fx1 = calculofuncao(p, x);
        float fx2 = calculofuncao(p, proximo);

        if (fabs(fx1) < 0.0001)
        {
            printf("\nRaiz aproximada em x = %.2f\n", x);
            contador++;
        }
        else if (fx1 * fx2 < 0)
        {
            printf("\nRaiz entre %.2f e %.2f\n", x, proximo);
            contador++;
        }
    }

    return contador;
}
