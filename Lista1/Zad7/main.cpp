#include <iostream>
#include <map>
#include <string>
#include <fstream>

std::map<char, int> liczZnaki(std::string nazwa)
{
    std::fstream plik(nazwa);
    std::string linia;

    std::map<char, int> rezultat;

    while (plik.is_open() && !plik.eof())
    {
        //linia to tablica charów, więc iteruje po niej i zapisuje do słownika (map)
        std::getline(plik, linia);
        for (auto znak : linia)
            rezultat[znak] += 1;
    }
    plik.close();
    return rezultat;
}

int main(int argc, char *argv[])
{

    if (argv[1])
    {
        std::map<char, int> wynik = liczZnaki(argv[1]);
        for (auto znak : wynik)
        {
            std::cout << znak.first << " -> " << znak.second << std::endl;
        }
    }
    else
    {
        return 0;
    }
}
