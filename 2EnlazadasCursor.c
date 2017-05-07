#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "structs.h"

#define NULO -1
#define LIBRE -2
//#define MAX_ARR 300


lista crearLista() {
    lista nueva;
    int i;
    for(i = 0; i < 8; i++) {
    nueva.arreglo[i].siguiente = LIBRE;
    }
    nueva.cabeza = NULO;
    nueva.fin = 0;
    return nueva;
}





int buscarLibre(lista actual) {
    int indice;
    for(indice = 0; indice < MAX_ARR; indice++) {
        if(actual.arreglo[indice].siguiente == LIBRE) {
            return indice;
        }
    }

    return NULO;
}

void mostrar(lista actual) {
    int indice = actual.cabeza;
    while(indice != NULO) {
        printf("%c ", actual.arreglo[indice].elemento);
        indice = actual.arreglo[indice].siguiente;
    }
    printf("\n");
}





lista insertar(lista actual,int elemento, int posicion)
{
    int auxiliar = actual.cabeza;
    int cuenta = 0;
	int posicionLibre = buscarLibre(actual);
    //int posicionLibre = posicion;
//    actual.arreglo[posicion].elemento = elemento;
    if(posicion<actual.fin)
    {
		actual.arreglo[posicion].elemento = elemento;
		
		
//		actual.arreglo[posicion].publi = calloc(sizeof(publicidad),1);
		
		
	}
    if(posicion < 0 || posicion > actual.fin || posicion > MAX_ARR) {
		printf("MAX ACTUAL\n");
        return actual;
    }
    if(posicionLibre == NULO) {
		//printf("TA NULO PAPI\n");
        return actual;
    }
    actual.arreglo[posicionLibre].elemento = elemento;
    if(posicion == 0) {
        actual.arreglo[posicionLibre].siguiente = actual.cabeza;
        actual.cabeza = posicionLibre;
        actual.fin++;
        return actual;
    }
    while(cuenta < posicion - 1)
    {
        auxiliar = actual.arreglo[auxiliar].siguiente;
        cuenta++;
    }
    actual.arreglo[posicionLibre].siguiente = actual.arreglo[auxiliar].siguiente;
    actual.arreglo[auxiliar].siguiente = posicionLibre;
    actual.fin++;
    return actual;
}
lista append(lista actual, int elemento)
{
	actual = insertar(actual, elemento, actual.fin);
	return actual;
}

int buscar(lista actual, int valor) {
    int indice = actual.cabeza;
    while(indice != NULO) {
        if(actual.arreglo[indice].elemento == valor) {
            return indice;
        }
        indice = actual.arreglo[indice].siguiente;
    }
    return NULO;
}


int obtener(lista actual, int posicion) {
    int cuenta = 0;
    int indice = actual.cabeza;
    if(posicion < 0 || posicion >= actual.fin) {
        return INT_MAX;
    }
    while(cuenta < posicion) {
        indice = actual.arreglo[indice].siguiente;
        cuenta++;
    }
    return actual.arreglo[indice].elemento;
}

lista borrar(lista actual, int posicion) {
    int cuenta = 0;
    int indice = actual.cabeza;
    int auxiliar;
    if(posicion < 0 || posicion >= actual.fin) {
        return actual;
    }
    if(posicion == 0) {
        actual.cabeza = actual.arreglo[indice].siguiente;
        actual.arreglo[indice].siguiente = LIBRE;
        actual.fin--;
    return actual;
    }
    while(cuenta < posicion - 1) {
        indice = actual.arreglo[indice].siguiente;
        cuenta++;
    }
    auxiliar = actual.arreglo[indice].siguiente;
    actual.arreglo[indice].siguiente = actual.arreglo[auxiliar].siguiente;
    actual.arreglo[auxiliar].siguiente = LIBRE;
    actual.fin--;
    return actual;
    }

int primero(lista actual) {
    return actual.cabeza;
}

lista borrarLista(lista L1)
{
	int indice = L1.fin;
	
	while(indice >=0)
	{
		L1=borrar(L1,indice);
		indice-=1;
	}
	return L1;
}



int siguiente(lista actual, int posicion)
    {
    int cuenta = 0;
    int indice = actual.cabeza;

    if(posicion < 0 || posicion >= actual.fin) {
        return NULO;
    }
    else if(posicion==actual.fin-1)                     // Es la primera variante de la implementacion de una Lista Circular.
    {
        indice=0;
        return primero(actual);
    }

    while(cuenta < posicion) {
        indice = actual.arreglo[indice].siguiente;
        cuenta++;
    }

    printf("El retorno es: %d\n",actual.arreglo[indice].siguiente);
    return actual.arreglo[indice].siguiente;
    }



int anterior(lista actual, int posicion) {
    int cuenta = 0;
    int predecesor = NULO;
    int indice = actual.cabeza;
    if(posicion < 0 || posicion >= actual.fin) {
        return predecesor;
    }
    else if(posicion==0)
    {
        return actual.fin-1;                          // Es la segunda variante de la implementacion de una Lista Circular
    }
    while(cuenta < posicion) {
        predecesor = indice;
        indice = actual.arreglo[indice].siguiente;
        cuenta++;
    }
    return predecesor;
}

lista anular(lista actual) {
    while(actual.fin > 0) {
        actual = borrar(actual, 0);
    }
    return actual;
}

