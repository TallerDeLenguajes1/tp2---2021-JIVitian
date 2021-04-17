#include <stdio.h>
#include <stdlib.h>

void llenarMatriz(int N, int M, int ** matriz);
void mostrarMatriz(int N, int M, int ** matriz);
void determinarPares(int N, int M, int** matriz, int * pares);
void liberarMatriz(int N, int ** matriz);

int main()
{
	int filas = 15, columnas = 5 + rand() % 11;
	int * pares = (int *) calloc(filas, sizeof(int));
	int ** matriz = (int **) malloc(sizeof(int *) * filas);

	llenarMatriz(filas, columnas, matriz);
	mostrarMatriz(filas, columnas, matriz);
	printf("\n");
	determinarPares(filas, columnas, matriz, pares);
	printf("\n");
	liberarMatriz(filas, matriz);
	free(pares);

	return 0;
}

void llenarMatriz(int N, int M, int ** matriz)
{
	for (int i = 0 ; i < N ; i++)
	{
		//Reservo tantos elementos como columnas tenga
		matriz[i] = (int *) malloc(sizeof(int) * M);
		for (int j = 0 ; j < M ; j++)
		{
			//Pongo valores aleatorios entre 100 y 999 en la matriz
			matriz[i][j] = 100 + rand() % 900;
		}
	}
}

void mostrarMatriz(int N, int M, int ** matriz)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%4d", matriz[i][j]);
		}
		printf("\n");
	}
}

void determinarPares(int N, int M, int** matriz, int * pares)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//Cada vez que obtenga un numero par de la matriz, el contador de pares de la fila i crece
			if (!(matriz[i][j] % 2))
				pares[i] += 1;
		}
		//Muestro la cantidad de pares por fila
		printf("La cantidad de pares en la fila %d es: %d\n", i+1, pares[i]);
	}
}

void liberarMatriz(int N, int ** matriz)
{
	//Libero el espacio en memoria de cada fila de la matriz
	for (int i = 0; i < N; i++)
	{
		free(matriz[i]);
	}
}