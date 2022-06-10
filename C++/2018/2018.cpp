#include "stdio.h"
#include "stdlib.h" 
#include "math.h" 

void con(int*& a, int& n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void push_back(int*& a, int& n, int val)
{
	int* newa = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		newa[i] = a[i];
	}
	newa[n] = val;
	n++;
	delete[] a;
	a = newa;
}

void pop_back(int*& a, int& n)
{
	n--;
	int* newa = new int[n];
	for (int i = 0; i < n; i++)
	{
		newa[i] = a[i];
	}
	delete[] a;
	a = newa;
}

void push_forward(int*& a, int& n, int val)
{
	int* newa = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		newa[i] = a[i - 1];
	}
	newa[0] = val;
	n++;
	delete[] a;
	a = newa;
}

void pop_forward(int*& a, int& n)
{
	n--;
	int* newa = new int[n];
	for (int i = 0; i < n; i++)
	{
		newa[i] = a[i + 1];
	}
	delete[] a;
	a = newa;
}

void push_num(int*& a, int& n, int v, int val)
{
	int* newa = new int[n + 1];
	for (int i = 0; i < v; i++)
	{
		newa[i] = a[i];
	}
	newa[v] = val;
	for (int i = v + 1; i <= n; i++)
	{
		newa[i] = a[i - 1];
	}
	n++;
	delete[] a;
	a = newa;
}

void pop_num(int*& a, int& n, int v)
{
	n--;
	int* newa = new int[n + 1];
	for (int i = 0; i < v; i++)
	{
		newa[i] = a[i];
	}
	for (int i = v; i < n; i++)
	{
		newa[i] = a[i + 1];
	}
	delete[] a;
	a = newa;
}

void push_value(int*& a, int& n, int I, int val)
{
	int* newa = new int[n + 1];
	for (int i = 0; i <= I; i++)
	{
		newa[i] = a[i];
	}
	newa[I + 1] = val;
	for (int i = I + 2; i <= n; i++)
	{
		newa[i] = a[i - 1];
	}
	n++;
	delete[] a;
	a = newa;
}

void pop_value(int*& a, int& n, int I)
{
	n--;
	int* newa = new int[n + 1];
	for (int i = 0; i <= I; i++)
	{
		newa[i] = a[i];
	}
	for (int i = I + 1; i < n; i++)
	{
		newa[i] = a[i + 1];
	}
	delete[] a;
	a = newa;
}

int main()
{
	int n;
	printf("Enter quantity n:");
	scanf_s("%d", &n);//ввод размера массива 
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 21 + (-10);//ввод элементов массива 
	}
	printf("a[n0]=");
	con(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			a[i] = a[i] * a[i];//решение первого 
	}
	printf("a[n1]=");
	con(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] > n)
			a[i] = sqrt(a[i]);//решение второго 
	}
	printf("a[n2]=");
	con(a, n);
	int amax = a[0], amin = a[0], imax = 0, imin = 0, S = 0, V = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > amax) { amax = a[i]; imax = i; }
		else if (a[i] < amin) { amin = a[i]; imin = i; }
	}
	S = a[imax] + a[imin];
	V = a[imax] * a[imin];
	a[imax] = S;
	a[imin] = V;//решение третьего 
	printf("a[n3]=");
	con(a, n);
	int j, n1;
	if (n % 2 == 1) n1 = n - 1; else n1 = n;
	for (int i = 0; i < n1; i += 2)
	{
		j = a[i]; a[i] = a[i + 1]; a[i + 1] = j;//решение четвертого 
	}
	printf("a[n4]=");
	con(a, n);
	int x = rand() % 21 + (-10);
	int y;
	printf("Enter number:");
	scanf_s("%d", &y);
	push_back(a, n, x);
	push_back(a, n, y);//решение пятого (1/2)
	printf("a[n5.1]=");
	con(a, n);
	pop_back(a, n);
	pop_back(a, n);//решение пятого (2/2)
	printf("a[n5.2]=");
	con(a, n);
	push_forward(a, n, x);
	push_forward(a, n, y);//решение шестого (1/2)
	printf("a[n6.1]=");
	con(a, n);
	pop_forward(a, n);
	pop_forward(a, n);//решение шестого (2/2)
	printf("a[n6.1]=");
	con(a, n);
	int v;
	printf("Enter v(0<v<quantity):");
	scanf_s("%d", &v);
	if ((v >= n) || (v < 1))
	{
		printf("Wrong number\n");
		system("pause");
		exit(0);
	}
	push_num(a, n, v, x);
	push_num(a, n, v + 1, y);//решение седьмого (1/2)
	printf("a[n7.1]=");
	con(a, n);
	pop_num(a, n, v);
	pop_num(a, n, v);//решение седьмого (2/2)
	printf("a[n7.2]=");
	con(a, n);
	int I = 99;
	printf("Enter V:");
	scanf_s("%d", &V);
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == V)
			I = i;
	}
	if (I == 99)
	{
		printf("Wrong value\n");
		system("pause");
		exit(0);
	}
	push_value(a, n, I, x);
	push_value(a, n, I + 1, y);//решение восьмого (1/2)
	printf("a[n8.1]=");
	con(a, n);
	pop_value(a, n, I);
	pop_value(a, n, I);//решение восьмого (2/2)
	printf("a[n8.2]=");
	con(a, n);
	system("pause");
	return 0;
}
