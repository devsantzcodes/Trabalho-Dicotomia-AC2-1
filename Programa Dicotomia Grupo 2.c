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

    printf("Digite o grau da função: ");
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

    printf("\n\nVerificando se há zeros de função no intervalo citado");

    if (verificafuncao(&P, a, b) == 1)
    {
        printf("Existe zero de função nos intervalos indicados.");
    }
    else
    {
        printf("Não há zero da função nos intervalos indicados.");
    }

    // Boa pratica: liberar memoria e pausar no final
    free(P.coef);
    system("pause");
}

void alocaPolinomio(Polinomio *p, int grau)
{
    // Para grau N, precisamos de N+1 coeficientes (0 a N)
    p->coef = (float *)malloc((grau + 1) * sizeof(float));

    if (p->coef == NULL)
    {
        printf("ERRO NO CÓDIGO (ALOCAR MEMORIA)");
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
    float fa = calculofuncao(p, a);
    float fb = calculofuncao(p, b);

    printf("\n  f(%.2f) = %.4f", a, fa);
    printf("\n  f(%.2f) = %.4f\n", b, fb);

    // Se o produto for negativo, os sinais sao opostos -> Existe raiz
    if (fa * fb < 0)
        return 1; // Verdadeiro
    else
        return 0; // Falso
}
