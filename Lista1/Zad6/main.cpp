#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
//funkcja pobierająca dane z plików
std::vector<int> pobierz(std::string file)
{
    std::vector<int> v;
    std::ifstream plik(file);
    int wartosc;

    while (plik >> wartosc)
    {
        v.push_back(wartosc);
    }

    return v;
}

// funkcja obliczająca dany wektor
void zapisz(std::vector<int> a, std::vector<int> b)
{
    std::vector<int> result;
    int newSize;

    if (!(a.empty() && b.empty()))
        newSize = a.size() + b.size() - 1;
        // wypełniamy vector zerami
        result.resize(newSize, 0);

    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b.size(); j++)
            result[i + j] += a[i] * b[j];

    //dodaj na początek stopień wielomianu
    result.insert(result.begin(),newSize);
    std::ofstream plik("c.txt");

    for(auto x: result){
        plik << x << " ";
    }

    std::cout << "Plik c.txt został stworzony" << std::endl;
}


int main()
{

    std::vector<int> plikA = pobierz("a.txt");
    std::vector<int> plikB = pobierz("b.txt");

    //pobieramy pierwsza wartość jako stopień i wyrzucamy ją z wektora wspołczynników
    plikA.erase(plikA.begin());
    plikB.erase(plikB.begin());

    zapisz(plikA, plikB);


    return 0;
}
