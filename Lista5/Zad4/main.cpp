#include <iostream>
#include <cmath>
#include <random>

void rsort(int t[], int n, int b[])
{
    int u=1000;
    int max=2;
    int *t_orig=t;
    int tura=0;
    for(int r=1;r<=max;r*=u)
    {   std::cout<<"tura "<< ++tura<<std::endl;
        if(r==1)
        {
            for(int i=0;i<n;i++)
                if(t[i]>max) max=t[i];
            u=ceil(sqrt(max));
            if(u<100)
                u=100;
        }
        int ile[u];
        for(int i=0;i<u;i++) //zerowanie liczników
            ile[i]=0;
        for(int i=0;i<n;i++)  //zliczanie
            ile[t[i]/r%u]++;
        for(int i=1;i<u;i++)  //akumulacja
            ile[i]+=ile[i-1];
        for(int i=n-1;i>=0;i--)  // wpis do bufora
            b[--ile[t[i]/r%u]]=t[i];
        int *s;s=t;t=b;b=s;
    }
    if(t!=t_orig)
        for(int i=0;i<n;i++)    // przepisanie
            t_orig[i]=t[i];
}

int main()
{
    int n = 23;
    int t[23] = {1,34,123,321,432,132,543,651,91,32,987,910,643,641,12,342,498,987,965,122,121,431,350};
    int *b=new int[n];
    rsort(t, n, b);
    for (int i=0;i<n;i++)
        std::cout << t[i] << ", ";
    return 0;
}

