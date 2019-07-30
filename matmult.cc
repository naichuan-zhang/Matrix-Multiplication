/**
 * LAB -- Matrices Multiplication
 * Naichuan Zhang
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

void readArr1(int, int, double**);
void multArrs(int, int, int, double**, double**, double**);
  
int main(int argc, char *argv[])
{
	int ar = atoi(argv[1]);
	int ac = atoi(argv[2]);
	int br = atoi(argv[3]);
	int bc = atoi(argv[4]);

	double **mat1 = NULL;
	mat1 = (double **)malloc(sizeof(double*) * ar);
	double **mat2 = NULL;
	mat2 = (double **)malloc(sizeof(double*) * br);

	
	// Error when multiplication failed..
	if (ac != br)
	{
		cout << "Sorry, the matrix cannot be created!" << endl;
		exit(0);
	}

	double **matrix = NULL;
	matrix = (double **)malloc(sizeof(double*) * ar);
	for (int i = 0; i < ar; i++)
		matrix[i] = (double*)malloc(bc * sizeof(double));
	
	cout << "Please enter the first matrix ( " << ar << " x " << ac << " ):\n";
	readArr1(ar, ac, mat1);
	cout << "Please enter the second matrix ( " << br << " x " << bc << " ):\n";
	readArr1(br, bc, mat2);

	multArrs(ar, ac, bc, mat1, mat2, matrix);
	
	return 0;
}

// read two matrices..
void readArr1(int r, int c, double **arr1)
{
	for (int i = 0; i < r; i++)
		arr1[i] = (double *)malloc(sizeof(double) * c);

	for (int ii = 0; ii < r; ii++)
	{
		for (int jj = 0; jj < c; jj++)
		{
			cin >> arr1[ii][jj];
		}
	}
}

// multiply and free matrices..
void multArrs(int ar, int ac, int bc, double **mat1, double **mat2, double **matrix)
{
	for (int i = 0; i < ar; i++)
		for (int j = 0; j < bc; j++)
			matrix[i][j] = 0;

	for (int i = 0; i < ar; i++)
		for (int j = 0; j < bc; j++)
			for (int k = 0; k < ac; k++)
				matrix[i][j] += mat1[i][k] * mat2[k][j];


	cout << "The result of multiplication:\n";
	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < bc; j++)
		{
			cout << matrix[i][j] << setw(5);
		}
		cout << "\n";
	}

	// free three matrices...
	for (int i = 0; i < ar; i++)
	{
		free(mat1[i]);
		mat1[i] = NULL;
		free(matrix[i]);
		matrix[i] = NULL;
	}
	free(mat1);
	mat1 = NULL;
	free(matrix);
	matrix = NULL;
	for (int i = 0; i < ac; i++)
	{
		free(mat2[i]);
		mat2[i] = NULL;
	}
	free(mat2);
	mat2 = NULL;
}

