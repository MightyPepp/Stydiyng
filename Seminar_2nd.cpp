#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Parent 
{
    public:
        float * p;
        float x;
        Parent(float x_val) 
        {
            cout << "Конструктор P" << endl;
            x = x_val;
            p = new float(x);
        }
        virtual void getp() 
        {
            if (p != nullptr) cout << *p << endl;
        }
        virtual ~Parent() 
        {
            delete p;
            p = nullptr;
            cout << "Деструктор P" << endl;
        }
};

class Child : public Parent 
{
    public:
        Child(float x_val) : Parent(x_val) 
        {
           cout << "Конструктор С" << endl;
        }
        ~Child() 
        {
            cout << "Деструктор С" << endl;
    }
};

void fillP1(vector<Parent*>& _P1, int _n) 
{
    srand(time(NULL));
    float a;
    for (int i = 0; i < _n; i++) 
    {
        a = rand()%10 + static_cast<float>(rand()) / (RAND_MAX + 1.0);
        _P1.push_back(new Child(a));
        _P1.back()->getp();
    }
}

int main () 
{
    srand(time(NULL));
    int n;
    cin >> n;
    vector<Parent*> P1;
    fillP1(P1, n);
    cout << "--------------------------------------------------------------" << endl;
    vector<Parent*> P2;
    for (int i = 0; i < P1.size(); i++) 
    {
        P2.push_back(P1[i]);
        P2.back()->getp();
    }
    for (auto l : P1) 
    {
        delete l;
    }
    return 0;
}
