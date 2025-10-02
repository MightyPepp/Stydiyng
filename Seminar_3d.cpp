#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class First
{
    public:
        int * p;
        int x;
        First() 
        {
            cout << "Конструктор 1" << endl; x = rand()%10; p = new int(x); 
        }
        virtual void getp() 
        {
            if (p != nullptr) cout << *p << endl;
        }
        virtual ~First() 
        { 
            delete p; p = nullptr; cout << "Деструктор 1" << endl; 
        }
};

class Second_First : public First
{
    public:
        float p;
        Second_First() : First() 
        {
            p = 2.61;
            cout << "Конструктор 2.1" << endl;
        }
        ~Second_First () 
        { 
            cout << "Деструктор 2.1" << endl; 
        }
        void getp() override
        {
            cout << p << endl;
        }
};

class Second_Second : public First
{
    private:
        char p;
    public:
        Second_Second() : First() 
        {
            char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
            int numLetters = sizeof(letters) / sizeof(letters[0]) - 1; 
            p = letters[rand() % numLetters];
            cout << "Конструктор 2.2" << endl;
        }
        ~Second_Second () 
        { 
            cout << "Деструктор 2.2" << endl; 
        }
        void getp() override
        {
            cout << p << endl;
        }
        void setp(char val_p) 
        {
            p = val_p;
        }
};

void fillFirstV(vector<First*>& _FirstV, int _n) 
{
    for (int i = 0; i < _n; i++) 
    {
        _FirstV.push_back(new First());
        _FirstV.back()->getp();
        _FirstV.push_back(new Second_First());
        _FirstV.back()->getp();
        _FirstV.push_back(new Second_Second());
        _FirstV.back()->getp();
    }
}

int main () 
{
    srand(time(NULL));
    int n;
    cin >> n;
    vector<First*> FirstV;
    fillFirstV(FirstV, n);
    cout << "----------------------------------------------" << endl;
    vector<First*> SecondV;
    for (int i = 0; i < FirstV.size(); i++) 
    {
        SecondV.push_back(FirstV[i]);
        SecondV.back()->getp();
    }
    for (auto l : SecondV) 
    {
        delete l;
    }
    return 0;
}
