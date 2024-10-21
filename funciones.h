#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTS 100

void mostrarLogo();
void mostrarMenu();
int esNombreValido(const char *nombre);
int esPrecioValido(float precio);
int ingresarProductos(char nombres[][30], float precios[], int numProductos);
void buscarProducto(char nombres[][30], float precios[], int numProductos);
const char* productoMasCaro(char nombres[][30], float precios[], int numProductos);
const char* productoMasBarato(char nombres[][30], float precios[], int numProductos);
void ordenarAlfabeticamente(char nombres[][30], float precios[], int numProductos);
void ordenarPorPrecio(char nombres[][30], float precios[], int numProductos);
void imprimirTabla(char nombres[][30], float precios[], int numProductos);
int ingresarProductos(char nombres[][30], float precios[], int numProductos);


#endif
