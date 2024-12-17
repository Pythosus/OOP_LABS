#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "Base object destroyed." << endl;
    }

    virtual void show() const
    {
        cout << "<-Base object." << endl;
    }
};

class Derived : public Base
{
public:
    ~Derived() override
    {
        cout << "Derived object destroyed." << endl;
    }

    void show() const override
    {
        cout << "<-Derived object." << endl;
    }
};

void add(vector<Base*>& storage, Base* obj)
{
    storage.push_back(obj);
}

int main()
{
    
    srand(static_cast<unsigned>(time(0)));

    vector<Base*> storage;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        if (rand() % 2 == 0)
        {
            add(storage, new Base());
        }
        else
        {
            add(storage, new Derived());
        }
    }

    for (const auto& obj : storage)
    {
        obj->show();
    }

    for (auto& obj : storage)
    {
        delete obj;
    }

    return 0;
}