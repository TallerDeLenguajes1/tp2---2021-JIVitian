#include <stdio.h>
#include <stdlib.h>

//Variable global que contiene los tipos de CPU validos
char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
//int size; Podría ser como un atributo de la clase para no tener que pasarse a las funciones como parametro.

typedef struct
{
	int velocidad;//entre 1 y 3 Gherz
	int anio;//entre 2000 y 2017
	int cantidad;//entre 1 y 4
	char *tipo_cpu;//valores del arreglo tipos
} compu ;

compu getPC(compu pc);
void setPC(int size, compu * list);
void showPC(compu pc);
void showPCs(int size, compu * list);
void oldestPC(int size, compu * list);
void fasterPC(int size, compu * list);


int main()
{
	int cantidad = 4;
	compu * PCs = (compu *) malloc(sizeof(compu) * cantidad);

	setPC(cantidad, PCs);
	showPCs(cantidad, PCs);
	oldestPC(cantidad, PCs);
	fasterPC(cantidad, PCs);
	free(PCs);

	return 0;
}

//Genera las caracteristicas de una PC de forma aleatoria
compu getPC(compu pc)
{
	pc.velocidad = 1 + rand() % 3;
	pc.anio = 2000 + rand() % 18;
	pc.cantidad = 1 + rand() % 4;
	pc.tipo_cpu = tipos[rand() % 6];
	return (pc);
}

//Genera una lista de PC
void setPC(int size, compu * list)
{
	compu pc;
	for (int i = 0 ; i < size ; i++) {
		list[i] = getPC(pc);
	}
}

//Muestra las caracteristicas de una PC
void showPC(compu pc)
{
	printf("Velocidad: %dGHz\nAnio: %d\nNucleos: %d\nTipo de Procesador: %s\n", pc.velocidad, pc.anio, pc.cantidad, pc.tipo_cpu);
	printf("\n");
}

//Muestra las caracteristicas de una lista de PCs
void showPCs(int size, compu * list)
{
	for (int i = 0 ; i < size ; i++)
	{
		showPC(list[i]);
	}
}

//Busca y presenta las caracteristicas de la PC mas vieja
void oldestPC(int size, compu * list)
{
	compu oldest = list[0];
	for (int i = 0; i < size; i++)
	{
		if (oldest.anio > list[i].anio){
			oldest = list[i]; 
		}
	}

	printf("La PC mas vieja guardada en la lista es: \n");
	showPC(oldest);
}

//Muestra las caracteristicas de la PC mas rapida
void fasterPC(int size, compu * list)
{
	compu faster = list[0];
	for (int i = 0; i < size; i++)
	{
		if (faster.velocidad < list[i].velocidad){
			faster = list[i]; 
		}
	}

	printf("La PC con mayor velocidad guardada en la lista es: \n");
	showPC(faster);
}