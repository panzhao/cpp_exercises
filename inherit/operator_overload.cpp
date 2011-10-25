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

        CComplex operator + (CComplex &temp);
        CComplex operator + (double temp);
        
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

int main(int argc, const char *argv[])
{
    CComplex par1(3.0, 5.8);
    CComplex par2(4.0, 6.8);
    
    CComplex par3 = par1 + par2;
    CComplex par4 = par1 + 4.7;
  
    par3.print();
    par4.print();
    
    return 0;
}
