#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 5

int main(){
	int f,c;
	//Primera forma vista en clase
	//Creamos un vector de una matriz que funciona como una matriz de 2 dimensiones
	//double ** mt = (double **) malloc(sizeof(int) * N * M);
	///...

	/*double * mt = (double *) malloc(N * M * sizeof(double));

	for(f = 0 ; f < N ; f++)
	{
		for(c = 0 ; c < M ; c++)
		{
			*(mt + f * M + c) = f * M + c;
			printf("%.1lf ", *(mt + f * M + c));
		}
		printf("\n");
	}

	free(mt);*/

	//Reservo N elementos para las filas
	double ** mt = (double **) malloc(sizeof(double *) * N);

	for (f = 0; f < N; f++)
	{
		//Reservo M elementos para las columnas
		mt[f] = (double *) malloc(sizeof(double) * M);
		for (c = 0; c < M; c++)
		{
			mt[f][c] = f * M + c;
			printf("%.1lf ", mt[f][c]);
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++)
	{
		free(mt[i]);
	}
}