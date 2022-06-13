#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

void scanarr(double* arr, int n) //Заполнение массива для 1-й части
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 21 + (-10);
	}
}

void twinarr(double* arr, double* arr1, int n) //Дублирование массива
{
	for (int i = 0; i < n; i++)
	{
		arr1[i] = arr[i];
	}
}

void printarr(double* arr, int n) //Вывод массива
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

int elements() //Подсчёт количества элементов в файле
{
	double a;
	int n = 0;
	std::ifstream A("arr.txt");
	while (A >> a)
	{
		n++;
	}
	A.close();
	return n;
}

void newarr(double* arr, int n) //Заполнение массива для 2-й части
{
	std::ifstream A("arr.txt");
	for (int i = 0; i < n; i++)
	{
		A >> arr[i];
	}
	A.close();
}

void push_back(double*& arr, int& n, int k, int val) //Добавление элемента в массив, задан номер
{
	k--;
	if (k >= 0 && k <= n)
	{
		double* newa = new double[n + 1];
		for (int i = 0; i < n; i++)
			newa[i] = arr[i];
		newa[k] = val;
		n++;
		for (int i = k + 1; i < n; i++)
			newa[i] = arr[i - 1];
		delete[] arr;
		arr = newa;
	}
	else std::cout << "Нет такого элемента.";
}

void pop_back(double*& arr, int& n, int k) //Удаление элемента, задан номер
{
	k--;
	if (k >= 0 && k <= n)
	{
		double* newa = new double[n - 1];
			for (int i = 0; i < k; i++)
				newa[i] = arr[i];
			n--;
			for (int i = k; i < n; i++)
				newa[i] = arr[i + 1];
		delete[] arr;
		arr = newa;
	}
	else std::cout << "Нет такого элемента.";
}

void push_value(double*& arr, int& n, int value, int val) //Добавление элемента, задано значение
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
		{
			k = i + 1;
			break;
		}
	}
	double* newa = new double[n + 1];
	if (k > 0)
	{
		for (int i = 0; i < k; i++)
		{
			newa[i] = arr[i];
		}
		n++;
		newa[k] = val;
		for (int i = k + 1; i < n; i++)
		{
			newa[i] = arr[i - 1];
		}
		delete[] arr;
		arr = newa;
	}
	else std::cout << "Элемент не найден" << std::endl;
}

void pop_value(double*& arr, int& n, int value) //Удаление элемента, задано значение
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
		{
			k = i + 1;
			break;
		}
	}
	double* newa = new double[n + 1];
	if (k > 0)
	{
		for (int i = 0; i < k; i++)
		{
			newa[i] = arr[i];
		}
		n--;
		for (int i = k; i < n; i++)
		{
			newa[i] = arr[i + 1];
		}
		delete[] arr;
		arr = newa;
	}
	else std::cout << "Элемент не найден" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n;
	std::cout << "Введите размер массива: ";
	std::cin >> n;
	double* arr = new double[n];
	double* arr1 = new double[n];
	scanarr(arr, n);
	std::cout << "Изначальный массив: ";
	printarr(arr, n);

	twinarr(arr, arr1, n);
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] < 0)
			arr1[i] *= arr1[i];
	}
	std::cout << "1.Замена отрицательных элементов их квадратами: ";
	printarr(arr1, n);

	twinarr(arr, arr1, n);
	int p;
	std::cout << "2.Введите p: ";
	std::cin >> p;
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] > p)
			arr1[i] = sqrt(arr1[i]);
	}
	std::cout << "2.Замена элементов больше p их корнями: ";
	printarr(arr1, n);

	twinarr(arr, arr1, n);
	int amax = arr1[0], amin = arr1[0], imax = 0, imin = 0, s = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr1[i] > amax)
		{
			amax = arr1[i];
			imax = i;
		}
		else if (arr1[i] < amin)
		{
			amin = arr1[i];
			imin = i;
		}
	}
	s = arr1[imax];
	arr1[imax] += arr1[imin];
	arr1[imin] *= s;
	std::cout << "3.Замена max на сумму max и min, а min на их произведение: ";
	printarr(arr1, n);

	twinarr(arr, arr1, n);
	int j, n1;
	if (n % 2 == 1) n1 = n - 1; else n1 = n;
	for (int i = 0; i < n1; i += 2)
	{
		j = arr1[i];
		arr1[i] = arr1[i + 1];
		arr1[i + 1] = j;
	}
	std::cout << "4.Перемена мест чётного и нечётного элемента: ";
	printarr(arr1, n);

	delete[] arr;
	delete[] arr1;

	n = elements();
	arr = new double[n];
	newarr(arr, n);
	std::cout << "Массив из файла: ";
	printarr(arr, n);

	int x = rand() % 21 + (-10);
	int y;
	std::cout << "Введите число: ";
	std::cin >> y;
	push_back(arr, n, n + 1, x);
	push_back(arr, n, n + 1, y);
	std::cout << "1.Добавить случайный и введёный с клавиатуры элементы в конец: ";
	printarr(arr, n);
	delete[] arr;
	n -= 2;

	arr = new double[n];
	newarr(arr, n);
	pop_back(arr, n, n);
	std::cout << "2.Удалить последний элемент: ";
	printarr(arr, n);
	delete[] arr;
	n++;

	x = rand() % 21 + (-10);
	y = 0;
	std::cout << "Введите число: ";
	std::cin >> y;
	arr = new double[n];
	newarr(arr, n);
	push_back(arr, n, 1, y);
	push_back(arr, n, 1, x);
	std::cout << "3.Добавить случайный и введёный с клавиатуры элементы в начало: ";
	printarr(arr, n);
	delete[] arr;
	n -= 2;

	arr = new double[n];
	newarr(arr, n);
	pop_back(arr, n, 1);
	std::cout << "4.Удалить первый элемент: ";
	printarr(arr, n);
	delete[] arr;
	n++;

	x = rand() % 21 + (-10);
	y = 0;
	std::cout << "Введите число: ";
	std::cin >> y;
	arr = new double[n];
	newarr(arr, n);
	int num;
	std::cout << "Введите номер массива, после которого нужно вставить элементы: ";
	std::cin >> num;
	push_back(arr, n, num + 1, x);
	push_back(arr, n, num + 2, y);
	std::cout << "5.Добавить случайный и введёный с клавиатуры элементы после элемента с заданным номером: ";
	printarr(arr, n);
	delete[] arr;
	n -= 2;

	arr = new double[n];
	newarr(arr, n);
	num = 0;
	std::cout << "Введите номер массива, после которого нужно удалить элемент: ";
	std::cin >> num;
	pop_back(arr, n, num + 1);
	std::cout << "6.Удалить элемент после элемента с заданным номером: ";
	printarr(arr, n);
	delete[] arr;
	n++;

	x = rand() % 21 + (-10);
	y = 0;
	std::cout << "Введите число: ";
	std::cin >> y;
	arr = new double[n];
	newarr(arr, n);
	double val;
	std::cout << "Введите значение, после которого нужно вставить элементы: ";
	std::cin >> val;
	push_value(arr, n, val, y);
	push_value(arr, n, val, x);
	std::cout << "7.Добавить случайный и введёный с клавиатуры элементы после элемента с заданным номером: ";
	printarr(arr, n);
	delete[] arr;
	n -= 2;

	arr = new double[n];
	newarr(arr, n);
	val = 0;
	std::cout << "Введите значение, после которого нужно удалить элемент: ";
	std::cin >> val;
	pop_value(arr, n, val);
	std::cout << "8.Удалить элемент после элемента с заданным значением: ";
	printarr(arr, n);
	delete[] arr;
}
