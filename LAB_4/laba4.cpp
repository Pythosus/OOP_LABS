#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string brand; 
    double price;        

public:
    Vehicle(const string& brand, double price)
        : brand(brand), price(price) {}

    virtual void info() const = 0;
    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle
{
public:
    Bicycle(const string& manufacturer, double price)
        : Vehicle(manufacturer, price) {}

    void info() const override
    {
        cout << "Type: bicycle, brand: " << brand << ", price: " << price << " $." << endl;
    }
};

class Car : public Vehicle
{
private:
    int seats;

public:
    Car(const string& brand, double price, int seats)
        : Vehicle(brand, price), seats(seats) {}

    void info() const override
    {
        cout << "Type: car, brand: " << brand << ", price: " << price << " $, number of seats: " << seats << endl;
    }
};

class Truck : public Vehicle
{
private:
    double load;

public:
    Truck(const string& brand, double price, double load)
        : Vehicle(brand, price), load(load) {}

    void info() const override
    {
        cout << "Type: truck, brand: " << brand<< ", price: " << price << " $, payload capacity: " << load << " tons." << endl;
    }
};

template <typename T>
class PointerArray
{
private:
    vector<T*> data;

public:
    void add(T* element)
    {
        if (!element)
        {
            throw invalid_argument("Cannot add a null pointer.");
        }
        data.push_back(element);
    }

    T*& operator[](size_t index)
    {
        if (index >= data.size())
        {
            throw out_of_range("Index is out of bounds.");
        }
        return data[index];
    }

    size_t size() const
    {
        return data.size();
    }

    ~PointerArray()
    {
        for (T* element : data)
        {
            delete element;
        }
    }
};

int main()
{

    try
    {
        PointerArray<Vehicle> vehicles;

        vehicles.add(new Bicycle("Cube", 400));
        vehicles.add(new Car("Toyota", 20000, 5));
        vehicles.add(new Truck("Volvo", 50000, 20));

        cout << "List of vehicles:" << endl;
        for (size_t i = 0; i < vehicles.size(); ++i)
        {
            vehicles[i]->info();
        }

        try
        {
            vehicles[5]->info();
        }
        catch (const out_of_range& e)
        {
            cerr << "Error: " << e.what() << endl;
        }

        try
        {
            vehicles.add(nullptr);
        }
        catch (const invalid_argument& e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
    catch (const exception& e)
    {
        cerr << "Unexpected error: " << e.what() << endl;
    }

    return 0;
}