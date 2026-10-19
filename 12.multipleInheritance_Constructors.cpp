#include <bits/stdc++.h>
using namespace std;

class Type{
    private:
    string dimensions;
    string grade;

    public:
        //no-arg constructor
        Type() : dimensions("N/A"), grade("N/A"){}

        //2-arg constructor
        Type(string di, string gr) : dimensions(di), grade(gr){}

        // get type from user
        void gettype(){
            cout << "Enter nominal dimensions (2x4 etc.): " << endl;
            cin >> dimensions;
            cout << "Enter grade (rough, const, etc.): " << endl;
            cin >> grade;
        }
        void showtype() const{
            cout << "Dimensions: " << dimensions << endl;
            cout << "Grade: " << grade << endl;
        }
};

class Distance{
    private:
        int feet;
        float inches;
    public:
    Distance() : feet(0), inches(0.0)
    {}
    Distance(int ft, float in) : feet(ft), inches(in)
    {}
    void getdist(){
        cout << "Enter feet: " << endl;
        cin >> feet;
        cout << "Enter inches: " << endl;
        cin >> inches;
    }
    void showdist() const {
        cout << feet << "\'-" << inches << '\"' << endl;
    }
};

class Lumber : public Type, public Distance{
    private:
        int quantity;
        double price;
    public:
    Lumber() : Type(), Distance(), quantity(0), price(0.0){

    }
    Lumber(string di, string gr, int ft, float in, int qu, float prc)
    : Type(di, gr), Distance(ft, in), quantity(qu), price(prc){

    }
    void getlumber(){
        Type::gettype();
        Distance::getdist();
        cout << "Enter quantity: " << endl;
        cin >> quantity;
        cout << "Enter price per piece: " << endl;
        cin >> price;
    }
    void showlumber() const{
        Type::showtype();
        cout << "Lenght: " << endl;
        Distance::showdist();
        cout << "Price for " << quantity << " pieces: $ " << price * quantity << endl;
    }
};

int main() {
    Lumber siding;

    cout << "Siding data: " << endl;
    siding.getlumber();

    Lumber studs("2x4", "const", 8, 0.0, 200, 4.45F);

    cout << "---Siding---" << endl;
    siding.showlumber();
    cout << "----Studs---" << endl;
    studs.showlumber();
    
    return 0;
}