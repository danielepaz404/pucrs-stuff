#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int R;
    int G;
    int B;
} Pixel;

Pixel **vetor;
int colunas = 0;
int linhas = 0;
int valor = 0;
char formato[2];

void escala_cinza(){
    FILE* fp_cinza = fopen("florzinha_cinza.ppm", "w");
    if(fp_cinza == NULL){
        printf("Erro ao criar o arquivo de escala cinza. \n");
        exit(1);
    }

    fprintf(fp_cinza, "P2\n");
    fprintf(fp_cinza, "%d %d\n", colunas, linhas);
    fprintf(fp_cinza, "%d\n", valor);

    int gray = 0;

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            gray = (int) (vetor[i][j].R * 0.3 + vetor[i][j].G * 0.59 + (int)vetor[i][j].B * 0.11);

            fprintf(fp_cinza, "%d ", gray);
        }

        fprintf(fp_cinza, "\n");
    }

    fclose(fp_cinza);
}

void negativa(){
    FILE* fp_negativa = fopen("florzinha_negativa.ppm", "w");
    if(fp_negativa == NULL){
        printf("Erro ao criar o arquivo com cores negativas. \n");
        exit(1);
    }

    fprintf(fp_negativa, "%s\n", formato);
    fprintf(fp_negativa, "%d %d\n", colunas, linhas);
    fprintf(fp_negativa, "%d\n", valor);

    int r, g, b;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            r = 255 - vetor[i][j].R;
            g = 255 - vetor[i][j].G;
            b = 255 - vetor[i][j].B;

            fprintf(fp_negativa, "%d %d %d ", r, g, b);
        }

        fprintf(fp_negativa, "\n");
    }

    fclose(fp_negativa);
}

void envelhecida(){
    FILE* fp_envelhecida = fopen("florzinha_envelhecida.ppm", "w");
    if(fp_envelhecida == NULL){
        printf("Erro ao criar o arquivo com cores envelhecidas. \n");
        exit(1);
    }

    fprintf(fp_envelhecida, "%s\n", formato);
    fprintf(fp_envelhecida, "%d %d\n", colunas, linhas);
    fprintf(fp_envelhecida, "%d\n", valor);

    int r, g, b;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            r = vetor[i][j].R >= 20 ? vetor[i][j].R - 20 : 0;
            g = vetor[i][j].G >= 20 ? vetor[i][j].G - 20 : 0;
            b = vetor[i][j].B >= 20 ? vetor[i][j].B - 20 : 0;

            fprintf(fp_envelhecida, "%d %d %d ", r, g, b);
        }

        fprintf(fp_envelhecida, "\n");
    }

    fclose(fp_envelhecida);
}

void rotacionada(){
    FILE* fp_rotacionada = fopen("florzinha_rotacionada.ppm", "w");
    if(fp_rotacionada == NULL){
        printf("Erro ao criar o arquivo rotacionado. \n");
        exit(1);
    }

    fprintf(fp_rotacionada,"%s\n", formato);
    fprintf(fp_rotacionada, "%d %d\n", colunas, linhas);
    fprintf(fp_rotacionada, "%d\n", valor);

    int r, g, b;
    for(int i = linhas - 1; i >= 0; i--) {
        for(int j = colunas - 1; j >= 0; j--) {
            r = vetor[colunas - 1 - j][i].R;
            g = vetor[colunas - 1 - j][i].G;
            b = vetor[colunas - 1 - j][i].B;

            fprintf(fp_rotacionada, "%d %d %d ", r, g, b);
        }

        fprintf(fp_rotacionada, "\n");
    }

    fclose(fp_rotacionada);
}

void aumentar_brilho(){
    FILE* fp_mais_brilho = fopen("florzinha_mais_brilho.ppm", "w");
    if(fp_mais_brilho == NULL){
        printf("Erro ao criar o arquivo com mais brilho. \n");
        exit(1);
    }

    fprintf(fp_mais_brilho, "%s\n", formato);
    fprintf(fp_mais_brilho, "%d %d\n", colunas, linhas);
    fprintf(fp_mais_brilho, "%d\n", valor);

    int r, g, b;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            r = vetor[i][j].R * 1.3 < 255 ? vetor[i][j].R * 1.3 : 255;
            g = vetor[i][j].G * 1.3 < 255 ? vetor[i][j].G * 1.3 : 255;
            b = vetor[i][j].B * 1.3 < 255 ? vetor[i][j].B * 1.3 : 255;

            fprintf(fp_mais_brilho, "%d %d %d ", r, g, b);
        }

        fprintf(fp_mais_brilho, "\n");
    }

    fclose(fp_mais_brilho);
}

void diminuir_brilho(){
    FILE* fp_menos_brilho = fopen("florzinha_menos_brilho.ppm", "w");
    if(fp_menos_brilho == NULL){
        printf("Erro ao criar o arquivo com menos brilho. \n");
        exit(1);
    }

    fprintf(fp_menos_brilho, "%s\n", formato);
    fprintf(fp_menos_brilho, "%d %d\n", colunas, linhas);
    fprintf(fp_menos_brilho, "%d\n", valor);

    int r, g, b;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            r = vetor[i][j].R * 0.7;
            g = vetor[i][j].G * 0.7;
            b = vetor[i][j].B * 0.7;

            fprintf(fp_menos_brilho, "%d %d %d ", r, g, b);
        }

        fprintf(fp_menos_brilho, "\n");
    }

    fclose(fp_menos_brilho);
}

void main() {
    char nome_imagem[30];

    printf("Qual o nome da image *.ppm?\n");
    scanf("%s", nome_imagem);

    strcat(nome_imagem, ".ppm");

    FILE *fp = fopen(nome_imagem, "r");

    // leitura do formato
    fscanf(fp, "%s", formato);

    // leitura do tamanho da imagem
    fscanf(fp, "%d %d", &colunas, &linhas);

    // leitura do valor maximo por pixel
    fscanf(fp, "%d", &valor);

    vetor = (Pixel**) malloc(colunas * linhas * sizeof(Pixel*));

    for(int i = 0; i < linhas; i++) {
        vetor[i] = (Pixel*) malloc(colunas * linhas * sizeof(Pixel));

        for(int j = 0; j < colunas; j++) {
            
            fscanf(fp, "%d %d %d", &vetor[i][j].R, &vetor[i][j].G, &vetor[i][j].B);
        }
    }

    fclose(fp);

    printf("Qual transformação vc deseja fazer?\n1) Gerar uma imagem tons de cinza;\n2) Imagem tons de cinza -  gerar imagem negativa;\n3) Imagem tons de cinza - aumentar o brilho;\n4) Imagem tons de cinza - diminuir o brilho;\n5) Rotacionar a imagem colorida – 90º;\n6) Imagem colorida - envelhecimento da imagem;\n");

    int escolha;
    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            escala_cinza();
            break;
        case 2:
            negativa();
            break;
        case 3:
            aumentar_brilho();
            break;
        case 4:
            diminuir_brilho();
            break;
        case 5:
            rotacionada();
            break;
        case 6:
            envelhecida();
            break;
    }

    for(int i = 0; i < linhas; i++) {
        free(vetor[i]);
    }

    free(vetor);

}