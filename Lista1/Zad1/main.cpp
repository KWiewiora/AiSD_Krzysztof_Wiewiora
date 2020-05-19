#include <iostream>

double rekurencja(double x, int n){   
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return x;
    }
    else if(n % 2 == 0){
        return rekurencja(x*x , n/2);
    }
    else{
        return x * rekurencja(x*x, (n-1)/2);
    }
}   
double iteracja(double x, int n){
    double wynik = 1.0;
    while (n > 0){
        if( n % 2 == 1){
            wynik *= x;
        }
        x *= x;
        n /= 2;
    }
    return wynik;
}
int main()
{
   std::cout << rekurencja(4,4) << std::endl; 
   std::cout << iteracja(4,4) << std::endl;
}