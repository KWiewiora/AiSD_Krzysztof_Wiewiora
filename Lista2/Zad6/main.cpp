#include <iostream>

int count = 0;

struct lnode
{
    int x;
    lnode *next;

    lnode(int x0, lnode *n = nullptr) : x(x0), next(n) { }
};

void inorder(lnode *t) // wypisanie kluczy w porządku "in order"
{
    if (t)
    {
        inorder(t->next);
        std::cout << t->x << " ";
    }
}

void insert(lnode *&t, int x) // wstawianie (nierekurencyjna)
{
    lnode **t1 = &t;

    while (*t1)
    {
        t1 = &((*t1)->next);
    }
    
    *t1 = new lnode(x);
}

lnode *merge(lnode *L1, lnode *L2)
{
    // sprawdzamy czy któraś z list nie jest pusta
    if (!L1)
    {
        count++;
        return L2;
    }
    else if (!L2)
    {
        count++;
        return L1;
    }

    // układamy i łaczymy listy
    if (L1->x < L2->x)
    {
        count++;
        L1->next = merge(L1->next, L2);
        return L1;
    }
    else
    {
        count++;
        L2->next = merge(L1, L2->next);
        return L2;
    }
}

int main()
{

    lnode *L1 = nullptr;
    lnode *L2 = nullptr;
    lnode *result = nullptr;

    for (auto i = 0; i < 10; i++)
    {
        insert(L1, i);
        insert(L2, i * 5);
    }

    std::cout << "Lista 1: " << std::endl;
    inorder(L1);

    std::cout << "\nList 2: " << std::endl;
    inorder(L2);

    result = merge(L1, L2);
    std::cout << "\nMerged: " << std::endl;

    inorder(result);
    std::cout << "\nIlość porównań: " << count << std::endl;

    return 0;
}
