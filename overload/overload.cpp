#include <iostream>

using namespace std;

int add(int a, int b = 3)
{
    return (a + b);
}

double add(int a = 5, double b = 3.4)
{
    return (a + b);
}

int main(int argc, const char *argv[])
{
    cout << "add(1, 2)" << add(4, 5) << endl;
    cout << "add(1, 2.6)" << add(1, 4.6) << endl;
    
    return 0;
}
