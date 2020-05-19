#include <iostream>

struct lnode
{
    int key;
    lnode * next;

    lnode(int k, lnode * n = nullptr) : key(k), next(n) 
    {}
};

int suma(lnode * L)
{
    int res = 0;
    while (L != nullptr)
    {
        res += L->key;
        L = L->next;
    }
    return res;
}

int nty(int n, lnode * L)
{
    if (L == nullptr)
        return 0;
    if (n == 0)
        return L->key;

    for (int i = 1; i < n + 1; i++)
    {
        if (L->next == nullptr)
            return 0;

        L = L->next;
    }
    return L->key;
}

lnode * filter(lnode * L)
{

    if (L->next == nullptr)
    {
        if (L->key < 0)
        {
            delete L;
            return nullptr;
        }

        return L;
    }

    lnode * res = L;
    lnode * prev = L;

    while (res->key < 0)
    {
        res = res->next;
        L = L->next;
        delete prev;
        prev = res;

        if (res == nullptr)
            return nullptr;
    }

    L = L->next;

    while (L != nullptr)
    {
        if (L->key < 0)
        {
            prev->next = L->next;
            delete L;
            L = prev;
        }
        else
            prev = prev->next;
        
        L = L->next;
    }

    return res;
}

void wypisz(lnode * L)
{
    std::cout << "elementy listy: ";
    while (L != nullptr)
    {
        std::cout << L->key << " ";
        L = L->next;
    }
    std::cout << "\n";
}

int main()
{
    lnode * L = new lnode(7);
    L = new lnode(8, L);
    L = new lnode(100, L);
    L = new lnode(-5, L);
    wypisz(L);
    std::cout << "suma: " << suma(L) << std::endl;
    std::cout << "element 0: " << nty(0, L) << std::endl;
    std::cout << "element 1: " << nty(1, L) << std::endl;
    std::cout << "element 2: " << nty(2, L) << std::endl;
    std::cout << "element 3: " << nty(3, L) << std::endl;
    
    std::cout << "Po filtracji lista wygląda tak: " << std::endl;
    wypisz(filter(L));

    return 0;
}