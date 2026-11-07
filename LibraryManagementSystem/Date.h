#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;

    bool isLeapYear(int y);
    int daysInMonth(int m, int y);

public:
    Date();
    Date(int d, int m, int y);

    void input();
    int Tdays();
    void display();

    // Getters
    int getDay();
    int getMonth();
    int getYear();

    // setters
    void set(int d, int m, int y);
};