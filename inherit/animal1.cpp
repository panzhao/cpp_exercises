#include <iostream>
#include <cstring>

using namespace std;

class Animal
{
    public:
        Animal(const char *m_name = NULL, int m_age = 1)
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
	    cout << "Animal copyconstructure!" << endl;

	    if (NULL == temp.name)
	    {
	        name = new char[1];
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

	virtual void show_info()
	{
	    cout << "Animal age:" << age << endl;
	    cout << "Animal name:" << name << endl;
	}
    
    private:
        char *name;
        int age;
};

class Dog:public Animal
{
    public:
        Dog(const char *p_name, int p_age, const char *m_name, int m_age = 1)
	:Animal(p_name, p_age), age(m_age), name(NULL)
        { 
            if (NULL == m_name)
	    {
	        name == new char[1];
		*name = '\0';
		
		return;
	    }
	     
            name = new char[strlen(m_name) + 1];
	    strcpy(name, m_name);

	    cout << "Dog constructure!" << endl;
        }
        
        void show_info()
	{
	    cout << "Dog age:" << age << endl;
	    cout << "Dog name:" << name << endl;
	}
	
        ~Dog()
	{
	    delete [] name;

	    cout << "Dog unconstructure!" << endl;
	}

    private:
        int age;
	char *name;
};

int main(void)
{
    Dog an("parent", 30, "child", 15);
    Dog bn(an);
    an.show_info();
    bn.show_info();
    
    return 0;
}
