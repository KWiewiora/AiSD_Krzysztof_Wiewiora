#include <iostream>
#include <vector>

void max_min(int a[], int n)
{
    int min,max;
    int i;

    //ustawiamy początkową wartość do porównywania
    if (n % 2 == 0)
    {
        if (a[0] > a[1])
        {
            max = a[0];
            min = a[1];
        }
        else
        {
            max = a[1];
            min = a[0];
        }

        //ustawiamy początkowy index pętli
        i = 2;
    }
    // jezeli tablica jest nieparzysta to zainicjalizuj pierwszy element jako min i max jednocześnie
    else
    {
        min = a[0];
        max = a[0];
        //początkowy index ustawiamy
        i = 1;
    }

    //pętla while która porównuje elementy z max i min do tej pory
    while (i < n - 1)
    {
        if (a[i] > a[i + 1])
        {
            if (a[i] > max)
            {
                max = a[i];
            }

            if (a[i + 1] < min)
            {
                min = a[i + 1];
            }
        }
        else
        {
            if (a[i + 1] > max)
            {
                max = a[i + 1];
            }

            if (a[i] < min)
            {
                min = a[i];
            }
        }
        //inkrementujemy co dwa ponieważ porównujemy dwa elementy na raz
        i += 2;
    }

    std::cout << "WYNIKI: \n max: " << max << "\n min: " << min << std::endl;
}

int main()
{
    int a[6] = {4, 16, 23, 15, 8, 42};
    max_min(a, 6);

    return 0;
}
