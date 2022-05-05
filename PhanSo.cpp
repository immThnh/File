#include<fstream>
#include<iostream>
using namespace std;

class PhanSo
{
private:
    int mauso;
    int tuso;
public:

    friend istream& operator >> (istream& is, PhanSo &ps)
    {
        cout <<"NHAP TU SO: ";
        is >> ps.tuso;
        cout << "NHAP MAU SO: ";
        is >> ps.mauso;
        return is;
    }

    friend ostream& operator << (ostream& os, PhanSo ps)
    {
        os << ps.tuso << "/" << ps.mauso << endl;
        return os;
    }

    PhanSo operator+ (const PhanSo &ps)
    {
        PhanSo result;
        result.tuso = this -> tuso * ps.mauso + this -> mauso * ps.tuso;
        result.mauso = this -> mauso * ps.mauso; 
    
        return result;
    }
    PhanSo operator- (const PhanSo &ps)
    {
        PhanSo result;
        result.tuso = (this -> tuso) * ps.mauso - this -> mauso * ps.tuso;
        result.mauso = this -> mauso * ps.mauso; 
    
        return result;
    }
    PhanSo operator*(const PhanSo &ps)
    {
        PhanSo result;
        result.tuso = this -> tuso * ps.tuso;
        result.mauso = this-> mauso * ps.mauso;
        return result;
    }
    PhanSo operator/ (const PhanSo &ps)
    {
        PhanSo result;
        result.tuso = this -> tuso * ps.mauso;
        result.mauso = this -> mauso * ps.tuso;
        return result;
    }
    
    PhanSo& operator= (const PhanSo &ps)
    {
        if(this == &ps)
        {
            return *this;
        }
        else 
        {
            this -> tuso = ps.tuso;
            this -> mauso = ps.mauso;
        }
        return *this;
    }
    
    PhanSo& operator+= (const PhanSo &ps)
    {
        this -> tuso = this -> tuso * ps.mauso + this -> mauso * ps.tuso;
        this -> mauso = this -> mauso * ps.mauso; 
        return *this;
    }
    PhanSo& operator -= (const PhanSo &ps)
    {
        this -> tuso = (this -> tuso) * ps.mauso - this -> mauso * ps.tuso;
        this -> mauso = this -> mauso * ps.mauso; 
        return *this;
    }
    
    PhanSo& operator *= (const PhanSo &ps)
    {
        this -> tuso = this -> tuso * ps.tuso;
        this -> mauso = this-> mauso * ps.mauso;
        return *this;
    }
    
    PhanSo& operator /= (const PhanSo &ps)
    {
        this -> tuso = this -> tuso * ps.mauso;
        this -> mauso = this -> mauso * ps.tuso;
        return *this;
    }
    
    bool operator== (const PhanSo &ps)
    {
        if((this -> tuso * ps.mauso) == (ps.tuso * this -> mauso))
        {
            return true;
        }
        return false;
    }
    
    PhanSo operator++ (int x)
    {
        PhanSo temp(*this);
        this -> tuso += this -> mauso;
        return temp;
    }
     PhanSo& operator++ ()
    {
        
        this -> tuso += this -> mauso;
        return *this;
    }
    
    

};
