#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    void getdist()
    {
        cout << "Enter feet: " << endl;
        cin >> feet;
        cout << "Enter inches: " << endl;
        cin >> inches;
    }

    void showdist()
    {
        cout << feet << "' - " << inches << "\"" << endl;
    }
};

int main()
{

    Distance dist[100];
    int n = 0;
    char ans;

    do
    {
        cout << "Enter distance number " << n + 1 << endl;
        dist[n++].getdist();
        cout << "Enter another (y/n)?: " << endl;
        cin >> ans;
    } while (ans != 'n');

    for (int j = 0; j < n; ++j)
    {
        cout << "Distance number " << j + 1 << " is ";
        dist[j].showdist();
    }
    cout << endl;

    return 0;
}