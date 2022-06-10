#include "stdafx.h"
#include "math.h"
#include "stdlib.h"

void selection_sort(int *a, int n, FILE *f)
{	
	int i,j,min,t,C=0,M=0;
	for (i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			C++;
			if(a[j]<a[min]) min=j;
		}
		if (min!=i)
		{
			M++;
			t=a[i];
			a[i]=a[min];
			a[min]=t;
		}
	}
	fprintf(f,"%d, %d, %d\n",n,C,M);
	fclose(f);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int *a;
	FILE *f;
	f=fopen("selectiona1.txt","w");
	fprintf(f,"N, C, M\n");
	fclose(f);
	f=fopen("selectionb1.txt","w");
	fprintf(f,"N, C, M\n");
	fclose(f);
	f=fopen("selectionc1.txt","w");
	fprintf(f,"N, C, M\n");
	fclose(f); //Создаем 3 файла

	for (int n=10;n<=10000;n=n+500)
	{
		a=new int [n];
		for (int i=0;i<n;i++)
		{
			a[i]=i;
		}
		for (int i=0;i<n;i=i+10)
		{
			a[i]=rand()%n;
		} // Задали массив
		f=fopen("selectiona1.txt","a");
		selection_sort(a,n,f);
		
		a=new int [n];
		for (int i=0,j=n-1;i<n;i++,j--)
		{
			a[i]=j; 
		} //Задали массив
		
		f=fopen("selectionb1.txt","a");
		selection_sort(a,n,f);
		
		
		a=new int [n];
		for (int i=0;i<n;i++)
		{
			a[i]=rand()%n; 
		} //Задали массив						
		
		f=fopen("selectionc1.txt","a");
		selection_sort(a,n,f);
		if (n<11) n=0;
	}
	return 0;
}
