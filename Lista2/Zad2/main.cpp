#include <iostream>

// mamy porównanie n-1
int max_1(int t[], int n)
{
    int x = t[n];
    while (n--)
    {
        if (x < t[n])
        {
            x = t[n];
        }
    }

    return x;
}

// funkcja pomocnicza do sprawdzenia która liczba jest większa
int max_1(int a, int b) { return a > b ? a : b; }

// mamy n porównań 
int max_2(int t[], size_t n)
{
    // iteruj tak długo aż skończą się liczby i szukaj
    if (n)
    {
        return max_1(t[n], max_2(t, n - 1));
    }
    return -1;
}

int max_3(int t[], size_t begin = 0, size_t end = 0)
{
    if (begin == end)
    {
        return t[end];
    }

    // maksymalne zagłebienie jest logarytmem bo dzieli dane na połowy i szukamy tak jak w binary serczu
    // czyli log(n) porównan
    int m = (begin + end) / 2;
    int left_max = max_3(t, begin, m);
    int right_max = max_3(t, m + 1, end);

    if (left_max > right_max)
    {
        return left_max;
    }

    return right_max;
}

int main()
{

    int tabSize = 10;
    int tab[tabSize] = {23, 31, 241, 31, 331, 55, 75, 3, 7, 3};
    
    int max_num_1 = max_1(tab, tabSize);
    int max_num_2 = max_2(tab, tabSize);
    int max_num_3 = max_3(tab, 0, tabSize);

    std::cout << max_num_1 << " = " << max_num_2 << " = " << max_num_3 << std::endl;

    return 0;
}
