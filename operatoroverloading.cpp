#include<iostream>
using namespace std;
class complex{
private:
    float real;
    float imag;
public:
    complex(){
        real=0;
        imag=0;
    }
    complex(float r,float i)
    {
        real=r;
        imag=i;
    }
    ~complex(){

    }
    void display(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    complex operator+(complex c){
        return complex(real+c.real,imag+c.imag);
    }
    complex operator-(complex c){
        return complex(real-c.real,imag-c.imag);
    }
    complex operator*(complex c){
        float r=real*c.real-imag*c.imag;
        float i=real*c.real+imag*c.real;
        return complex(r,i);

    }


};
int main(){
    complex c1(4,5),c2(2,3);
    cout<<"/nfirst complex number:";
    c1.display();
    cout<<"/second complex number:";
    c2.display();
    complex sum=c1+c2;
    cout<<"/nsum";
    sum.display();

    complex diff=c1-c2;
    cout<<"/ndifferance";
    diff.display();

    complex prod=c1*c2;
    cout<<"/nproduct";
    prod.display();
    return 0;
    
}
//output
//PS C:\Users\poona\OneDrive\Desktop\pt123> g++ operatoroverloading.cpp -o operatoroverloading
//PS C:\Users\poona\OneDrive\Desktop\pt123> ./operatoroverloading
///nfirst complex number:4+5i
//second complex number:2+3i
//nsum6+8i
//ndifferance2+2i
//nproduct-7+18i