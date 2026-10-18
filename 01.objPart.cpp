#include <bits/stdc++.h>
using namespace std;

class part // define class
{
private:
    int modelnumber;
    int partnumber;
    float cost;

public:
    void setpart(int mn, int pn, float c) // set data
    {
        modelnumber = mn;
        partnumber = pn;
        cost = c;
    }

    void showpart() // dispaly data
    {
        cout << "Model " << modelnumber;
        cout << ", part " << partnumber;
        cout << ", costs $" << cost << endl;
    }
};

int main()
{
    part part1; // define object of class part

    part1.setpart(6244, 373, 217.55F); // call member function
    part1.showpart();

    return 0;
}