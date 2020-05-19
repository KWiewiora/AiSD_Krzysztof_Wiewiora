#include <iostream>

constexpr int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

void shift(int a[], int n)
{
    int temp = a[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = temp;
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
void shiftk(int a[], int n, int k)
{
    k %= n;

    if (k == 0)
    {
        return;
    }

    int i = 0;
    while (i < gcd(n, k))
    {
        int x = a[i];
        int j = i + k;

        if (j >= n)
        {
            j -= n;
        }

        while (j != i)
        {
            int y = a[j];
            a[j] = x;
            x = y;
            j += k;
            if (j >= n)
            {
                j -= n;
            }
            print(a, n);
        }
        a[i++] = x;
        print(a, n);
    }
}
void shiftArr(int a[], int n, int k = 0)
{
    for (int i = 0; i < k; i++)
    {
        shift(a, n);
    }
}

int main()
{

    int tabSize = 9;
    int a[tabSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(a, tabSize);
    shiftk(a, tabSize, 3);
    print(a, tabSize);

    return 0;
}
