#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <time.h>   // ����ʱ������ĺ��� 
using namespace std;
 
void matrix_multiply_ijk(int **a, int **b, int **c, int n);
void matrix_multiply_ikj(int **a, int **b, int **c, int n);
void matrix_multiply_jik(int **a, int **b, int **c, int n);
void matrix_multiply_jki(int **a, int **b, int **c, int n);
void matrix_multiply_kij(int **a, int **b, int **c, int n);
void matrix_multiply_kji(int **a, int **b, int **c, int n);
 
void matrix_print(int **a, int n);
 
int main(int argc, char *argv[])
{
	// �������飺
	srand(time(0));
	int matrix_n = 5000;     // �޸ľ���Ľ���Ϊ��ͬ��ֵ 
	int numberOfRows = matrix_n;
	int numberOfCols = matrix_n;
	int** mat1 = new int* [numberOfRows];  // a���������
	int** mat2 = new int* [numberOfRows]; 
	int** mat3 = new int* [numberOfRows]; 
	for(int i=0; i<numberOfRows; i++)
	{
		mat1[i] = new int[numberOfCols];
		mat2[i] = new int[numberOfCols];
		mat3[i] = new int[numberOfCols];
	} 
	
	// ��ʼ������  1-10֮�������� 
	for(int i=0; i<numberOfRows; i++)
	{
		for(int j=0; j<numberOfCols; j++)
		{
			mat1[i][j] = 1 + rand()%(10-1+1);
			mat2[i][j] = 1 + rand()%(10-1+1);
		}
	}
	matrix_multiply_ijk(mat1, mat2, mat3, matrix_n);
	matrix_multiply_ikj(mat1, mat2, mat3, matrix_n);
	matrix_multiply_jik(mat1, mat2, mat3, matrix_n);
	matrix_multiply_jki(mat1, mat2, mat3, matrix_n);
	matrix_multiply_kij(mat1, mat2, mat3, matrix_n);
	matrix_multiply_kji(mat1, mat2, mat3, matrix_n);
	for(int i=0; i<numberOfRows; i++)
	{
		delete mat1[i];
		delete mat2[i];
		delete mat3[i];
	}
	delete mat1;
	delete mat2;
	delete mat3;
	return 0;
}
 
// �������˷� ijk
void matrix_multiply_ijk(int **a, int **b, int **c, int n)  // n��ʾ����Ľ��� 
{
	double clocks_PerMills = double(CLOCKS_PER_SEC) / 1000.0;   // ������ÿ���Ӱ�����ʱ���� 
	clock_t start_time = clock();                            // ��ʼ��ʱ���� 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int sum = 0;
			for(int k=0; k<n; k++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
	double elapseMills = (clock()-start_time) / clocks_PerMills; 
	cout << "The routine run time of ijk: " << float(elapseMills /1000)<< "s" << endl;	
}
 
// �������˷� ikj
void matrix_multiply_ikj(int **a, int **b, int **c, int n)  // n��ʾ����Ľ��� 
{
	double clocks_PerMills = double(CLOCKS_PER_SEC) / 1000.0;   // ������ÿ���Ӱ�����ʱ���� 
	clock_t start_time = clock();                            // ��ʼ��ʱ���� 
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
		{
			int sum = 0;
			int j;
			for(j=0; j<n; j++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
	double elapseMills = (clock()-start_time) / clocks_PerMills; 
	cout << "The routine run time of ikj: " <<float(elapseMills /1000)<< "s"  << endl;	
}
//�������˷�jik
 void matrix_multiply_jik(int **a, int **b, int **c, int n)
 {
 	double clocks_PerMills = double(CLOCKS_PER_SEC) / 1000.0;   // ������ÿ���Ӱ�����ʱ���� 
	clock_t start_time = clock();                            // ��ʼ��ʱ���� 
 	for (int j=0; j<n; j++)
 	{
 		for (int i=0; i<n; i++)
 		{
 			int sum = 0;
 			for (int k=0; k<n; k++)
 				sum += a[i][k]*b[k][j];
 			c[i][j] = sum;
		  } 
	 }
	double elapseMills = (clock()-start_time) / clocks_PerMills; 
	cout << "The routine run time of jik: " << float(elapseMills /1000)<< "s" << endl;	
 }
//�������˷�jki 
 void matrix_multiply_jki(int **a, int **b, int **c, int n)
 {
 	double clocks_PerMills = double(CLOCKS_PER_SEC) / 1000.0;   // ������ÿ���Ӱ�����ʱ���� 
	clock_t start_time = clock();                            // ��ʼ��ʱ���� 
 	for (int j=0; j<n; j++)
 	{
 		for (int k=0; k<n; k++)
 		{
 			int r=b[k][j];
 			for (int i=0; i<n; i++)
 				c[i][j] +=a[i][k]*r;
		  } 
	 }
	double elapseMills = (clock()-start_time) / clocks_PerMills; 
	cout << "The routine run time of jki: " << float(elapseMills /1000)<< "s"  << endl;	
 }
// �������˷� kij
void matrix_multiply_kij(int **a, int **b, int **c, int n)
{
	double clocks_PerMills = double(CLOCKS_PER_SEC) / 1000.0;   // ������ÿ���Ӱ�����ʱ���� 
	clock_t start_time = clock();                            // ��ʼ��ʱ���� 
	for (int k=0; k<n; k++) 
	{
		for (int i=0; i<n; i++) 
		{
			int r = a[i][k];
			for (int j=0; j<n; j++)
				c[i][j] += r * b[k][j];
		 } 
	}
	double elapseMills = (clock()-start_time) / clocks_PerMills; 
	cout << "The routine run time of kij: " << float(elapseMills /1000)<< "s"  << endl;	
}
// �������˷� kji 
void matrix_multiply_kji(int **a, int **b, int **c, int n)
{
	double clocks_PerMills = double(CLOCKS_PER_SEC) / 1000.0;   // ������ÿ���Ӱ�����ʱ���� 
	clock_t start_time = clock();                            // ��ʼ��ʱ���� 
	for (int k=0; k<n; k++) 
	{
		for (int j=0; j<n; j++) 
		{
			int r = b[k][j];
			for (int i=0; i<n; i++)
				c[i][j] += a[i][k]*r;
		 } 
	}
	double elapseMills = (clock()-start_time) / clocks_PerMills; 
	cout << "The routine run time of kji: " << float(elapseMills /1000)<< "s"  << endl;	
}

// �������
void matrix_print(int **a, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
} 
