#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <time.h>   // 包含时间测量的函数 
using namespace std;
 
void matrix_multiply_ijk(int **a, int **b, int **c, int n);
void matrix_multiply_ikj(int **a, int **b, int **c, int n);
void matrix_multiply_kij(int **a, int **b, int **c, int n);
void matrix_multiply_jki(int **a, int **b, int **c, int n);
void matrix_multiply_kji(int **a, int **b, int **c, int n);
void matrix_multiply_jik(int **a, int **b, int **c, int n);
void matrix_print(int **a, int n);
 
int main(int argc, char *argv[])
{
	// 定义数组：
	srand(time(0));
	int matrix_n = 5000;     // 修改矩阵的阶数为不同的值 
	int numberOfRows = matrix_n;
	int numberOfCols = matrix_n;
	int** mat1 = new int* [numberOfRows];  // a矩阵的行数
	int** mat2 = new int* [numberOfRows]; 
	int** mat3 = new int* [numberOfRows]; 
	for(int i=0; i<numberOfRows; i++)
	{
		mat1[i] = new int[numberOfCols];
		mat2[i] = new int[numberOfCols];
		mat3[i] = new int[numberOfCols];
	} 
	
	// 初始化矩阵  1-10之间的随机数 
	for(int i=0; i<numberOfRows; i++)
	{
		for(int j=0; j<numberOfCols; j++)
		{
			mat1[i][j] = 1 + rand()%(10-1+1);
			mat2[i][j] = 1 + rand()%(10-1+1);
		}
	}
	
	//matrix_print(mat1, matrix_n);    // 输出矩阵 
	//matrix_print(mat2, matrix_n);    // 输出矩阵 
	//matrix_print(mat3, matrix_n);
	
	double clocks_PerMills = double(CLOCKS_PER_SEC) / 1000.0;   // 常数，每秒钟包含的时钟数 

	
	// 选择矩阵乘法方案 
	//matrix_multiply_ijk(mat1, mat2, mat3, matrix_n);        // 矩阵乘法
	for(int m=0;m<6;m++)
	{
		if(m=0)
		{
		clock_t start_time = clock();                            // 开始的时钟数 	
		matrix_multiply_ikj(mat1, mat2, mat3, matrix_n);
	    double elapseMills1 = (clock()-start_time) / clocks_PerMills; 
	    cout << "ikj run time: " << elapseMills1<< "ms" << endl;
	    	
		}
		else if(m=1)
		{
		clock_t start_time = clock();                            // 开始的时钟数 	
		matrix_multiply_ijk(mat1, mat2, mat3, matrix_n);
	    double elapseMills2 = (clock()-start_time) / clocks_PerMills; 
	    cout << "ijk run time: " << elapseMills2<< "ms" << endl;
	   	
		}
		else if(m=2)
		{
			clock_t start_time = clock();                            // 开始的时钟数 	
		matrix_multiply_kij(mat1, mat2, mat3, matrix_n);
	    double elapseMills3 = (clock()-start_time) / clocks_PerMills; 
	    cout << "kij run time: " << elapseMills3<< "ms" << endl;	
		}
		
		else if(m=3)
		{
			clock_t start_time = clock();                            // 开始的时钟数 	
		matrix_multiply_jki(mat1, mat2, mat3, matrix_n);
	    double elapseMills4 = (clock()-start_time) / clocks_PerMills; 
	    cout << "jki run time: " << elapseMills4<< "ms" << endl;	
		}
		else if(m=4)
		{
			clock_t start_time = clock();                            // 开始的时钟数 	
		matrix_multiply_kji(mat1, mat2, mat3, matrix_n);
	    double elapseMills5 = (clock()-start_time) / clocks_PerMills; 
	    cout << "kji run time: " << elapseMills5<< "ms" << endl;	
		}
		
		else if(m=5)
		{
			clock_t start_time = clock();                            // 开始的时钟数 	
		matrix_multiply_jik(mat1, mat2, mat3, matrix_n);
	    double elapseMills6 = (clock()-start_time) / clocks_PerMills; 
	    cout << "jik run time: " << elapseMills6<< "ms" << endl;	
		}
		
		 cout << "clock_perMils: " << clocks_PerMills << endl;	 
		 
	}
	 
	//matrix_print(mat3, matrix_n);
	// matrix_multiply_ikj(mat1, mat2, mat3, matrix_n);
	// matrix_print(mat3, matrix_n);
	// 释放内存 
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
 
// 计算矩阵乘法 ijk
void matrix_multiply_ijk(int **a, int **b, int **c, int n)  // n表示方阵的阶数 
{
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
}
 
// 计算矩阵乘法 ikj
void matrix_multiply_ikj(int **a, int **b, int **c, int n)  // n表示方阵的阶数 
{
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
}

// 计算矩阵乘法 kij
void matrix_multiply_kij(int **a, int **b, int **c, int n)  // n表示方阵的阶数 
{
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
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
}

// 计算矩阵乘法 kji
void matrix_multiply_kji(int **a, int **b, int **c, int n)  // n表示方阵的阶数 
{
	for(int k=0; k<n; k++)
	{
		for(int j=0; j<n; j++)
		{
			int sum = 0;
			int i;
			for(i=0; i<n; i++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
}

// 计算矩阵乘法 jki
void matrix_multiply_jki(int **a, int **b, int **c, int n)  // n表示方阵的阶数 
{
	for(int j=0; j<n; j++)
	{
		for(int k=0; k<n; k++)
		{
			int sum = 0;
			int i;
			for(i=0; i<n; i++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
}

// 计算矩阵乘法 jik
void matrix_multiply_jik(int **a, int **b, int **c, int n)  // n表示方阵的阶数 
{
	for(int j=0; j<n; j++)
	{
		for(int i=0; i<n; i++)
		{
			int sum = 0;
			int k;
			for(k=0; k<n; k++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	} 
}
 
// 输出矩阵
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

