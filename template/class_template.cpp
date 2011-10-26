#include <iostream>

using namespace std;

template <T> class Node
{
    public:
       Node(T data):mDate(data), next(NULL)
       {
       
       }

    private:
       int mDate;
       Node<T> *next; 
};
