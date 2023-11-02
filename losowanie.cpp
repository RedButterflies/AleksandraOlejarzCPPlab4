//
// Created by szyns on 01.11.2023.
//
#include "losowanie.h"
#include<list>
#include<random>
#include <ctime>
using namespace std;

Losowanie::Losowanie() {
    srand(static_cast<unsigned>(time(nullptr)));
    this->n = rand()%10;
}
list<int> Losowanie::funkcja1(int n) {
    srand(static_cast<unsigned>(time(nullptr)));
    for(int i=0;i<n;i++)
    {
        int liczba = rand()%201-100;
        if(liczba<0){
        lista.push_back(liczba);
        }
        else
        {
            lista.push_front(liczba);
        }
    }
    return lista;

}
vector<int> Losowanie::funkcja2(int n) {
    srand(static_cast<unsigned int>(time(nullptr))+5);
    for(int i=0;i<n;i++)
    {
        int liczba = rand()%201-100;
        if(liczba<0){
            vektor.push_back(liczba);
        }
        else
        {
            vektor.insert(vektor.begin(),liczba);

        }
    }
    return vektor;

}



