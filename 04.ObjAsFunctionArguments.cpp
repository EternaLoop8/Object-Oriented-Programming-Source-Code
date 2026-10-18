#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // constructoe (no args)
    Distance() : feet(0), inches(0.0)
    {
    }

    // constructor (two args)
    Distance(int ft, float in) : feet(ft), inches(in)
    {
    }

    // get length from user
    void getdist()
    {
        cout << "Enter feet: " << endl;
        cin >> feet;
        cout << "ENter inches: " << endl;
        cin >> inches;
    }

    // display distance
    void showdist()
    {
        cout << feet << "' - " << inches << "\"" << endl;
    }

    // declaration
    void add_dist(Distance, Distance);
};

// add lenghts d2 and d3
void Distance::add_dist(Distance d2, Distance d3)
{
    inches = d2.inches + d3.inches; // add the inches
    feet = 0;                       // (for possible carry)
    if (inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
    feet += d2.feet + d3.feet;
}

int main()
{
    Distance dist1, dist3;    // define two lenghts
    Distance dist2(11, 6.25); // defien and initialize dist2

    dist1.getdist();
    dist3.add_dist(dist1, dist2);

    // display all lengths
    cout << "dist1= " << endl;
    dist1.showdist();

    cout << "dist2= " << endl;
    dist2.showdist();

    cout << "dist3= " << endl;
    dist3.showdist();

    return 0;
}