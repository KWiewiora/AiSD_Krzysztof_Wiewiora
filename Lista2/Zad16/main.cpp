#include <iostream>

#include <stack>

struct node
{
    explicit node(const int &k, node *const n = nullptr) : key{k}, left{nullptr}, right{nullptr}, parent{n} {}
    int key;
    node *left;
    node *right;
    node *parent;
};
namespace ASD
{
class iterator
{
public:
    explicit iterator(node *const root = nullptr) : current{root} {}
    ~iterator() {}
    iterator &operator=(const iterator &it)
    {
        current = it.current;
        return *this;
    }
    iterator &operator++()
    {
        if (current->right) 
        {
            current = current->right;
            while (current->left)
                current = current->left;
            return *this;
        }
        while (1)
        {
            if (!current->parent) 
            {
                current = nullptr;
                return *this;
            }
            if (current == current->parent->left)
            {
                current = current->parent;
                return *this;
            }
            current = current->parent;
        }
    }
    iterator operator++(int)
    {
        iterator temp = *this;
        ++(*this);
        return temp;
    }
    int &operator*() const
    {
        return current->key;
    }
    bool operator!=(const iterator &it) const { return current != it.current; }

private:
    node *current;
};
} // namespace ASD
ASD::iterator begin(node *root) //zaczyna od lewej
{
    while (root && root->left)
        root = root->left;
    return ASD::iterator(root);
}
ASD::iterator end(node *root)
{
    return ASD::iterator(); 
}
void insert(node *&root, const int &key)
{
    node **current = &root, *prev = nullptr;
    while (*current)
    {
        prev = *current;
        current = key > (*current)->key ? &(*current)->right : &(*current)->left;
    }
    *current = new node(key, prev);
}
node *find(node *nd, const int &key)
{
    while (nd && nd->key != key)
        nd = key > nd->key ? nd->right : nd->left;
    return nd;
}
void remove(node *&root, const int &key)
{
    node **nde = &root;
    while ((*nde) && (*nde)->key != key)
        nde = key > (*nde)->key ? &(*nde)->right : &(*nde)->left;
    auto &nd = *nde;
    if (nd)
    {
        if (nd->right && nd->left) //dwójka dzieci
        {
            node **child = &(nd->right);
            bool hasLeftChild = false;

            while ((*child)->left)
            {
                child = &(*child)->left;
                hasLeftChild = true;
            }
            nd->key = (*child)->key; 
            if ((*child)->right)     
            {
                node *right_child = (*child)->right;
                node *parent = (*child)->parent;
                delete *child;
                *child = nullptr;
                hasLeftChild ? parent->left = right_child : parent->right = right_child;
            }
            else
            {
                delete *child;
                *child = nullptr;
            }
        }
        else if (!nd->right && !nd->left) //liść
        {
            delete nd;
            nd = nullptr;
        }
        else if (!nd->left) // ma prawe dziecko
        {
            node *temp = nd->right;
            node *parent = nd->parent;
            delete nd;
            nd = temp;
            nd->parent = parent;
        }
        else
        {
            node *temp = nd->left;
            node *parent = nd->parent;
            delete nd;
            nd = temp;
            nd->parent = parent;
        }
    }
}
void inorder(const node *const root)
{
    if (root)
    {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}
void g(node *root)
{
    root->key += 5;
}
void inorder_do(node *root, void f(node *))
{
    node *prev = nullptr;
    while (root)
    {
        if (prev == root->parent)
        {
            if (root->left)
            {
                prev = root;
                root = root->left;
                continue;
            }
            else
                prev = nullptr;
        }
        if (prev == root->left)
        {
            f(root);
            if (root->right)
            {
                prev = root;
                root = root->right;
                continue;
            }
            else
                prev = nullptr;
        }
        if (prev == root->right)
        {
            prev = root;
            root = root->parent;
        }
    }
}
void destroy(node *&root)
{
    if (root)
    {
        destroy(root->right);
        destroy(root->left);
        delete root;
        root = nullptr;
    }
}
constexpr size_t height(const node *const root) //rekurencyjnie
{
    return root ? 1 + std::max(height(root->left), height(root->right)) : 0;
}
size_t height_it(node *root) //iteracyjnie
{
    size_t height{};
    if (!root)
        return height;
    std::stack<node *> s;
    s.emplace(root);
    for (;;)
    {
        size_t counter = s.size();
        if (!counter)
            return ++height;
        ++height;
        while (counter--)
        {
            node *n = s.top();
            s.pop();
            if (n->left)
                s.emplace(n->left);
            if (n->right)
                s.emplace(n->right);
        }
    }
}

int main()
{


    node *root = nullptr;
    insert(root, 5);
    insert(root, 2);
    insert(root, 10);
    insert(root, 7);
    insert(root, 6);
    insert(root, 15);
    insert(root, 14);
    insert(root, 13);
    insert(root, 16);

    inorder(root); 
    std::cout << std::endl;
    for (ASD::iterator i = begin(root); i != end(root); ++i) 
    {
        std::cout << *i << " ";
    }

    destroy(root);

    return 0;
}
