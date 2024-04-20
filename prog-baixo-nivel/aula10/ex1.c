#include <stdio.h>

void main() {
    int segundos = 0;
    int minutos = 0;
    int horas = 0;

    int numeros[2] = {6,2};

    printf("Informe o tempo em segundos\n");
    scanf("%d", &segundos);

    if(segundos >= 60) {
        minutos = segundos / 60;
        segundos = segundos % 60;

        if(minutos >= 60) {
            horas = minutos / 60;
            minutos = minutos % 60; 
        }
    }

    printf("Horas: %d, Minutos: %d, Segundos: %d\n", horas, minutos, segundos);
}