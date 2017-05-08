#include "structs.h"
#include <stdio.h>
#include <string.h>
//Funcion que se encarga de insertar en el ultimo lugar de una lista de listas ListaEnlazada, la lista L1 
lista * appendLista(lista L1, lista * ListaEnlazada, int * CantidadElementos)
{
	//Se aumenta en uno la cantidad de elementos que posee esa lista
	* CantidadElementos = *CantidadElementos + 1; 
	
	//Se asigna mAs memoria a la lista enlazada que contendrA las listas
	ListaEnlazada = (lista *) realloc(ListaEnlazada,*CantidadElementos*sizeof(lista));
	
	//Se asigna en la posicion indicada, la lista L1
	ListaEnlazada[*CantidadElementos-1] = L1;
	
	return ListaEnlazada;
	
}

int pivot(publicidad *p1, int izq, int der)
{
    int i;
    int pivote, valor_pivote;
    publicidad aux;

    pivote = izq;
    valor_pivote = p1[pivote].valor;
    for (i=izq+1; i<=der; i++){
        if (p1[i].valor > valor_pivote){
                pivote++;
                aux=p1[i];
                p1[i]=p1[pivote];
                p1[pivote]=aux;

        }
    }
    aux=p1[izq];
    p1[izq]=p1[pivote];
    p1[pivote]=aux;
    return pivote;
}
//O(n) = nlogn
void Quicksort(publicidad *p1, int izq, int der)
{
     int pivote;
     if(izq < der){
        pivote=pivot(p1, izq, der);
        Quicksort(p1, izq, pivote-1);
        Quicksort(p1, pivote+1, der);
     }
}

int todosUsados(lista usados, int numPub)
{
	int i=0;
	for(i=0;i<numPub;i++)
	{
		if(usados.arreglo[i].elemento == 0)
			return 0;
	}
	return 1;
}


resultadoPag * insertarPublicidad(publicidad * publicidades, int numPub, pagina * paginas, int numPag )
{
	int pag=0;
	int pub=0;
	lista usados = crearLista();
	resultadoPag * pagResultado = calloc(sizeof(resultadoPag),numPag); 
	int i =0;

	for(i=0;i<numPub;i++)
	{
		usados=append(usados,0);
		
	}
	

	int largoActual;

	int numPagResultado=0;
	int cantidadIdentificadores=0;
	
	int anuncios=0;
	for(i=0;i<numPag;i++)
	{	
		pagResultado[i].identificadores = calloc(sizeof(char *),10);

	}
	
	while(pag < numPag )
	{
		if(todosUsados(usados, numPub)==1)
			break;
			
		pub = 0;
		largoActual = paginas[pag].largo;
		//anchoActual = paginas[numPag].ancho;
		numPagResultado=0;
		cantidadIdentificadores=0;
		
		while(pub<numPub)
		{
				

			if(usados.arreglo[pub].elemento == 0 && publicidades[pub].largo <= largoActual && publicidades[pub].ancho <= paginas[pag].ancho)
			{
				anuncios+=1;
				usados.arreglo[pub].elemento = 1;
				largoActual -= publicidades[pub].largo;

				pagResultado[pag].valorTotal += publicidades[pub].valor;
				


				pagResultado[pag].identificadores[cantidadIdentificadores] = publicidades[pub].identificador;
				cantidadIdentificadores+=1;
				pagResultado[pag].totalIdentificadores+=1;
					
			}
			else
			{
				pub +=1;
				
			}
			
			if(pub >= numPub)
			{
				pag +=1;
				
			}
			 
		}
		numPagResultado+=1;
	}
	
	
		

		
	//printf("%d\n",numPagResultado);
	
	FILE * Salida;
	
	Salida = fopen("Salida.out","w");
	
	
	for(i=0;i<numPag;i++)
	{
		//printf("=%d\n",pagResultado[i].totalIdentificadores);	
		mostrarResultado(i,pagResultado[i],Salida);
	}
	
	fclose(Salida);
	

	int ganancias=0;
	printf("NUmero total de anuncios: %d\n",anuncios);
	for(i=0;i<pag;i++)
	{
		ganancias += pagResultado[i].valorTotal;
	}
	printf("Ganancias: %d\n",ganancias);
	
	
	
	return pagResultado;
}



























publicidad crearPublicidad(char * identificador, int ancho, int largo, int valor)
{
	publicidad p1;
	p1.identificador = malloc(sizeof(char *));
	strcpy(p1.identificador,identificador);
//	p1.identificador = identificador;
	p1.ancho = ancho;
	p1.largo = largo;
	p1.valor = valor;
	p1.area = largo*ancho;
	return p1;
}

pagina crearPagina(int largo, int ancho, int numeropag)
{
	pagina pag1;
	pag1.largo = largo;
	pag1.ancho = ancho;
	pag1.numeropag = numeropag;
	return pag1;
}


void mostrarResultado(int numpag,resultadoPag rp1,FILE * Salida)
{	

	fprintf(Salida,"pAgina %d:\n",numpag+1);
	int i=0;
	fprintf(Salida,"Anuncios: ");
	for(;i<rp1.totalIdentificadores;i++)
	{
		fprintf(Salida," %s", rp1.identificadores[i]);
		if(i!=rp1.totalIdentificadores-1)
		{
			fprintf(Salida,"-");
		}
	} 	
	fprintf(Salida,"\nGanancias: %d\n************************\n", rp1.valorTotal);
	
}

void mostrarPublicidad(publicidad p1)
{
	printf("Identificador: %s, Ancho: %d, Largo: %d, Area %d, Valor: %d.\n",p1.identificador,p1.ancho,p1.largo,p1.area,p1.valor);
}

void mostrarPagina(pagina pag1)
{
	//printf("pag %d largo %d ancho %d\n",pag1.numeropag,pag1.largo,pag1.ancho);
}

//Muestra por pantalla todos los elementos que se encuentran en la lista que contiene las listas de combinaciones
void mostrarListaEnlazada(lista * ListaEnlazada, int CantidadElementos)
{
	int i;
	for(i=0;i<CantidadElementos;i++)
	{
		printf("%d: ",i+1);
		mostrar(ListaEnlazada[i]);
	}
}

int verificarDuplicado(publicidad * Ps, int numPub, char * identificador)
{
	int i=0;
	for(i=0;i<numPub;i++)
	{
		if(strcmp(Ps[i].identificador,identificador) == 0)
		{
			//printf("El %s se encuentra repetido en %d\n",Ps[i].identificador,i);
			return 0;
		} 
	}
//	printf("%s NO SE ENCUENTRA\n",identificador);
	return 1;
}


pagina * obtenerPaginas(int * numeroPaginas)
{
	int i=0;
	printf("Ingrese el nUmero de pAginas disponibles (mAximo 10)\n");
	scanf("%d",numeroPaginas);
	if(*numeroPaginas < 0 || *numeroPaginas>10)
	{
		while( ! (*numeroPaginas>0 && *numeroPaginas<10))
		{
			printf("El valor ingresado no es vAlido, inserte un nUmero entre 1 y 10\n");
			printf("Ingrese el nUmero de pAginas disponibles\n");
			scanf("%d",numeroPaginas);
		}  
	}
	pagina * paginas = malloc(sizeof(pagina)* *numeroPaginas);
	
	int * largoPag = malloc(sizeof(int));
	int * anchoPag = malloc(sizeof(int));
	
	for(i=0;i<*numeroPaginas;i++)
	{
		printf("Ingrese el valor del largo de la pAgina %d\n",i+1);
		scanf("%d",largoPag);
		
		if(*largoPag >0)
		{
			paginas[i].largo = *largoPag;
		}
		else
		{
			while( *largoPag<0  )
			{
				printf("El valor ingresado no es vAlido, inserte un nUmero mayor a 0\n");
				printf("Ingrese el valor del largo de la pAgina %d\n",i+1);
				scanf("%d",largoPag);				
				if(*largoPag >0)
				{
					//paginas[i].largo = *largoPag;
				}
			}
		}
		
		
		printf("Ingrese el valor del ancho de la pAgina %d\n",i+1);
		scanf("%d",anchoPag);
		
		if(*anchoPag >0)
		{
			paginas[i].ancho = *anchoPag;
		}
		else
		{
			while( *largoPag<0  )
			{
				printf("El valor ingresado no es vAlido, inserte un nUmero mayor a 0\n");
				printf("Ingrese el valor del ancho de la pAgina %d\n",i+1);
				scanf("%d",anchoPag);				
				if(*anchoPag >0)
				{
					//paginas[i].ancho = *anchoPag;
				}
			}
		}
		paginas[i] = crearPagina(*largoPag, *anchoPag, i);
	}
	
	return paginas;
}


void LeerArchivo()
{
	FILE * Entrada;
	Entrada =fopen("Entrada.in","r");
	 
	publicidad * Ps = calloc(sizeof(publicidad),1);
	
	char * Identificador = calloc(sizeof(char),5);
	int * largo = calloc(sizeof(int),1);
	int * ancho = calloc(sizeof(int),1);
	int * valor = calloc(sizeof(int),1); 
	char in;
	int pub=0;
	
	while( !feof(Entrada) )
	{
		in= '0';		
		fscanf(Entrada,"%s",Identificador);
		
		
		if(  strncmp(Identificador,"//",2) !=0  && verificarDuplicado(Ps,pub,Identificador)==1)
		{
			
			fscanf(Entrada,"%d %d %d",ancho,largo,valor);
			
			Ps = realloc(Ps,  sizeof(publicidad)*(pub+1));
			
			Ps[pub] = crearPublicidad(Identificador,*ancho,*largo,*valor);
			
			pub=pub+1;
			
		}
		else
		{
			
			while( in !='\n' && !feof(Entrada)  ){
				in = fgetc(Entrada);

			}
		}
	}
	fclose(Entrada);
	
	Quicksort(Ps,0,pub-1);


	int z=0;
	for(z=0;z<pub;z++)
	{
		mostrarPublicidad(Ps[z]);
	}


	
	int * numeroPaginas = malloc(sizeof(int));
	pagina * paginas = obtenerPaginas(numeroPaginas);

	
	//printf("pub %d pags %d\n",pub,*numeroPaginas);
	
	insertarPublicidad(Ps, pub, paginas, *numeroPaginas);
	
}
