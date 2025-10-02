#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Samsonov {
    public:
        float * p;
        float x;
        Samsonov(float val_x) 
        {
            cout << "Конструктор S" << endl; x = val_x; p = new float(x); 
        }
        void setvalue(float _x) 
        {
            *p = _x;
        }
        virtual void getp() 
        {
            if (p != nullptr) cout << *p << endl;
        }
        virtual ~Samsonov() 
        { 
            delete p; p = nullptr; cout << "Деструктор S" << endl; 
        }
        virtual void geti() {}
};

class Aleksandr : public Samsonov {
    public:
        int y;
        Aleksandr(int _y, float val_x) : Samsonov(val_x) 
        {
             cout << "Пользовательский конструктор A" << endl; y = _y; 
        }
        void geti() override 
        {
            cout << y << endl;
        }
        ~Aleksandr () 
        { 
            cout << "Деструктор А" << endl; 
        }
};

void fillwagon(vector<Samsonov*>& _Wagon, int _n) {
    srand(time(NULL));
    float a;
    int b;
    for (int i = 0; i < _n; i++) 
    {
        a = rand()%10 + static_cast<float>(rand()) / (RAND_MAX + 1.0);
        b = rand()%10;
        _Wagon.push_back(new Aleksandr(b, a));
        _Wagon.back()->getp();
        _Wagon.back()->geti();
    }
}

int main () {
    vector<Samsonov*> Wagon;
    vector<Samsonov*> Lorry;
    int n;
    cin >> n;
    fillwagon(Wagon, n);
    cout << "---------------------------------------------------------------------------" << endl;
    for (int i = 0; i < Wagon.size(); i++) 
    {
        Lorry.push_back(Wagon[i]);
        Wagon[i] = nullptr;
        Lorry.back()->getp();
        Lorry.back()->geti();
    }
    for (auto l : Lorry) 
    {
        delete l;
    }
    return 0;
}
