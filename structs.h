#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#define MAX_ARR 300
typedef struct publicidad
{
	char * identificador;
	int ancho;
	int largo;
	int area;
	int valor;
} publicidad;

typedef struct pagina
{
	int largo;
	int ancho;
	int numeropag;	
} pagina;


typedef struct resultadoPag
{
//	int numeropag;
	int valorTotal;
	int totalIdentificadores;
	char ** identificadores;	
} resultadoPag;


typedef struct s {
	publicidad publi;
    int elemento;
    int siguiente;
} nodo;



typedef struct t {
    nodo arreglo[MAX_ARR];
    int cabeza;
    int fin;
} lista;



#endif
