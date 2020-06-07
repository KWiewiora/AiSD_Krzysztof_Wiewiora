#include <iostream>
#include <string>
#include <algorithm>



template<typename T,size_t size = 1000>
class HashMap final
{
    private:
        struct node;
    public:
        HashMap(){};
        void insert(const T& key)
        {   
            //hashuje wartosc dana jako parametr
            const size_t hash = hash_str(key);
            if(hash >= size)
                return;
            node* nd = array[hash];//bierzemy wskaznik elementu z tablicy dla hasha
            if(!nd)//jesli wskaznik pusty yo tworzymy nowego noda 
                array[hash] = new node(hash);
            else//jelsi nie jesy puste index w tablicy to srednio...
            {
                node* prev = nullptr;
                while(nd)//iterujemy az do konca linkowanej listy
                {
                    prev = nd;
                    nd = nd->next_node;
                }
                nd = new node(hash);//tworzymy nowy node na koncu
                prev->next_node = nd;//ustawiamy wksaznik przedostaniego na nowo powstaly ostatni
            }
        }
        void remove(const T& key)
        {
            const size_t hash = hash_str(key);// hashujemy key-> mamy index
            if(hash >= size) //sprawdzamy czy index jest w tablicy
                return;
            node* nd = array[hash];//szukamy wskaznika noda dla tego indexu
            if(!nd)
                return; //jak nic nie ma to konczymy bo nie ma co usuwac
            else
            {
                if(nd && nd->key == hash)//jak jest jakis node i to ten co go szuakmy to usuwamy
                {
                    array[hash] = nd->next_node;
                    delete nd;
                    return;
                }
                node* prev = nullptr;
                while(nd && hash != nd->key)//ale jak jest node ale nie ten co chcemy to musimy szuakc dalej w lancuchu
                {
                    prev = nd;
                    nd = nd->next_node;
                }
                prev->next_node = nd->next_node;//przepinamy wskazniki
                delete nd;
            }
        }
        node* find(const T& key)
        {
            const size_t hash_key = hash_str(key);
            node* nd = array[hash_key];
            while(nd && hash_key != nd->key)
                nd = nd->next_node;
            return nd;
        }
        size_t hash_str(const std::string& s)
        {
            size_t h = 0; 
            for(const char& c : s)
                h = h * 33 ^ c;
            return h % 1000;
        }
        ~HashMap()
        {
            for(size_t i = 0; i < size; ++i)
                while(array[i])
                {
                    node* prev = array[i];
                    array[i] = array[i]->next_node;
                    delete prev;
                }  
        };
    private:
        struct node
        {
            explicit node(const size_t& key,node*const nd = nullptr) : key{key},next_node{nd} {}
            size_t key;
            node* next_node;
            ~node(){}
        };
        node* array[size] = {nullptr};
};

std::string random_string(const size_t& length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n(str.begin(),length,randchar);
    return str;
}

int main()
{
    HashMap<std::string> hTable;
    std::string arr[1000];
    for(size_t i = 0; i < 1000; ++i)
        arr[i] = random_string(i);
    for(size_t i = 0; i < 1000; ++i)
        hTable.insert(arr[i]);
    for(size_t i = 0; i < 200; ++i)
        hTable.remove(arr[i]);
    std::cout << hTable.find(arr[201])->key << std::endl;
}