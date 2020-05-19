#include <iostream>
#include <random>

int countNull = 0;

struct nodeBST // drzewo bez wskaźnika na rodzica
{
    int x;
    nodeBST *left;
    nodeBST *right;

    nodeBST(int x0, nodeBST *l = NULL, nodeBST *r = NULL) : x(x0), left(l), right(r) { }
};

void insertBST(nodeBST *&t, int x) // wstawianie (nierekurencyjna)
{
    nodeBST **t1 = &t;

    while (*t1)
    {
        if (x < (*t1)->x)
        {
            t1 = &((*t1)->left);
        }
        else
        {
            t1 = &((*t1)->right);
        }
    }

    *t1 = new nodeBST(x);
}

int hBST(nodeBST *t) // wysokość drzwa BST 
{
    return !t ? 0 : 1 + std::max(hBST(t->left), hBST(t->right));
}

void displayBST(nodeBST *t, char z1 = ' ', char z2 = ' ') // in order z nawiasami
{
    if (t)
    {
        std::cout << z1;
        displayBST(t->left, '(', ')');
        std::cout << t->x;
        displayBST(t->right, '[', ']');
        std::cout << z2;
    }
    else{
        countNull++;
    }
}

int main()
{

    nodeBST *L = nullptr;

    // losowe liczby
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0, 100};

    for (auto i = 0; i < 100; i++)
    {
        int r = generate(gen);
        insertBST(L, i);
    }

    displayBST(L);

    std::cout << "\n\nWysokość to: " << hBST(L) << std::endl;
    std::cout << "Ilość wskazników NULL: " << countNull << std::endl;

    return 0;
}
