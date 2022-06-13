/*
Графы.
Найти длину от выбранной вершины до всех вершин.
Составить маршрут от выбранной вершины до другой выбранной вершины.
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <climits>

int** Read(std::string, int&, int&); //Прототипы функций
void Delete(int**&, int);
int* dijkstra(int**, int, int);
void dijkstra_route(int**, int, int, int, int*, std::stack <int>&);

int main()
{
    setlocale(LC_ALL, "Russian");
    
    std::ofstream out; //Создаем файл для выходных данных
    out.open("out.txt");

    int n, m;
    std::stack <int> route;

    int** A = Read("matrix.txt", n, m);   
    if (n != m | A == NULL) //Проверяем входной файл на валидность
    {
        std::cout << "Ошибка";
        out << "Ошибка";
        return 0;
    }

    int s;
    std::cout << "Стартовая вершина: ";
    std::cin >> s;
    s--;
    int* d = dijkstra(A, n, s);
    
    for (int i = 0; i < n; i++) //Выводим полученый маршрут расстояний в файл и консоль
    {
        std::cout << s + 1 << " -> " << i + 1 << " = " << d[i] << std::endl;
        out << s + 1 << " -> " << i + 1 << " = " << d[i] << std::endl;
    }

    int end;
    std::cout << "Конечная вершина: "; std::cin >> end;
    end--;

    dijkstra_route(A, n, s, end, d, route);

    std::cout << "Маршрут: " << std::endl; //Выводим машрут в консоль и файл
    out << "Маршрут: " << std::endl;
    
    while (!route.empty())
    {
        std::cout << " -> " << route.top();
        out << " -> " << route.top();
        route.pop();
    }
    std::cout << std::endl;
    out << std::endl;
    out.close();
    Delete(A, n);
    delete[] d;
    return 0;
}

int** Read(std::string file_name, int& n, int& m) //Считывание данных из файла
{
    std::ifstream in(file_name);
    if (in.is_open())
    {
        int count = 0;
        int temp;

        while (!in.eof()) //Подсчёт количества символов в файле
        {
            in >> temp;
            count++;
        }

        in.seekg(0, std::ios::beg);
        in.clear();

        int count_space = 0;
        char symbol;

        while (!in.eof())
        {
            in.get(symbol); //Подсчёт количества пробелов в строке
            if (symbol == ' ') 
                count_space++;
            if (symbol == '\n') 
                break;
        }

        in.seekg(0, std::ios::beg);
        in.clear();

       
        n = count / (count_space + 1); //Вычисление вершин графа
        m = count_space + 1;

        int** x = new int* [n];

        // записываем в двумерный массив вершины графа, где n это номер начальной вершины, а m номер конечной вершины
        for (int i = 0; i < n; i++) 
            x[i] = new int[m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                in >> x[i][j];
            }
        }
        in.close();
        return x;
    }
    in.close();
    return NULL;
}

void Delete(int**& x, int n) //Очистка памяти
{
    for (int i = 0; i < n; i++) 
        delete[] x[i];
    delete[] x;
}

int* dijkstra(int** A, int n, int s) // Алгоритм Дейкстры
{
    const int inf = INT_MAX;
    int* d = new int[n];
    bool* v = new bool[n];
    int u;

    for (int i = 0; i < n; i++)
    {
        d[i] = inf; //Заполняем пути к вершинам максимальными значениями
        v[i] = false;
    }

    d[s] = 0;// Начальная вершина
    /*
    Идем от начальной вершины к первой вершине, запоминаем расстояние, идем ко второй вершине, запоминаем расстояние и т.д.
    пока не дойдем до конца, затем выбираем вершину с наименьшим расстоянием до исходной вершины и идем от нее к следующей так до конца,
    на выходе получаем кратчайший маршрут в виде длин
    */
    for (int count = 0; count < n - 1; count++)
    {
        int min = inf;
        for (int i = 0; i < n; i++) //Находим вершину с минимальным к ней расстоянием
            if (!v[i] && d[i] <= min)
            {
                min = d[i];
                u = i;
            }
        v[u] = true;
        for (int i = 0; i < n; i++) //Даем всем вершинам, смежным с выбранной вес пути к ней
            /*если эта вершина не пройденная и она смежна с выбранной
            и если сумма веса выбранной вершины и ребра к текущей будет меньше, чем
            вес текущей на данный момент, то  - меняем значение веса текущей вершины.*/
            if (!v[i] && A[u][i] && d[u] != inf && d[u] + A[u][i] < d[i])
                d[i] = d[u] + A[u][i];
    }
    delete[] v;
    return d;
}

void dijkstra_route(int** A, int n, int s, int end, int* d, std::stack <int>& route) //Реализация функции составления маршрута
{
    route.push(end + 1);
    int weight = d[end];
    /*
    Проходим по файлу и сравниваем значения в нем с значениями в массиве маршрута
    если совпадают запоминаем вершину, на выходе получаем путь
    */
    while (end != s)
    {
        for (int i = 0; i < n; i++)
            if (A[i][end] != 0)
            {
                int temp = weight - A[i][end];
                if (temp == d[i])
                {
                    weight = temp;
                    end = i;
                    route.push(i + 1);
                }
            }
    }
}
