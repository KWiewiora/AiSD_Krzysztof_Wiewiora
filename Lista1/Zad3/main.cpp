#include <iostream>

// schemat hornera - wyciagamy z nawiasu kolejne x-y, dzieki temu oszczedzamy na mnozeniach
double oblicz(double a[], int n, double x)
{
    double wynik = a[0];
    for (int i = 1; i <= n; i++)
    {
        wynik = wynik*x + a[i];
    }
    return wynik;
}
int main()
{ 
    double a[4] = {3,(-8),2,5};
    std::cout << oblicz(a,3,4) << std::endl;
    return 0;
}