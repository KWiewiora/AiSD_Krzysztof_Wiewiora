#include <iostream>
#include <vector>
#include <cmath>

void sito_erastotenesa(int n)
{
    std::vector<bool> prime(n, true);
    prime[0] = false;
    prime[1] = false;

    //algorytm sita erastotenesa
    for (int k = 2; pow(k, 2) < n; ++k)
    {
        //jeżeli jest pierwszą
        if (prime[k])
        {
            for (int j = k * k; j < n; j += k)
            {
                //wykreśl wszystkie jej wielokrotnosci
                prime[j] = false;
            }
        }
    }

    for (int k = 0; k < n; ++k)
    {
        //wzystkie pierwsze które zostawy wypisz na ekran
        if (prime[k])
        {
            std::cout << k << std::endl;
        }
    }
}

int main()
{
    sito_erastotenesa(100);

    return 0;
}
