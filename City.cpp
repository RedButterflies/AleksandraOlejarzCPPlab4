//
// Created by szyns on 01.11.2023.
//
#include <iostream>
#include <algorithm>
#include "City.h"
#include "Citizen.h"

using namespace std;

City::City(const string &cityName) : city_name(cityName) {
    this->city_name=cityName;
}

void City::addCitizen(const Citizen& citizen) {
    citizens.push_back(citizen);
    if(postalCodeMap.find(citizen.getPostalCode())== postalCodeMap.end())
    {
        postalCodeMap[citizen.getPostalCode()]= PostalCodes();
    }
    postalCodeMap[citizen.getPostalCode()].citizensNumber++;


}

void City::deleteCitizen(const string& surname, int age) {
     int found=0;
    for(int i=0;i<citizens.size();i++)
    {
        if(citizens.at(i).getSurname()==surname && citizens.at(i).getAge()==age)
        {
            cout<<"Usunieto "<<citizens.at(i).getName()<<" "<<citizens.at(i).getSurname()<<" z mieszkancow miasta "<<city_name<<endl;
            citizens.erase(citizens.begin()+i,citizens.begin()+i+1);
            found ++;

        }
    }
    if(found==0)
    {
        cout<<"Nie znaleziono mieszkanca do usuniecia w miescie "<<city_name<<endl;
    }



}

void City::show_citizens() {
    cout<<endl;
    cout<<"Mieszkancy miasta "<<city_name<<" :"<<endl;
    cout<<endl;

    for(auto & citizen : citizens)
    {
        citizen.show();
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;

}

void City::show_city() {
    cout<<"Nazwa miasta: "<<city_name<<endl;

}

int City::women() {
    int liczbaKobiet=0;
    for(auto & citizen : citizens)
    {
        if(citizen.getSex()=='w')
        {
            liczbaKobiet++;
        }
    }
    return liczbaKobiet;

}

int City::city_citizens() {
    return citizens.size();
}

int City::adults() {
    int citizenNumber=0;
    for(auto & citizen : citizens)
    {
        if(citizen.getAge()>=18)
        {
            citizenNumber++;
        }
    }
    return citizenNumber;
}

void City::postal_codes() {
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Statystyka kodow pocztowych w "<<city_name<<" :"<<endl;
cout<<endl;
int uniquePostalCodes=0;
for(const auto& entry : postalCodeMap)
{
    cout<<entry.first<<" -> "<<entry.second.citizensNumber<<" mieszkancow"<<endl;
    uniquePostalCodes++;
}
    cout<<"Liczba unikatowych kodow pocztowych w miescie o nazwie "<<city_name<<" : "<<uniquePostalCodes<<endl;


}

const string &City::getCityName() const {
    return city_name;
}

int City::uniquePostalCodes() {

    int uniquePostalCodes=0;
    for(const auto& entry : postalCodeMap)
    {

        uniquePostalCodes++;
    }

    return uniquePostalCodes;
}





