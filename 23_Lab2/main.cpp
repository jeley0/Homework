#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include "datetime.h"

using namespace std;

Datetime* ReadFileDate(string file_name, int& n)
{
    int hour, minute, second, day, month, year;
    ifstream file(file_name);
    string line;
    n = 0;
    while (getline(file, line))
    {
        n++;
    }
    Datetime* Date = new Datetime[n];
    int i = 0;
    file.clear();
    file.seekg(0, ios::beg);
    while (getline(file, line))
    {
        istringstream line_(line);
        line_ >> hour >> minute >> second >> day >> month >> year;
        Date[i].Set(hour, _hour_);
        Date[i].Set(minute, _minute_);
        Date[i].Set(second, _second_);
        Date[i].Set(day, _day_);
        Date[i].Set(month, _month_);
        Date[i].Set(year, _year_);
        i++;
    }
    file.close();
    return Date;
}
int main()
{
    srand(time(0));
    Datetime date, next, prev;
    int n;
    Datetime* Date = ReadFileDate("23_Lab1_file.txt", n);
    Datetime* Next = new Datetime[n];
    date.SystemTime(date); printf("\n\nSystem time: "); date.Output();
    printf("\n\n\tData read from file:\n\n");
    for (int i = 0; i < n; i++)
    {
        Date[i].GetNextDate(next);
        Date[i].GetPrevDate(prev);
        printf("%i)\t", i + 1);
        Date[i].Output();
        printf("\t");
        next.Output();
        printf("\t");
        prev.Output();
        printf("\n");
        Next[i] = next;
    }
    printf("\n\tVariant 3:\n\n");
    for (int i = 0; i < n; i++)
    {
        if (Date[i].Get(_month_) == Next[i].Get(_month_))
        {
            printf("%i)\t", i + 1);
            Date[i].Output();
            printf("\t");
            Next[i].Output();
            printf("\n");
        }
    }
    delete[] Date;
    delete[] Next;
    return 0;
}