#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTS][30];
    float precios[MAX_PRODUCTS];
    int numProductos = 0;
    int opcion;

    mostrarLogo();  // Muestra el logo al inicio

    do {
        mostrarMenu();  // Muestra el menú
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                numProductos = ingresarProductos(nombres, precios, numProductos);
                break;
            case 2:
                buscarProducto(nombres, precios, numProductos);
                break;
            case 3:
                printf("Producto más caro: %s\n", productoMasCaro(nombres, precios, numProductos));
                break;
            case 4:
                printf("Producto más barato: %s\n", productoMasBarato(nombres, precios, numProductos));
                break;
            case 5:
                ordenarAlfabeticamente(nombres, precios, numProductos);
                imprimirTabla(nombres, precios, numProductos);
                break;
            case 6:
                ordenarPorPrecio(nombres, precios, numProductos);
                imprimirTabla(nombres, precios, numProductos);
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida, por favor intente de nuevo.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}
