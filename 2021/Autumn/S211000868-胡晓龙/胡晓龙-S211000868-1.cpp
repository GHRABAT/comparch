#include<time.h>
#include<iostream>
#include<cstring>
using namespace std;
#define Max 5000
double a[Max][Max];
double b[Max][Max];
double c[Max][Max];


int main()
{
	int i, j, k, n;
	n = 2000;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = 1;//rand()%10;
			b[i][j] = 1;//rand()%10;
		}
	}

	cout << "����ά��Ϊ:" << n << "*" << n << endl;

	clock_t start, finish;            //ijk
	double duration;
	start = clock();
	double sum, r;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			sum = 0.0;
			for (k = 0; k < n; k++)
			{
				sum += a[i][k] * b[k][j];
				c[i][j] = sum;
			}
		}
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "ijk����ʱ��:" << duration << endl;

	start = clock();                    //jik
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			sum = 0.0;
			for (k = 0; k < n; k++)
			{
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
		}
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "jik����ʱ��:" << duration << endl;

	start = clock();                     //kij
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			r = a[i][k];
			sum = 0.0;
			for (j = 0; j < n; j++)
			{
				sum += r * b[k][j];
			}
			c[i][j] = sum;
		}
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "kij����ʱ��:" << duration << endl;

	start = clock();                //kji
	for (k = 0; k < n; k++)                 
	{
		for (j = 0; j < n; j++)
		{
			r = b[k][j];
			sum = 0.0;
			for (i = 0; i < n; i++)
			{
				sum += b[i][k] * r;
			}
			c[i][j] = sum;
		}
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "kji����ʱ��:" << duration << endl;

	start = clock();               //ikj
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			r = a[i][k];
			sum = 0.0;
			for (j = 0; j < n; j++)
			{
				sum += r * b[k][j];
			}
			c[i][j] = sum;
		}
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "ikj����ʱ��:" << duration << endl;

	start = clock();               //jki
	for (j = 0; j < n; j++)
	{
		for (k = 0; k < n; k++)
		{
			r = b[k][j];
			sum = 0.0;
			for (i = 0; i < n; i++)
			{
				sum += b[i][k] * r;
			}
			c[i][j] = sum;
		}
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "jki����ʱ��:" << duration << endl;
	return 0;
}
//����ά��Ϊ:2000*2000
//ijk����ʱ��:50.153
//jik����ʱ��:35.621
//kij����ʱ��:28.152
//kji����ʱ��:28.589
//ikj����ʱ��:28.497
//jki����ʱ��:30.328

