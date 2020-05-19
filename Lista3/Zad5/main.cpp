#include <iostream>

void merge (int start, int mid, int end, int arr[], int *t)
{
    int i,j,q;
    //wsadzamy otrzymane dane do tymczasowej tablicy
    for (i=start; i<=end; i++)
    {
        t[i] = arr[i];
    }
    i = start;
    j = mid + 1;
    q = start;

    //wsadzamy z powrotem dane do oryginalnej tablicy juz posortowane
    while (i<= mid && j<= end)
    {
        if(t[i] < t[j])
        {
            arr[q++] = t[i++];
        }
        else
        {
            arr[q++] = t[j++];
        }
    }
    //kiedy j doszlo do konca a i jeszcze nie jest w polowie
    while (i <= mid)
    {
        arr[q++] = t[i++];
    }
}

void mergesort(int start, int end, int arr[])
{
    int *t = new int[end + 1];
    int mid;
    if(start < end)
    {
        mid = (start + end)/2;
        //lewa strona
        mergesort(start, mid, arr);
        //prawa strona
        mergesort(mid+1, end, arr);
        //mergowanie 
        merge(start, mid, end, arr, t);
    }
    delete[] t;
}


int main()
{

    const int N = 10;
    int arr[N] = {1, 4, 2, 7, 6, 9, 3, 8, 5, 0};
    
    mergesort(0, N - 1, arr);
    
    std::cout<< "Merge-sort na tablicy" << std::endl;
    
    for (int i = 0; i<N; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
