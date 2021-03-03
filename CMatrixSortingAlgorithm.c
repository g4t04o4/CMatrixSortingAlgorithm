#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** generate(const int** matrix, size_t m, size_t n)
{
	int key = 0;
	int k = 0;

	int** newMatrix = (int**)malloc(m * sizeof(int*));

	for (size_t i = 0; i < m; i++)
	{
		newMatrix[i] = (int*)malloc(n * sizeof(int));
	}

	for (size_t j = 0; j < n; j++)
	{
		newMatrix[0][j] = matrix[0][j];

		for (size_t i = 1; i < m; i++)
		{
			key = matrix[i][j];
			k = i - 1;

			while (k >= 0 && newMatrix[k][j] < key)
			{
				newMatrix[k + 1][j] = newMatrix[k][j];
				k--;
			}

			newMatrix[k + 1][j] = key;
		}
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			key = newMatrix[i][j];
			k = j - 1;
	
			while (k >= 0 && newMatrix[i][k] < key)
			{
				newMatrix[i][k + 1] = newMatrix[i][k];
				k--;
			}
			newMatrix[i][k + 1] = key;
		}
	}

	return newMatrix;
}

void printMatrixToConsole(const int** matrix, size_t m, size_t n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	const size_t m = 10, n = 8;

	srand(123456);

	int** matrix = (int**)malloc(m * sizeof(int *));
	for (size_t i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n * sizeof(int));
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 100 - 1;
		}
	}

	printMatrixToConsole(matrix, m, n);
	printf("\n");
	printMatrixToConsole(generate(matrix, m, n), m, n);

	return 0;
}
