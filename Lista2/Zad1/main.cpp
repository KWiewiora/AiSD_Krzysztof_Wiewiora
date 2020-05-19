#include <iostream>
#include <cmath>

int szukaj(int a[], int size, int number)
{
    int min = 0;
    int max = size - 1;

    while (max >= min)
    {
        int m = std::floor(max + min) / 2;
        if (number == a[m])
        {
            return m;
        }
        else if (number > a[m])
        {
            min = m + 1;
        }
        else
        {
            max = m - 1;
        }
    }
    return -1;
}

int main()
{
 

    // w posortowanej ilość wyszukiwan n-1, porównuje każdy z każdym
    int a[12] = {5, 9, 10, 70, 80, 93, 103, 105, 121, 170, 201,220};

    int count = szukaj(a, 12, 80);

    std::cout << "Ilość wyszukiwań w posortowanej: " << count << std::endl;

    return 0;
}
