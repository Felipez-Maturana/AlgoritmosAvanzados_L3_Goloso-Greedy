#include "structs.h"

#ifndef _FUNCIONES_H
#define _FUNCIONES_H

lista InsertSort(lista L);
lista EliminarRepetidos(lista L);
int verificarVocal(int elemento);

lista moverDerecha(lista L);
lista moverIzquierda(lista L);
int calcularDesfase(lista L1,lista L2);
int BuscarEspacio(lista L1,int a);
lista moverNDerecha(lista L, int veces);
lista moverNIzquierda(lista L, int veces);
lista Decodificar(int desfase, lista LDescifrar, lista Alfabeto);




void mostrarResultado(int numPag,resultadoPag rp1, FILE * Salida);

int pivot(publicidad *p1, int izq, int der);
void Quicksort(publicidad *p1, int izq, int der);
#endif // _FUNCIONES_H
