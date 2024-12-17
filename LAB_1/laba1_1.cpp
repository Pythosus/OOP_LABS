#include <iostream>
using namespace std;

int main()
{
    double *ms = new double[10];
    for (int i = 0; i < 10; i++)
        cin >> ms[i];
    cout << "Begin: "<< & ms[0] << endl;
    for (int i = 0; i < 10; i++)
        cout <<ms[i] <<" Adress: " << &ms[i] <<" Distance: "<< &ms[i] - &ms[0] << endl;
    delete[]ms;
}
