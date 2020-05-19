#include <iostream>

struct lnode // drzewo bez wskaźnika na rodzica
{
    int x;
    lnode *next;

    lnode(int x0, lnode *n = nullptr) : x(x0), next(n) { }
};

void insert(lnode *&t, int x) // wstawianie (nierekurencyjnie)
{
    lnode **t1 = &t;
    while (*t1)
    {
        t1 = &((*t1)->next);
    }
    *t1 = new lnode(x);
}

void inorder(lnode *t) // wypisanie kluczy w porządku "in order"
{
    if (t)
    {
        inorder(t->next);
        std::cout << t->x << " ";
    }
}

void reverse(lnode *&L)
{
    lnode *previous = NULL;
    lnode *next = NULL;
    while (L)
    {
        next = L->next;
        L->next = previous;
        previous = L;
        L = next;
    }
    L = previous;
}

int main()
{


    // tworzymy listę node'ów
    lnode *t = nullptr;
    for (auto i = 0; i < 10; i++)
    {
        insert(t, i);
    }

    // wyświetlamy listę
    std::cout << "In order: " << std::endl;
    inorder(t);
    std::cout << std::endl;

    // wyświetlamy odwróconą
    std::cout << "Reversed: " << std::endl;
    reverse(t);
    inorder(t);

    return 0;
}
