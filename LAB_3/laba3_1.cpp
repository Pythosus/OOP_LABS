#include <iostream>
#include <vector>

using namespace std;

class Detail
{
protected:
    Detail() { cout << "Detail created" << endl; }

public:
    virtual ~Detail() { cout << "Detail deleted" << endl; }

    virtual void info() const = 0;

    template <typename T>
    static T* create()
    {
        return new T();
    }
};

template <typename T>
void class_store(vector<Detail*>& storage)
{
    storage.push_back(Detail::create<T>());
}

class Assembly : public Detail
{
protected:
    Assembly() { cout << "Assembly created" << endl; }

public:
    ~Assembly() override { cout << "Assembly deleted" << endl; }

    void info() const override { cout << "Assembly!!!" << endl; }

    friend class Detail;
};

class Part : public Detail
{
protected:
    Part() { cout << "Part created" << endl; }

public:
    ~Part() override { cout << "Part deleted" << endl; }

    void info() const override { cout << "Part!!!" << endl; }

    friend class Detail;
};

int main()
{
    vector<Detail*> storage;

    class_store<Part>(storage);
    class_store<Assembly>(storage);

    for (const auto& obj : storage)
    {
        obj->info();
    }

    for (auto& obj : storage)
    {
        delete obj;
        obj = nullptr;
    }
    storage.clear();

    return 0;
}