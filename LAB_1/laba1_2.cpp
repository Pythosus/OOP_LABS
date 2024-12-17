#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class Book{
private:
    string author;
    string name;
    int Btype;
    map<int, string> book_type{
        {1, "художественные"}, {2, "технические"}
    };
public:
    Book() : author("Ivanov I.I."), name("Book"), Btype(1) {}
    Book(string author, string name, int Btype) {
        this->author = author;
        this->name = name;
        this->Btype = Btype;
    }

    string get_type() { return book_type[Btype]; }
    string get_author() { return author; }
    string get_name() { return name; }

};

void info(Book obj) {
    cout << obj.get_name()<<' '<<obj.get_author()<<' '<<obj.get_type()<<endl;
}

int main()
{
    setlocale(LC_ALL, "");
    vector<Book> library;
    Book kn1;
    Book kn2("James Brown", "Modern Technologies", 2);
    Book kn3("H.P. Lovecraft", "Call of Cthulhu", 1);
    library.push_back(kn1);
    library.push_back(kn2);
    library.push_back(kn3);
    for (Book n : library) {
        info(n);
    }
