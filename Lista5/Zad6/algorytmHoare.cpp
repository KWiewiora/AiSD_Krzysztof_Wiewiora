int partition (int n, double t[])
{
    int k = -1;
    double x = t[n / 2];
    while (true)
    {
        while (t[--n] > x);
        while (t[++k] < x);
        if (n > k)
        {
            double y = t[k];
            t[k] = t[n];
            t[n] = y;
        }
        else
            return k;
    }
}

int kty(int n, double t[], int k)
{
    int L = partition(n,t);
    if (k<=L)
        return kty(L,t,k);
    else
        return kty(n-L, t+L, k-L);
}
