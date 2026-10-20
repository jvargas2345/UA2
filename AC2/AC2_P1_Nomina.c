
//Sistema de caclulo de nomina (AC2_PI_Nomina)
/*Que se logra:Calcular el salario neto y mostrar un comprobante.

Como se logra:Solicitando el nombre y el salario, validando los datos
y calculando los descuentos correspondientes.

Resultado esperado:Mostrar el salario bruto, los descuentos y el salario neto
con dos decimales.*/


//BIBLIOTECAS

#include <stdio.h>
#include <string.h>

//CONSTANTES A UTILIZAR
#define CAJA 0.095
#define IESS 0.025
#define RENTA 0.10
#define LIMITE 800.0

int main() {
//Variables a usar caracter para nombre y double para que venga de forma decimal
    char nombre[100];
    double salarioBruto, caja, iess, renta, neto, total;

    //DATOS DE ENTRADA

    // Pedir el nombre
    do {
        printf("Ingrese el nombre completo: ");
        fgets(nombre, 100, stdin);

        nombre[strlen(nombre) - 1] = '\0';

        if (strlen(nombre) == 0) {
            printf("El nombre no puede estar vacio.\n");
        }

    } while (strlen(nombre) == 0);

    // Pedir el salario
    do {
        printf("Ingrese el salario bruto: ");
        scanf("%lf", &salarioBruto);

        if (salarioBruto <= 0) {
            printf("El salario debe ser mayor que cero.\n");
        }

    } while (salarioBruto <= 0);

    // Calcular descuentos
    caja = salarioBruto * CAJA;
    iess = salarioBruto * IESS;

    if (salarioBruto > LIMITE) {
        renta = salarioBruto * RENTA;
    } else {
        renta = 0;
    }

    // Calcular salario neto
    total = caja + iess + renta;
    neto = salarioBruto - total;

    // Muesta de comprobante (Salida)
    printf("\n========== COMPROBANTE ==========\n");
    printf("Empleado: %s\n", nombre);
    printf("---------------------------------\n");
    printf("%-20s %10.2f\n", "Salario bruto:", salarioBruto);
    printf("%-20s %10.2f\n", "Descuento CAJA:", caja);
    printf("%-20s %10.2f\n", "Descuento IESS:", iess);
    printf("%-20s %10.2f\n", "Descuento renta:", renta);
    printf("---------------------------------\n");
    printf("%-20s %10.2f\n", "Total descuentos:", total);
    printf("%-20s %10.2f\n", "Salario neto:", neto);
    printf("=================================\n");

    return 0;
}
