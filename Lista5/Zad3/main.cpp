

#include <iostream>
#include <cmath>
#include <random>

int* counting_sort(int t[], int n, int c)
{
    int count_arr[10] = {0};
    int divider = pow(10,c);
    //liczy elementy
    for (int i=0; i<n; i++)
        count_arr[(t[i]/divider)%10]++;
    
    //zmienia liczenie by posiadal poprawna pozycje elementy w output arr
    for (int j=1; j<=10; ++j)
        count_arr[j] += count_arr[j-1];
    
    int output_arr[n];
    for (int k=n-1; k>=0; k--)
    {
        int curr = (t[k]/divider)%10;
        output_arr[count_arr[curr]-1] = t[k];
        count_arr[curr]--;
    }
    
    for (int i = 0; i<n; i++)
        t[i] = output_arr[i];
    
    return t;
}

int main()
{

    int arr_size = 20;
    int t[arr_size];
    std::cout << "PRZED:\n";
    for (int i=0; i<arr_size ; i++)
    {
        t[i] = rand() % 100 + 1;
        std::cout << t[i] << ", ";
    }
    std::cout << "\n";
    std::cout << "PO:\n";
    int *sorted_arr = counting_sort(t, arr_size, 2);
    sorted_arr = counting_sort(sorted_arr, arr_size, 1);
    sorted_arr = counting_sort(sorted_arr, arr_size, 0);
    for (int i=0; i<arr_size; i++)
    {
        std::cout << sorted_arr[i] << ", ";
    }
    return 0;
}
