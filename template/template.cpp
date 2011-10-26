#include <iostream>

using namespace std;

template <class T1, class T2, int x>

T1 sum(T1 a, T2 b)
{
    return (a + b + x);
}

int main(int argc, const char *argv[])
{
    cout << "sum(3, 'a'):" << sum<int , char , 3>(3, 'a') << endl;
  //cout << "sum('a', 3):"   << sum('a', 3)   << endl;
  //cout << "sum(3.2, 4.6):" << sum(3.2, 4.6) << endl;

    return 0;
}
