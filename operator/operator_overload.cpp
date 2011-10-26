#include <iostream>

using namespace std;

class CComplex
{
    public:
        CComplex(double m_real = 0.0, double m_img = 0.0)
        {
            real = m_real;
            img  = m_img;
        }
   
        void print()
        {
            cout << "real:" << real << endl;
            cout << "img:"  << img  << endl;
        }
       
        /*运算符重载，在类的方法中默认传的有this指针*/
        CComplex operator + (CComplex &temp);
        CComplex operator + (double temp);
        
        /*友员函数需要指定一个参数*/
        friend CComplex operator + (double temp_img, CComplex &m_temp);
        
    private:
        double real;
        double img;

};

CComplex CComplex::operator + (CComplex &m_temp)
{   
    CComplex temp;
    
    temp.real = real + m_temp.real;
    temp.img  = img  + m_temp.img;

    return temp;
}

CComplex CComplex::operator + (double m_img)
{   
    CComplex temp;
    
    temp.real = real;
    temp.img  = m_img + img;

    return temp;
}


CComplex operator + (double m_img, CComplex &m_temp)
{   
    CComplex temp;
    
    temp.real = m_temp.real;
    temp.img  = m_img + m_temp.img;

    return temp;
}

int main(int argc, const char *argv[])
{
    CComplex par1(3.0, 5.8);
    CComplex par2(4.0, 6.8);
    
    CComplex par3 = par1 + par2;
    CComplex par4 = 4.6  + par1;
  
    par3.print();
    par4.print();
    
    return 0;
}
