#include <iostream>
unsigned long
int hash(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }
int main()
{
    unsigned char t;
    t = 97;
    std::cout << hash(&t) << std::endl;
    return 0;
}
