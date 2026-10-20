//VALIDACION DE CALIFICACIONES ESTUDIANTES (AC2_P2_Califacaciones)
/*
Que se logra: Obtener el promedio, la nota maxima y saber si el estudiante esta aprobado, en riesgo o no aprobado.

Como se logra: Se solicita el nombre y tres calificaciones, despues se valida que cada nota este entre 0 y 100 y 
se guardan las notas en un arreglo y se recorren con for para calcular el promedio y encontrar la nota mas alta.

Resultado esperado: Mostrar el nombre, las tres notas, el promedio, la nota mas alta y la condicion final.*/

//BIBLIOTECAS
#include <stdio.h>
#include <string.h>

//CONSTANTES DE NOTAS
#define MINIMO 0
#define MAXIMO 100
#define APROBACION 70
#define RIESGO 60

int main() {

    char nombre[100];
    float notas[3];
    float suma = 0, promedio, mayor;
    char condicion[20];
    int i;

//datos de entrada

    // Solicitar el nombre
    printf("Ingrese el nombre completo del estudiante: ");
    fgets(nombre, 100, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    // Solicitar y validar las tres notas
    for (i = 0; i < 3; i++) {

        do {
            printf("Ingrese la calificacion %d (0 a 100): ", i + 1);
            scanf("%f", &notas[i]);

            if (notas[i] < MINIMO || notas[i] > MAXIMO) {
                printf("Error: la nota debe estar entre 0 y 100.\n");
            }

        } while (notas[i] < MINIMO || notas[i] > MAXIMO);

    }

    // Calcular la suma de las notas
    for (i = 0; i < 3; i++) {
        suma = suma + notas[i];
    }

    // Calcular el promedio
    promedio = suma / 3;

    // Buscar la nota mas alta
    mayor = notas[0];

    for (i = 1; i < 3; i++) {
        if (notas[i] > mayor) {
            mayor = notas[i];
        }
    }

    // Determinar la condicion del estudiante
    if (promedio >= APROBACION) {
        strcpy(condicion, "APROBADO");
    } else if (promedio >= RIESGO) {
        strcpy(condicion, "EN RIESGO");
    } else {
        strcpy(condicion, "NO APROBADO");
    }

    // Mostrar los resultados
    printf("\n======= RESULTADO ACADEMICO =======\n");
    printf("Estudiante: %s\n", nombre);
    printf("-----------------------------------\n");

    for (i = 0; i < 3; i++) {
        printf("Calificacion %d: %.2f\n", i + 1, notas[i]);
    }
    printf("-----------------------------------\n");
    printf("Promedio: %.2f\n", promedio);
    printf("Nota mas alta: %.2f\n", mayor);
    printf("Condicion: %s\n", condicion);
    printf("===================================\n");

    return 0;
}
