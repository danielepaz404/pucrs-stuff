#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main () {
    int colunas, linhas, sementes;

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

    // gerar randomicamente o mapeamento
    int rand_linha, rand_coluna;
    int semente_i = 0;
    while (semente_i < sementes) {

        srand(time(NULL));
        rand_linha = rand() % linhas;
        rand_coluna = rand() % colunas;

        if(matriz[rand_linha][rand_coluna] == '.') {
            matriz[rand_linha][rand_coluna] = '0' + semente_i + 1;

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
}