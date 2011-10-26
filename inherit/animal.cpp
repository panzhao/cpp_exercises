#include <iostream>
#include <cstring>

using namespace std;

class Animal
{
    public:
        Animal(const char *m_name, int m_age = 1)
	:age(m_age), name(NULL)
	{   
	    if (NULL == m_name)
	    {
	        name = new char[1];
		*name = '\0';
	
	        return;
	    }

	    name = new char[strlen(m_name) + 1];
	    strcpy(name, m_name);
	    
	    cout << "Animal constructure!" << endl;
	}

	Animal(Animal &temp)
	{
	    cout << "Animal constructure!" << endl;
	    
	    if (NULL == temp.name)
	    {
	        name  = new char[1];
		*name = '\0';
		
		return;
	    }

	    name = new char[strlen(temp.name) + 1];
            strcpy(name, temp.name);
	    
	    age = temp.age;
	}

	~Animal()
	{
	    delete [] name;
	    cout << "Animal unconstructure!" << endl;
	}
	
	void show_info()
	{
	    cout << "Animal age:" << age << endl;
	    cout << "Animal name:" << name << endl;
	}
#if 0
        virtual void sleep()
	{
	    cout << "animal sleep" << endl;
	}

	void show_info()
	{
	    cout << "Animal age:" << age << endl;
	}
    
    protected:
	void eat()
	{
	    cout<<"animal eat"<<endl;
	}
    
    private:
	void walk()
	{
	    cout<<"animal walk"<<endl;
	}
#endif
    private:
        char *name;
        int age;
};

#if 0
class Dog:public Animal
{
    public:
        Dog(int p_age = 1, int m_age = 1):Animal(p_age), age(m_age)
        { 
	    cout << "Dog constructure!" << endl;
	    cout << "Dog age:" << age << endl;
        }

	~Dog()
	{
	    cout << "Dog unconstructure!" << endl;
	}

        void sleep()
	{
	    cout << "Dog sleep" << endl;
	}

    private:
        int age;
};

class Person:public Animal
{
    public:
        void sleep()
	{
	    eat();
	    cout<<"person sleep"<<endl;
	}
};
#endif 

int main(void)
{
    Animal an("lucy", 15);
    Animal bn(an);
    bn.show_info();

    return 0;
}
