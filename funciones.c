#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include <ctype.h>

void mostrarLogo() {
    printf("\033[33m");  // Color amarillo
    printf(" _____                                                                                       _____ \n");
    printf("( ___ )-------------------------------------------------------------------------------------( ___ )\n");
    printf("\033[0m\033[37m"); 
    printf(" |   |     '########::::'###::::'########::'########::::'###::::::'##'##::::'#######::::     |   | \n");
    printf(" |   |     ... ##..::::'## ##::: ##.... ##: ##.....::::'## ##::::: ## ##:::'##.... ##:::     |   | \n");
    printf(" |   |     ::: ##:::::'##:. ##:: ##:::: ##: ##::::::::'##:. ##::'#########:..::::: ##:::     |   | \n");
    printf(" |   |     ::: ##::::'##:::. ##: ########:: ######:::'##:::. ##:.. ## ##.:::'#######::::     |   | \n");
    printf(" |   |     ::: ##:::: #########: ##.. ##::: ##...:::: #########:'#########:'##::::::::::     |   | \n");
    printf(" |   |     ::: ##:::: ##.... ##: ##::. ##:: ##::::::: ##.... ##:.. ## ##.:: ##::::::::::     |   | \n");
    printf(" |   |     ::: ##:::: ##:::: ##: ##:::. ##: ########: ##:::: ##::: ## ##::: #########:::     |   | \n");
    printf(" |   |     :::..:::::..:::::..::..:::::..::........::..:::::..::::..:..::::.........::::     |   | \n");
    printf(" |   |     '########:'####:'########:'##::: ##:'########:::::'###::::::::::'######::         |   | \n");
    printf(" |   |     ... ##..::. ##:: ##.....:: ###:: ##: ##.... ##:::'## ##::::::::'##... ##:         |   | \n");
    printf(" |   |     ::: ##::::: ##:: ##::::::: ####: ##: ##:::: ##::'##:. ##::::::: ##:::..::         |   | \n");
    printf(" |   |     ::: ##::::: ##:: ######::: ## ## ##: ##:::: ##:'##:::. ##:::::: ##:::::::         |   | \n");
    printf(" |   |     ::: ##::::: ##:: ##...:::: ##. ####: ##:::: ##: #########:::::: ##:::::::         |   | \n");
    printf(" |   |     ::: ##::::: ##:: ##::::::: ##:. ###: ##:::: ##: ##.... ##:'###: ##::: ##:         |   | \n");
    printf(" |   |     ::: ##::::'####: ########: ##::. ##: ########:: ##:::: ##: ###:. ######::         |   | \n");
    printf(" |   |     :::..:::::....::........::..::::..::........:::..:::::..::...:::......:::         |   | \n");
    printf("\033[33m");
    printf("(_____)-------------------------------------------------------------------------------------(_____\n");
    printf("\033[0m");  
}

void mostrarMenu() {
    printf("\n");
    printf("**********************************************************\n");
    printf("*              Que quiere hacer?                         *\n");
    printf("* 1) Agregar un nuevo producto                           *\n");
    printf("* 2) Buscar un producto                                  *\n");
    printf("* 3) Conocer el precio mas alto                          *\n");
    printf("* 4) Conocer el precio mas bajo                          *\n");
    printf("* 5) Mostrar todos los productos (A-Z)                   *\n");
    printf("* 6) Mostrar todos los productos (mas caro a mas barato) *\n");
    printf("* 7) Salir                                               *\n");
    printf("**********************************************************\n");
}

int esNombreValido(const char *nombre) {
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!isalpha(nombre[i]) && nombre[i] != ' ') { 
            return 0; 
        }
    }
    return 1; 
}

int esPrecioValido(float precio) {
    return precio >= 0; 
}

int ingresarProductos(char nombres[][30], float precios[], int numProductos) {
    int nuevosProductos;
    printf("¿Cuántos productos desea agregar (máx %d)? ", MAX_PRODUCTS - numProductos);
    scanf("%d", &nuevosProductos);

    if (numProductos + nuevosProductos > MAX_PRODUCTS) {
        printf("No se pueden agregar más de %d productos.\n", MAX_PRODUCTS);
        nuevosProductos = MAX_PRODUCTS - numProductos;
    }

    for (int i = numProductos; i < numProductos + nuevosProductos; i++) {
        do {
            printf("Ingrese el nombre del producto %d: ", i + 1);
            scanf(" %[^\n]", nombres[i]);
        } while (!esNombreValido(nombres[i]));

        do {
            printf("Ingrese el precio del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
        } while (!esPrecioValido(precios[i]));
    }

    return numProductos + nuevosProductos;
}


void imprimirTabla(char nombres[][30], float precios[], int numProductos) {
    printf("\n%-5s | %-30s | %-10s\n", "ID", "Nombre", "Valor ($)");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < numProductos; i++) {
        printf("%-5d | %-30s | $ %-9.2f\n", i + 1, nombres[i], precios[i]);
    }

    printf("-----------------------------------------------------------\n");
}

void buscarProducto(char nombres[][30], float precios[], int numProductos) {
    char nombreBuscado[30];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%s", nombreBuscado);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("\nProducto encontrado:\n");
            imprimirTabla(nombres, precios, 1);  // Mostrar solo el producto encontrado
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

const char* productoMasCaro(char nombres[][30], float precios[], int numProductos) {
    int indiceMax = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indiceMax]) {
            indiceMax = i;
        }
    }
    return nombres[indiceMax];
}

const char* productoMasBarato(char nombres[][30], float precios[], int numProductos) {
    int indiceMin = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] < precios[indiceMin]) {
            indiceMin = i;
        }
    }
    return nombres[indiceMin];
}

void ordenarAlfabeticamente(char nombres[][30], float precios[], int numProductos) {
    for (int i = 0; i < numProductos - 1; i++) {
        for (int j = i + 1; j < numProductos; j++) {
            if (strcmp(nombres[i], nombres[j]) > 0) {
                // Intercambiar nombres
                char tempNombre[30];
                float tempPrecio;

                strcpy(tempNombre, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], tempNombre);

                // Intercambiar precios
                tempPrecio = precios[i];
                precios[i] = precios[j];
                precios[j] = tempPrecio;
            }
        }
    }
}

void ordenarPorPrecio(char nombres[][30], float precios[], int numProductos) {
    for (int i = 0; i < numProductos - 1; i++) {
        for (int j = i + 1; j < numProductos; j++) {
            if (precios[i] < precios[j]) {
                // Intercambiar nombres
                char tempNombre[30];
                float tempPrecio;

                strcpy(tempNombre, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], tempNombre);

                // Intercambiar precios
                tempPrecio = precios[i];
                precios[i] = precios[j];
                precios[j] = tempPrecio;
            }
        }
    }
}
