#include <stdio.h>

#define MAX_ENTRIES 100

typedef struct
{
    char estado[3];
    char codigoCarta[3];
    char nomeCidade[50];
    long populacao;
    double area;
    double densidadePopulacional;
    double pib;
    double pibPerCapita;
    int numeroPontosTuristicos;
} Cidade;

void calcularDensidadePopulacional(Cidade *cidade)
{
    if (cidade->area > 0)
    {
        cidade->densidadePopulacional = cidade->populacao / cidade->area;
    }
    else
    {
        cidade->densidadePopulacional = 0;
    }
}

void calcularPibPerCapita(Cidade *cidade)
{
    if (cidade->populacao > 0)
    {
        cidade->pibPerCapita = cidade->pib / cidade->populacao;
    }
    else
    {
        cidade->pibPerCapita = 0;
    }
}

void adicionarCidade(Cidade cidades[], int *contador)
{
    if (*contador < MAX_ENTRIES)
    {
        Cidade novaCidade;

        printf("Digite o estado (sigla de 2 caracteres): ");
        scanf("%s", novaCidade.estado);

        printf("Digite o código da carta: ");
        scanf("%s", novaCidade.codigoCarta);

        printf("Digite o nome da cidade: ");
        scanf("%s", novaCidade.nomeCidade);

        printf("Digite a população: ");
        scanf("%ld", &novaCidade.populacao);

        printf("Digite a área: ");
        scanf("%lf", &novaCidade.area);

        printf("Digite o PIB: ");
        scanf("%lf", &novaCidade.pib);

        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &novaCidade.numeroPontosTuristicos);

        calcularDensidadePopulacional(&novaCidade);
        calcularPibPerCapita(&novaCidade);

        cidades[*contador] = novaCidade;
        (*contador)++;
    }
    else
    {
        printf("Limite de entradas atingido.\n");
    }
}

void listarCidades(Cidade cidades[], int contador)
{
    for (int i = 0; i < contador; i++)
    {
        printf("Estado: %s\n", cidades[i].estado);
        printf("Código da Carta: %s\n", cidades[i].codigoCarta);
        printf("Nome da Cidade: %s\n", cidades[i].nomeCidade);
        printf("População: %ld\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("Densidade Populacional: %.2f hab/km²\n", cidades[i].densidadePopulacional);
        printf("PIB: %.2f\n", cidades[i].pib);
        printf("PIB per Capita: %.2f\n", cidades[i].pibPerCapita);
        printf("Número de Pontos Turísticos: %d\n", cidades[i].numeroPontosTuristicos);
        printf("---------------\n");
    }
}

int main()
{
    Cidade cidades[MAX_ENTRIES];
    int contador = 0;
    int opcao;

    do
    {
        printf("Menu:\n");
        printf("1. Adicionar Cidade\n");
        printf("2. Listar Cidades\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarCidade(cidades, &contador);
            break;
        case 2:
            listarCidades(cidades, contador);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
