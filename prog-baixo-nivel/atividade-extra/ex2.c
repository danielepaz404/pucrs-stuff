#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int distancia_euclidiana(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void main () {
    int colunas = 0;
    int linhas = 0;
    int sementes = 0;

    // solicitar colunas x linhas
    printf("Informe o numero de colunas: ");
    scanf("%d", &colunas);

    printf("Informe o numero de linhas: ");
    scanf("%d", &linhas);

    // solicitar numero de sementes (regioes)
    printf("Informe o numero de sementes: ");
    scanf("%d", &sementes);

    char **matriz = (char**) malloc(linhas * sizeof(char *));

    // alocar dinamicamente
    for(int i = 0; i < linhas; i++){
        matriz[i] = (char*) malloc(colunas * sizeof(char));
        for(int j = 0; j < colunas; j++) {
            matriz[i][j] = '.';
        }
    };

    int** matriz_sementes = (int**) malloc(sementes * sizeof(int*));
    for(int i = 0; i < linhas; i++){
        matriz_sementes[i] = (int*) malloc(2 * sizeof(int));
        for(int j = 0; j < 2; j++) {
            matriz_sementes[i][j] = 0;
        }
    };

    // gerar randomicamente o mapeamento
    int rand_linha = 0;
    int rand_coluna = 0;
    int semente_i = 0;

    int* matriz_sementes_valores = (int*)malloc(sementes*sizeof(int));

    while (semente_i < sementes) {

        srand(time(NULL));
        rand_linha = rand() % linhas;
        rand_coluna = rand() % colunas;

        if(matriz[rand_linha][rand_coluna] == '.') {
            matriz[rand_linha][rand_coluna] = '0' + semente_i + 1;

            matriz_sementes_valores[semente_i] = semente_i + 1;

            matriz_sementes[semente_i] = (int*) malloc (2 * sizeof(int));
            matriz_sementes[semente_i][0] = rand_linha;
            matriz_sementes[semente_i][1] = rand_coluna;

            semente_i++;
        }
    };


    // imprimir o diagrama
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf(" %c ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Imprime sementes: \n");
    // imprimir posicao sementes
    for(int i = 0; i < sementes; i++) {
        for(int j = 0; j < 2; j++) {
            printf(" %d ", matriz_sementes[i][j]);
        }
        printf("\n");
    }

    // cria a matriz de distancia
    int *matriz_distancia = (int*) malloc(sementes*((linhas * colunas) - sementes) * sizeof(int));
    for(int i = 0; i < linhas; i++){
        matriz_distancia[i] = 0;
    }

    int valor = 0;

    // calcula a distancia para cada ponto
    for(int i = 0; i < linhas; i++) {
        printf("Imprime distancia euclidiana: \n");
        for(int j = 0; j < colunas; j++) {
            for(int k = 0; k < sementes; k++) {
                matriz_distancia[k] = distancia_euclidiana(i, j, matriz_sementes[k][0], matriz_sementes[k][1]);
                printf(" %d ", matriz_distancia[k]);
            }

            if(matriz[i][j] == '.') {
                int menor_distancia = linhas * colunas;

                for(int k = 0; k < sementes; k++) {
                    if(matriz_distancia[k] < menor_distancia) {
                        menor_distancia = matriz_distancia[k];
                        valor = matriz_sementes_valores[k];
                    }
                }
                matriz[i][j] = '0' + valor;
            }
        }
        printf("\n");
    }

     // imprimir o diagrama
    printf("\n");
    for(int i = 0; i < linhas; i++) {

        for(int j = 0; j < colunas; j++) {
            printf(" %c ", matriz[i][j]);
        }

        printf("\n");
    }
}