#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string name;
    float cost;
public:
    Publication() :name("Something"), cost(100) {}
    Publication(string name, float cost):name(name), cost(cost) {}
    void put_data(string nm, float cs) {
        name = nm;
        cost = cs;
    }
    void get_data() const{
        cout << "Name: " << name << " Cost: " << cost<<endl;
    }
};

class book :protected Publication {
protected:
    int pages;
public:
    book(string name, float cost, int pages) : Publication(name, cost), pages(pages) {}
    void put_data(string nm, float cs, int pg) {
        Publication::put_data(nm, cs);
        pages = pg;
    }
    void get_data() const{
        cout << "Name: " << name << " Cost: " << cost <<" Pages: "<<pages<<endl;
    }
};

class type :protected Publication {
protected:
    int time;
public:
    type(string name, float cost, int time) : Publication(name, cost), time(time) {}
    void put_data(string nm, float cs, int tm) {
        Publication::put_data(nm, cs);
        time = tm;
    }
    void get_data() const {
        cout << "Name: " << name << " Cost: " << cost << " Time: " << time << endl;
    }
};

int main()
{
    Publication tst1;
    tst1.get_data();

    book bk1("abcd", 200, 120);
    bk1.get_data();
    bk1.put_data("abcd", 120, 120);
    bk1.get_data();

    type tst2("cool", 50, 70);
    tst2.get_data();
}