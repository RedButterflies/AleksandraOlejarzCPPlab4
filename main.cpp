#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include "Even.h"
#include "student.h"
#include "compare.h"
#include "losowanie.h"
#include "City.h"
#include "Citizen.h"
#include <list>
using namespace std;

template <typename T>

void show(T &con)
{
    for(auto it=con.begin( );it!=con.end( ); it++)
        cout<<*it<<" ";
    cout<<endl;
}
void print(int& el)
{
    cout<<el<<"   ";
}
void add10(int &el)
{
    el=el+10;
}
bool isEven(int x)
{
    if (x%2 == 0)
        return true;
    else
        return false;
}
void showMark(Student &s)
{
    cout<<s.getMark()<<" ";
}
void showCities(vector<City>c)
{
    for(auto & i : c)
    {
        cout<<endl;
        cout<<endl;
        cout<<endl;
        i.show_city();
        i.show_citizens();
        cout<<"Liczba osob doroslych w miescie: "<<i.adults()<<endl;
        cout<<"Liczba kobiet w miescie:  "<< i.women()<<endl;
        cout<<"Liczba mieszkancow w miescie: "<<i.city_citizens()<<endl;
        i.postal_codes();
        cout<<endl;
        cout<<endl;
        cout<<endl;

   }
}

void mostUniquePostalCodes(vector<City>cities)
{
    int most = cities.at(0).uniquePostalCodes();
    string name=cities.at(0).getCityName();
    for(auto & citie : cities)
    {
        if (citie.uniquePostalCodes()>most)
        {
            most=citie.uniquePostalCodes();
            name=citie.getCityName();
        }

    }
    cout<<"Miasto z najwieksza liczba unikalnych kodow pocztowych: "<<name<<endl;
}
void leastPopulatedCity(vector <City> cities)
{
    int leastPopulated = cities.at(0).city_citizens();
    string name=cities.at(0).getCityName();
    for(auto & city : cities)
    {
        if(city.city_citizens() < leastPopulated)
        {
            leastPopulated=city.city_citizens();
            name=city.getCityName();

        }

    }
    cout<<"Miasto, w ktorym mieszka najmniej mieszkancow: "<<name<<endl;

}
void the_most(const vector<City>&c,int mode)
{
    switch (mode) {
        case 1:
            mostUniquePostalCodes(c);
            break;
        case 2:
            leastPopulatedCity(c);
            break;
        default:
            cout << "Nieprawidłowy tryb." << endl;
            break;
    }
}
void statistic (vector <City> c)
{
    for(auto & i : c)
    {
        cout<<endl;
        i.show_city();
        cout<<"Liczba mieszkancow: "<<i.city_citizens()<<endl;
        cout<<"Liczba kobiet: "<<i.women()<<endl;
        cout<<"Liczba mezczyzn: "<<i.city_citizens()-i.women()<<endl;
        cout<<"Liczba pelnoletnich: "<<i.adults()<<endl;
        cout<<"Liczba niepelnoletnich: "<<i.city_citizens()-i.adults()<<endl;
        cout<<endl;

    }
}
bool compareByResidents(City city1, City city2 )
{
    return city1.city_citizens() < city2.city_citizens();
}
void sort_cities(vector <City> &c)
{
    sort(c.begin(), c.end(), compareByResidents);
}
int sumaCyfr(int liczba) {
    int suma=0;
    while (liczba>0)
    {
        suma+=liczba%10;
        liczba/=10;
    }
    return suma;
}

int liczbaCyfr(int liczba) {
    int liczbaCyfr=0;
    while(liczba>0)
    {
        liczba/=10;
        liczbaCyfr++;
    }
    return liczbaCyfr;
}
bool comp1 (const int& liczba1, const int& liczba2)
{
    return sumaCyfr(liczba1) < sumaCyfr(liczba2);
}
bool comp2 (const int& liczba1, const int& liczba2)
{
    return liczbaCyfr(liczba1) > liczbaCyfr(liczba2);
}
void wedlugSumyCyfr(vector<int>&liczby)
{
    sort(liczby.begin(),liczby.end(),comp1);
}
void wedlugLiczbyCyfr(vector<int>&liczby)
{
    sort(liczby.begin(),liczby.end(),comp2);
}

 int main()
 {
 vector<int> vec;
 vec.push_back(1);
 vec.push_back(2);
 vec.push_back(3);
 cout<<"Operator[]"<<endl;
 for(int i : vec)
 cout<<i<<" ";
 cout<<endl;
 cout<<"At"<<endl;
 for(int i : vec)
 cout<<i<<" ";
 cout<<endl;
 cout<<"Iterator: "<<endl;
 vector <int>::iterator it;
 for(it=vec.begin(); it != vec.end(); it++ )
 cout <<*it<<" ";
 cout<<endl;
 cout<<"begin() "<< *vec.begin()<<" front() "
 <<vec.front()<<endl;
 cout<<"end() "<< *(vec.end()-1)<<" back() "
 <<vec.back()<<endl;
 show(vec);
 vec.pop_back();
 show(vec);
 vec.erase(vec.begin()+1,vec.begin()+2);
 show(vec);
 vec.insert(vec.begin()+1,100);
 show(vec);
 vec.clear();
 show(vec);
 vector<float>vec2(5,8.2);
 show(vec2);
 vec2.push_back(3.1);
 show(vec2);
 vector<int>num={3,6,3,8,9,1,3};
 show(num);
 sort(num.begin(),num.end());
 show(num);
 cout<<"binary search"<<endl;
 cout<<binary_search(num.begin(),num.end(),3)<<endl;
 cout<<"count"<<endl;
 cout<<count(num.begin(),num.end(),3)<<endl;
 cout<<"reverse"<<endl;
 reverse(num.begin(),num.begin()+4);
 show(num);
 cout<<"random_shuffle"<<endl;
 shuffle(num.begin(),num.end(), std::mt19937(std::random_device()()));
 show(num);
 cout<<"max element"<<endl;
 cout<<*max_element(num.begin(),num.end())<<endl;
 cout<<"merge"<<endl;
 vector<int>num2(4,6);
 vector<int>res(num.size()+num2.size());
 sort(num.begin(),num.end());
 merge(num.begin(),num.end(),num2.begin(),num2.end(),res.begin());
 show(res);

      for_each(num.begin(),num.end(),print);
     for_each(num.begin(),num.end(),print);
     for_each(num.begin(),num.end(),add10);
      cout<<endl;
      for_each(num.begin(),num.end(),print);
     cout<<endl;
      cout<<count_if(num.begin(),num.end(),isEven);

     cout<<endl;
 cout<<count_if(num.begin(),num.end(),isEven)<<endl;
 cout<<count_if(num.begin(),num.end(),Even(2))<<endl;
vector<Student>st;
st.emplace_back(1,"Ala");
st.emplace_back(5,"Ola");
st.emplace_back(2,"Piotr");
for_each(st.begin(),st.end(),showMark);
cout<<endl;
sort(st.begin(),st.end(),Compare());
for_each(st.begin(),st.end(),showMark);

Losowanie los;

los.funkcja1(los.n);
los.funkcja2(los.n);

cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Funkcja z uzyciem listy: "<<endl;
for_each(los.lista.begin(),los.lista.end(),print);
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Funkcja z uzyciem wektora: "<<endl;
for_each(los.vektor.begin(),los.vektor.end(),print);
cout<<endl;
cout<<endl;
cout<<endl;
//tworzenie mieszkancow
Citizen c1 ("Adam","Malysz",56,'m',"30-605");
Citizen c2 ("Gadam","Palysz",26,'m',"40-600");
Citizen c3 ("Piotr","Maczkowski",16,'m',"10-203");
Citizen c4 ("Alicja","Kaczorek",19,'w',"30-605");
Citizen c5 ("Tania","Malyszak",13,'w',"10-123");
Citizen c6 ("Yla","Dom",37,'w',"40-124");
Citizen c7 ("Mila","Wind",59,'w',"40-124");
Citizen c8 ("Kai","Sanei",11,'m',"10-123");
Citizen c9 ("Tylor","Deila",2,'w',"40-600");

//tworzenie miast
City Lublin("Lublin");
City Sydney("Sydney");
City Georgia("Georgia");

//dodawanie mieszkancow do miast
Lublin.addCitizen(c1);
Lublin.addCitizen(c4);
Lublin.addCitizen(c5);

Sydney.addCitizen(c3);
Sydney.addCitizen(c6);
Sydney.addCitizen(c2);

Georgia.addCitizen(c7);
Georgia.addCitizen(c8);
Georgia.addCitizen(c9);

//wyswietlenie mieszkancow miast
Lublin.show_citizens();
Sydney.show_citizens();
Georgia.show_citizens();

//Usuwanie mieszkancow
Lublin.deleteCitizen("Malysz",56);
Sydney.deleteCitizen("Dom",37);
Georgia.deleteCitizen("Abba",13);

Lublin.show_citizens();
Sydney.show_citizens();
Georgia.show_citizens();

Lublin.show_city();
Sydney.show_city();
Georgia.show_city();
//wystwietlenie liczby kobiet w miastach
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Liczba kobiet w Lublinie: "<<Lublin.women()<<endl;
cout<<endl;
cout<<"Liczba kobiet w Sydney: "<<Sydney.women()<<endl;
cout<<endl;
cout<<"Liczba kobiet w Georgii: "<<Georgia.women()<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
//wyswietlenie liczby mieszkancow w miastach
cout<<"Liczba mieszkancow w Lublinie: "<<Lublin.city_citizens()<<endl;
cout<<endl;
cout<<"Liczba mieszkancow w Sydney: "<<Sydney.city_citizens()<<endl;
cout<<endl;
cout<<"Liczba mieszkancow w Georgii: "<<Georgia.city_citizens()<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Liczba pelnoletnich mieszkancow w Lublinie: "<<Lublin.adults()<<endl;
cout<<endl;
cout<<"Liczba pelnoletnich mieszkancow w Sydney: "<<Sydney.adults()<<endl;
cout<<endl;
cout<<"Liczba pelnoletnich mieszkancow w Georgii: "<<Georgia.adults()<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
//wyswietlenie statystyk kodow pocztowych
Sydney.postal_codes();
Lublin.postal_codes();
Georgia.postal_codes();




//test metody showCities
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Test metody showCities()"<<endl;
Citizen c10("John", "Doe", 3, 'm', "20-456");
Citizen c11("Jane", "Smith", 28, 'w', "20-496");
Citizen c12("Robert", "Johnson", 45, 'm', "30-789");
Citizen c13("Emily", "Brown", 24, 'w', "20-678");
Citizen c14("Michael", "Wilson", 5, 'm', "40-555");
Citizen c15("Olivia", "Lee", 29, 'w', "10-456");
Citizen c16("William", "Taylor", 60, 'm', "30-444");
Citizen c17("Sophia", "Moore", 6, 'w', "40-333");
Citizen c18("David", "Anderson", 42, 'm', "40-333");
City Perth("Perth");
City Houston("Houston");
City Ghostown("Ghostown");

Perth.addCitizen(c10);
Perth.addCitizen(c11);
Perth.addCitizen(c12);
Perth.addCitizen(c13);
Perth.addCitizen(c15);


Houston.addCitizen(c14);


Ghostown.addCitizen(c16);
Ghostown.addCitizen(c17);
Ghostown.addCitizen(c18);


vector<City>cities;


cities.push_back(Ghostown);
cities.push_back(Houston);
cities.push_back(Perth);
showCities(cities);

//test metody the_most()
cout<<"Test metody the-most() "<<endl;
the_most(cities,1);
the_most(cities,2);

//test metody statistic()

cout<<"Test metody statistic() "<<endl;
statistic(cities);

cout<<"Test metody sort_cities()"<<endl;
cout<<endl;
cout<<"Przed posortowaniem: "<<endl;
     for(auto & citie : cities)
     {
         cout<<citie.getCityName()<<endl;
     }
sort_cities(cities);
     cout<<endl;
     cout<<"Po posortowaniu: "<<endl;
     for(auto & citie : cities)
     {
         cout<<citie.getCityName()<<endl;
     }
cout<<endl;
cout<<endl;
cout<<endl;

//zadanie4.4
cout<<"Sortowanie wektora liczb"<<endl;
vector<int>numbers={111,23456,123,11,10,1,2,3,3456,34,234,4,44,56,555,5555556,678,876,78,764};
cout<<"Wektor przed posortowaniem: "<<endl;
     for_each(numbers.begin(),numbers.end(), print);
     cout<<endl;
     cout<<endl;
     cout<<endl;
cout<<"Posortowany rosnaco wedlug sumy cyfr: "<<endl;
     wedlugSumyCyfr(numbers);
     for_each(numbers.begin(),numbers.end(), print);
     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<"Posortowany malejaco wedlug liczby cyfr: "<<endl;
     wedlugLiczbyCyfr(numbers);
     for_each(numbers.begin(),numbers.end(), print);
     return 0;
 }


