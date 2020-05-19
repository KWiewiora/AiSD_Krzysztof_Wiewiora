#include <iostream>
#include <random>

struct node {
    int value;
    node *next;
    
    node(int x, node *n = nullptr) : value(x), next(n) {}
};

void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
    node **t1=&t;

    while(*t1)
    {
        t1 = &((*t1)->next);
    }

    *t1=new node(x);
}

node print_list(node *t) //rekurencyjnie
{
    if(t)
    {
        std::cout << t->value << " ";
        print_list(t->next);
    }
    return 0;
}

node insertion_sort (node *L)
{
    if(!L || !L->next)
    {
        return *L;
    }

    node *sorted = nullptr;

    while (L)
    {
        node *head = L;
        node **trail = &sorted;
        L = L->next;

        while (!(*trail == nullptr || head->value < (*trail)->value))
        {
            trail = &(*trail)->next;
        }

        head->next = *trail;
        *trail = head;
        print_list(sorted);
        std::cout << std::endl;
    }
    return *sorted;
}


int main()
{
    node *L = nullptr;

    insert(L, 6);
    insert(L, 5);
    insert(L, 7);
    insert(L, 1);
    insert(L, 2);
    insert(L, 4);
    insert(L, 3);
    std::cout << "\nPrzed sortowaniem:\n";
    print_list(L);
    std::cout << std::endl;

    node L_after = insertion_sort(L);
    std::cout << "\nPo sortowaniu: \n";
    print_list(&L_after);

    return 0;
}
