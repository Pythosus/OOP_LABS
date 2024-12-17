#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string name;
    float cost;
public:
    Publication() :name("Something"), cost(100) {}
    Publication(string name, float cost) :name(name), cost(cost) {}
    void put_data(string nm, float cs) {
        name = nm;
        cost = cs;
    }
    void get_data() const {
        cout << "Name: " << name << " Cost: " << cost << endl;
    }
};

class sales {
protected:
    float prodano[3];
public:
    sales() :prodano{ 100, 100, 100 } {}
    sales(float m1, float m2, float m3) :prodano{m1, m2, m3} {}
    void put_data(float m1, float m2, float m3) {
        prodano[0] = m1; prodano[1] = m2; prodano[2] = m3;
    }
    void get_data() const {
        cout << "Saled in 1 month: " << prodano[0] << " Saled in 2 month: " << prodano[1] << "Saled in 3 month: " << prodano[2] << endl;
    }
};

class book :protected Publication, protected sales {
protected:
    int pages;
public:
    book(string name, float cost, int pages, float m1, float m2, float m3) : Publication(name, cost), pages(pages), sales(m1, m2, m3){}
    void put_data(string nm, float cs, int pg, float m1, float m2, float m3) {
        Publication::put_data(nm, cs);
        pages = pg;
        sales::put_data(m1, m2, m3);
    }
    void get_data() const {
        cout << "Name: " << name << " Cost: " << cost << " Pages: " << pages << endl;
        sales::get_data();
        cout << "---------------------------------------" << endl;
    }
};

class type :protected Publication, protected sales {
protected:
    int time;
public:
    type(string name, float cost, int time, float m1, float m2, float m3) : Publication(name, cost), time(time), sales(m1, m2, m3) {}
    void put_data(string nm, float cs, int tm, float m1, float m2, float m3) {
        Publication::put_data(nm, cs);
        time = tm;
        sales::put_data(m1, m2, m3);
    }
    void get_data() const {
        cout << "Name: " << name << " Cost: " << cost << " Time: " << time << endl;
        sales::get_data();
        cout << "---------------------------------------"<<endl;
    }
};

int main()
{
    type au("Audio", 100.2, 300, 100, 84, 91);
    au.get_data();
    book bk("Kniga", 78.8, 350, 120.2, 88.2, 100.1);
    bk.get_data();
    bk.put_data("New Kniga", 80, 350, 120.2, 90.2, 101.2);
    bk.get_data();
}