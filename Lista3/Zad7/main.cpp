#include <iostream>
#include <random>

struct Node  // drzewo bez wskaźnika na rodzica
{ 
    int x;
    Node* left;
    Node* right;
    
    Node(int x0, Node* l=NULL, Node* r=NULL)
    :x(x0), left(l), right(r)
    {}
};

void insert_recursive(Node *& t, int x) // wstawianie (rekurenycjnie)
{
    if(!t)
        t=new Node(x);
    else
        if(x<t->x)
            insert_recursive(t->left,x);
        else
            insert_recursive(t->right,x); 
}

void inorder(Node *t)  // wypisanie kluczy w porządku "in order"
{
    if(t)
    {
        inorder(t->left);
        std::cout<<t->x<<" ";
        inorder(t->right);
    }
}


int find_level(Node *root, double v)
{
    Node *n = root;
    int level = 1;
    while (n && n->x != v)
    {
        level++;
        if (v < n->x)
            n = n->left;
        else n = n->right;
    }
    return n ? level : 0;
}

int main()
{

    Node *root = nullptr;

    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{1,100};
    int liczba = 0;
    int los = generate(gen);
    for (auto i=0; i<10; i++)
    {
        int r = generate(gen);
        if (i == los/10)
            liczba = r;
        insert_recursive(root, r);
        std::cout << r << " ";
    }
    std::cout << "\nLiczba: " << liczba << " Poziom: " << find_level(root, liczba) << std::endl;

    return 0;
}
