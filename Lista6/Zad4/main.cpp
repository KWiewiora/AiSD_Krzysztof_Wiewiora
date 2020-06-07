#include <iostream>
#include <random>
void insert1(int x,int arr[]){
    int hash= x%16;
    
    if (arr[hash] == 0){
        arr[hash]=x;
        
        return;
    }
    while (arr[hash] != 0){
        hash =(hash+1)%16;
        
    }
   
    arr[hash]=x;
    return;
}

void insert2(int x,int arr[]){
    int hash= x%16;
    if (arr[hash] == 0){
        arr[hash]=x;
        
        return;
    }
    int hash2 =(10*x+1)%16;
    int hash1=hash;
    int i=1;
    while (arr[hash] != 0){
        hash2=hash2 *i;
        i++;
        hash=(hash1+hash2)%16;
        
    }
    
    arr[hash]=x;
    return;
}

int main(){
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{1,100};
    int liczby[11] = {3, 20, 25, 98, 120, 213, 2131, 99, 131, 9, 129};
    int hash_array[16] = {0};
    int hash_array2[16] = {0};
 
    for (int i = 0; i < 11 ; i++) {
        insert1(liczby[i],hash_array);
        insert2(liczby[i],hash_array2);
    }

    std::cout << "haszowanie liniowe :\n" ;
    for (int i = 0; i < 16 ; i++) {
        std::cout<<hash_array[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "haszowanie dwukrotne :\n" ;
    for (int i = 0; i < 16; i++) {
        std::cout<<hash_array2[i] << " ";
    }
    std::cout << "\n";
    return 0;
}