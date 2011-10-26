#include <iostream>
#include <cstring>

using namespace std;

class Person
{
    private:
        int age;
        char *name;
    
    public:
        Person(const char *name = NULL, int age = 0);
        void display();
        ~Person();
 
    protected:
        void sleep();
};

Person::Person(const char * name, int age)
:name(NULL), age(age)
{
    if (NULL == name)
    {
        this->name = new char [1];
	*this->name = '\0';
	return;
    }
   
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    
    this->age = age;
}

Person::~Person()
{
    delete [] name;
}

void Person::display()
{
    cout << "name:  " << name << endl;
    cout << "age:  " << age << endl;
    cout << "person" ;
    sleep();
}

void Person::sleep()
{
    cout << "sleep" << endl;
}

class Student:public Person
{
    public:
        Student(char const *name = NULL, int age = 0):Person(name, age)
	{
	}
        void display()
	{
	    sleep();
	}

};

int main()
{
    Person stu("hello", 1);
    stu.display();

    Student stt;
    stt.display();

    return 0;
}
