// Link al repositorio https://github.com/MartinMaximilianoMonnittola/tp6_info1
// legajo 422342
// Martin Monnittola

#include <stdio.h>
#define PI 3.141592653589793
#define RECTANGULO 1
#define CIRCULO 2

float calcularAreaRectangulo(float lado_1, float lado_2) {
    return lado_1 * lado_2;
}

float calcularPerimetroRectangulo(
                                  float longitud, 
                                  float altura
){
    return 2 * longitud + 2 * altura;
}

float calcularAreaCirculo(float radio) {
    return 2 * PI * radio * radio;
}

float calcularPerimetroCirculo(float radio) {
    return 2 * PI * radio;
}

void imprimirResultados(int opcion, float area, float perimetro) {
    switch (opcion) {
        case RECTANGULO:
            printf("El área del rectángulo es: %.2f\n", area);
            printf("El perimetro del rectángulo es: %.2f\n\n", perimetro);
            break;
        case CIRCULO:
            printf("El área del circulo es: %.2f\n", area);
            printf("El perimetro del circulo es: %.2f\n\n", perimetro);
            break;
        default :
            printf("Opcion no valida\n");
    }
}

void ingreso_de_valores(
              int opcion, 
              float *longitud_1, 
              float *longitud_2
){
    float long_1 = 0;
    float long_2 = 0;
    switch (opcion) {
        case RECTANGULO:
            while (long_1 <= 0)
            {
                printf("Ingrese la longuitud del rectángulo\n");
                scanf("%f", &long_1);

                if (long_1 <= 0) printf("La longuitud ingresada es incorrecta\n");
            }
            *longitud_1 = long_1;

            while (long_2 <= 0)
            {
                printf("Ingrese la altura del rectángulo\n");
                scanf("%f", &long_2);

                if (long_2 <= 0) printf("La altura ingresada es incorrecta\n");
            }
            *longitud_2 = long_2;
            break;
        case CIRCULO:
            while (long_1 <= 0)
            {
                printf("Ingrese el radio del Circulo\n");
                scanf("%f", &long_1);

                if (long_1 <= 0) printf("El radio ingresado es incorrecta\n");
            }
            *longitud_1 = long_1;
            break;
        default :
            break;
    }
}

void calculo(
              int opcion, 
              float longitud_1,
              float longitud_2,
              float *area,
              float *perimetro
){
    switch (opcion) {
        case RECTANGULO:
            if (longitud_1 > 0 && longitud_2 > 0) {
                *area = calcularAreaRectangulo(longitud_1, longitud_2);
                *perimetro = calcularPerimetroRectangulo(longitud_1, longitud_2); 
            }
            break;
        case CIRCULO:
            if (longitud_1 > 0) {
                *area = calcularAreaCirculo(longitud_1);
                *perimetro = calcularPerimetroCirculo(longitud_1); 
            }
            break;
        default :
            break;
    }
}

int main()
{
    int opcion = 0;
    float longitud_1 = 0;
    float longitud_2 = 0;
    float area;
    float perimetro;

    while (opcion != 1 && opcion != 2)
    {
        printf("Ingrese la figura que desea calcular\n");
        scanf("%d", &opcion);

        if (opcion != 1 && opcion != 2) printf("La opcion ingresada es incorrecta\n");
    }

    ingreso_de_valores(opcion, &longitud_1, &longitud_2);
    calculo(opcion, longitud_1, longitud_2, &area, &perimetro);
    imprimirResultados(opcion, area, perimetro);

    return 0;
}