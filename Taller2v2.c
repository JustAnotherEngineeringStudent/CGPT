/*Este programa es para calcular cuanto hay que pagar de estacionamiento de en base del tiempo que se ha estado (Estoy cansado jefe)

Autor: Juan Pablo Araya
Fecha: 19-05-2025
btw cuando vaya a tirar el gcc tengo que usar (gcc taller2.c -std=c89 -o taller2)
*/
#include <stdio.h>

int terminar = 0, domingo;
float pagar;


int main(){
    while (terminar == 0){
        int hora_entrada, minuto_entrada, hora_salida, minuto_salida, total_entrada, total_salida, tiempo_estancia, calculopagar = 0;
        int repetir15 = 3, repetir60 = 0, inicio = 0;

        if (inicio == 0){
            printf("Si hoy es un dia domingo, ingrese 1 en caso de que no ingrese 0\n");
            scanf("%d", &domingo);
            printf("Ingrese la hora de entrada, primero la hora y luego el minuto separados por : (HH:MM)\n");
            scanf("%d:%d", &hora_entrada, &minuto_entrada);
            printf("Ingrese la hora de salida, primero la hora y luego el minuto (HH:MM)\n");
            scanf("%d:%d", &hora_salida, &minuto_salida);
            inicio = 1;
        }
        /* Ahora voy a calcular el tiempo que estuvo, paso primero las horas a minutos* */
        if (inicio == 1){
            total_entrada = (hora_entrada * 60) + minuto_entrada;
            total_salida = (hora_salida * 60) + minuto_salida;
            tiempo_estancia = total_salida - total_entrada;
            printf("El tiempo de estancia es %d minutos\n", tiempo_estancia);
            inicio = 2;
        }
        if (tiempo_estancia <= 10){
            printf("El tiempo de estancia es menor o igual a 10 minutos, no se paga nada\n");
            terminar = 1;
        } else {
            tiempo_estancia -= 10; // Descuento de los 10 minutos gratis
            pagar = 0;
            int bloques15 = tiempo_estancia / 15;
            if (bloques15 > 3) bloques15 = 3;
            pagar += bloques15 * 3;
            tiempo_estancia -= bloques15 * 15;
            if (bloques15 == 3) {
                if (tiempo_estancia >= 60) {
                    pagar += 10;
                    tiempo_estancia -= 60;
                    pagar += (tiempo_estancia / 60) * 5;
                }
            }
            printf("Total a pagar antes de descuento domingo: %.2f\n", pagar);
            terminar = 1;
        }
    }
    if (domingo == 1){
        printf("El total a pagar es: %.2f\n", pagar * 0.9);
    }
    else if (domingo == 0){
        printf("El total a pagar es: %.2f\n", pagar);
    }
    getchar();
    getchar();
    return 0;
}