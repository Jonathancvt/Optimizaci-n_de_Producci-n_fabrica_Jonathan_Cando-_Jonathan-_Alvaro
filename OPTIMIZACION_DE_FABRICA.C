
#include <stdio.h>
#include <stdlib.h>

#define PRODUCTOS 5

// Prototipos de funciones
void leerDemandas(int *demanda, int cantidad);
void mostrarDemandas(int *demanda, int cantidad);
float calcularTiempo(int *demanda, float *tiempos, int cantidad);
int calcularRecursos(int *demanda, int *recursos, int cantidad);
void verificarProduccion(float tiempoTotal, int recursosTotal,
                         float tiempoDisponible, int recursosDisponibles);

int main()
{
    int demanda[PRODUCTOS];

    // Tiempo de fabricacion por producto
    float tiempos[PRODUCTOS] = {2, 3, 1, 2, 4};

    // Recursos necesarios por producto
    int recursos[PRODUCTOS] = {3, 2, 4, 2, 3};

    float tiempoTotal;
    int recursosTotal;

    float tiempoDisponible;
    int recursosDisponibles;

    printf("=== SISTEMA DE PRODUCCION DE FABRICA ===\n");

    // Ingresar las demandas
    leerDemandas(demanda, PRODUCTOS);

    // Mostrar las demandas
    mostrarDemandas(demanda, PRODUCTOS);

    // Calcular tiempo y recursos
    tiempoTotal = calcularTiempo(demanda, tiempos, PRODUCTOS);

    recursosTotal = calcularRecursos(demanda, recursos, PRODUCTOS);

    // Ingresar limites disponibles
    printf("\nIngrese el tiempo disponible en horas: ");
    scanf("%f", &tiempoDisponible);

    printf("Ingrese los recursos disponibles: ");
    scanf("%d", &recursosDisponibles);

    // Mostrar resultados
    printf("\n======= RESULTADOS =======\n");

    printf("Tiempo total de fabricacion: %.2f horas\n", tiempoTotal);

    printf("Cantidad de recursos necesarios: %d\n", recursosTotal);

    // Verificar si se puede cumplir la demanda
    verificarProduccion(tiempoTotal, recursosTotal,
                        tiempoDisponible, recursosDisponibles);

    return 0;
}

// Funcion para ingresar las demandas
void leerDemandas(int *demanda, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nIngrese la demanda del producto %d: ", i + 1);
        scanf("%d", demanda + i);

        while (*(demanda + i) < 0)
        {
            printf("Ingrese una cantidad positiva: ");
            scanf("%d", demanda + i);
        }
    }
}

// Funcion para mostrar las demandas
void mostrarDemandas(int *demanda, int cantidad)
{
    printf("\n------- DEMANDAS -------\n");

    for (int i = 0; i < cantidad; i++)
    {
        printf("Producto %d: %d unidades\n", i + 1, *(demanda + i));
    }

    printf("------------------------\n");
}

// Funcion para calcular el tiempo total
float calcularTiempo(int *demanda, float *tiempos, int cantidad)
{
    float total = 0;

    for (int i = 0; i < cantidad; i++)
    {
        total += *(demanda + i) * *(tiempos + i);
    }

    return total;
}

// Funcion para calcular los recursos necesarios
int calcularRecursos(int *demanda, int *recursos, int cantidad)
{
    int total = 0;

    for (int i = 0; i < cantidad; i++)
    {
        total += *(demanda + i) * *(recursos + i);
    }

    return total;
}

// Funcion para verificar la produccion
void verificarProduccion(float tiempoTotal, int recursosTotal,
                         float tiempoDisponible, int recursosDisponibles)
{
    if (tiempoTotal <= tiempoDisponible &&
        recursosTotal <= recursosDisponibles)
    {
        printf("\nLA FABRICA PUEDE CUMPLIR CON LA DEMANDA.\n");
    }
    else
    {
        printf("\nLA FABRICA NO PUEDE CUMPLIR CON LA DEMANDA.\n");
    }

    if (tiempoTotal > tiempoDisponible)
    {
        printf("No hay suficiente tiempo disponible.\n");
    }

    if (recursosTotal > recursosDisponibles)
    {
        printf("No hay suficientes recursos disponibles.\n");
    }
}
