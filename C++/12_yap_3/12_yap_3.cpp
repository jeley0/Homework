#include <iostream>
#include <fstream>
using namespace std;

struct phone {
    int price = 0, ram = 0, year = 0;
    string name;

    void out();
    bool IsEqual(phone);
};

struct MyStack
{
    struct Node
    {
        phone data;
        Node* prev;
    };
    Node* Top = NULL;
    int Count = 0;

    bool Push(phone);
    bool Pop(phone&);
    void Info();
    void clear(phone&);
};

void phone::out() {
    cout << "Информация о телефоне:"
        << "\tНазвание - " << name << endl
        << "\tЦена - " << price << endl
        << "\tОбъём памяти - " << ram << endl
        << "\tГод выпуска - " << year << endl;
}

bool phone::IsEqual(phone a) {
    if (a.price == price && a.ram == ram && a.name == name && a.year == year) return true;
    return false;
}

bool MyStack::Push(phone data)
{
    if (!Top)
    {
        Top = new Node;
        Top->prev = NULL;
        Count = 1;
    }
    else
    {
        Node* temp;
        temp = new Node;
        temp->prev = Top;
        Top = temp;
        Count++;
    }
    Top->data = data;
    return true;
}

bool MyStack::Pop(phone& data)
{
    if (!Top) return false;
    Node* temp = Top->prev;
    data = Top->data;
    delete Top;
    Top = temp;
    Count--;
    return true;
}

void MyStack::Info()
{
    if (!Top) cout << "Stack is empty" << endl;
    else
    {
        cout << endl << "Stack info: " << endl;
        cout << "Stack size = " << Count << endl;
        Top->data.out();
    }
}

void MyStack::clear(phone& k) {
    while (Count != 0) Pop(k);
}

void read(MyStack&, string);
void FindCr(MyStack&, phone);

int main()
{
    setlocale(LC_ALL, "Russian");
    phone k;
    phone find;
    MyStack S;
    read(S, "phone.txt");
    int choice;


    do {
        cout << "1. Добавить телефон в корзину" << endl;
        cout << "2. Вытащить телефон из корзины" << endl;
        cout << "3. Очистить корзину" << endl;
        cout << "0. Выход" << endl;

        cin >> choice;

        switch (choice) {
        
        case 1: {
            system("cls");
            cout << "Введите название: "; cin >> k.name;
            cout << "Введите цену: "; cin >> k.price;
            cout << "Введите объём памяти: "; cin >> k.ram;
            cout << "Введите год выпуска: "; cin >> k.year;
            
            S.Push(k);
            system("cls");
            break;
        }

        case 2: {
            system("cls");
            cout << "Введите название: "; cin >> find.name;
            cout << "Введите цену: "; cin >> find.price;
            cout << "Введите объём памяти: "; cin >> find.ram;
            cout << "Введите год выпуска: "; cin >> find.year;
            FindCr(S, find);
            system("cls");
            break;
        }

        case 3: {
            S.clear(k);
            system("cls");
        }

        case 0: {
            S.clear(k);
            break;
        }

        }
    } while (choice != 0);
}

void read(MyStack& S, string FileName) {
    ifstream F(FileName);

    if (!F) {
        cout << "Ошибка при загрузке базы телефонов. Не найден файл" << endl << endl;
        return;
    }

    phone cr;

    while (F >> cr.price >> cr.ram >> cr.name >> cr.year) S.Push(cr);

    F.close();
}

void FindCr(MyStack& S, phone find) {
    phone cr;
    MyStack second;
    while (S.Count != 0 && !(S.Top->data.IsEqual(find))) {
        S.Pop(cr);
        second.Push(cr);
    }
    if (S.Count != 0) {
        cout << "Телефон найден" << endl;
        S.Pop(cr);
        system("pause");
        system("cls");
    }
    else cout << "Телефон не найден" << endl;
    while (second.Pop(cr)) S.Push(cr);
    system("pause");
    system("cls");
}
