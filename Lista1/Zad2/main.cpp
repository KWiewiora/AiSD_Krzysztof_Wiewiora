#include <iostream>
 double f(double x)
 {
     return 5*x - 3;
 }
double bisekcja(double a,double b)
{
    double c;
    if(f(a) * f(b) >= 0)
    {
        std::cout<<"niepoprawne a i b";
        return 0;
    }
 
    c=a;
 
    while ((b-a) >= 0.01) //robi sie zanim nie dojdzie do bliskiego zeru
    {
        c = (a+b)/2;
        if (f(c) == 0.0){
            
            break;
        }
        else if (f(c)*f(a) < 0){
               
                b=c;
        }
        else{
                
                a=c;
        }
    }
    return c;
}

int main()
{
    double a = -2;
    double b = 2;
    std::cout << bisekcja(a,b) << std::endl;

    return 0;
}
