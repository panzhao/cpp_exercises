#include <iostream>

using namespace std;

class Animal
{
    public:
        Animal(int m_age = 1):age(m_age)
	{
	    cout << "Animal constructure!" << endl;
	}

        virtual void sleep()            //虚函数 类似 包含void (*sleep)()绑定
	{
	    cout<<"animal sleep"<<endl;
	}

	void show_info()
	{
	    cout << "Animal age:" << age << endl;
	}
    
    protected:                          //被保护 的区域 可在 继承他的函数中调用
	void eat()
	{
	    cout<<"animal eat"<<endl;
	}
    
    private:
        int age;

	void walk()
	{
	    cout<<"animal walk"<<endl;
	}
};

class Dog:public Animal
{
    public:
        Dog(int p_age = 1, int m_age = 1):Animal(p_age), age(m_age)
        { 
	    cout << "Dog constructure!" << endl;
	    cout << "Dog age:" << age << endl;
        }

        void sleep()
	{
	    cout<<"Dog sleep"<<endl;
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

int main(void)
{
    Dog dg(30, 10);
    dg.show_info();

    return 0;
}
