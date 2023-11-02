//
// Created by szyns on 01.11.2023.
//

#ifndef UNTITLED11_CITY_H
#define UNTITLED11_CITY_H
#include "Citizen.h"
#include <iostream>
#include <vector>
#include <map>
#include "PostalCodes.h"
using namespace std;

class City{
private:
    vector<Citizen>citizens;
    string city_name;
    map<string, PostalCodes> postalCodeMap;

public:
    explicit City(const string &cityName);
    void addCitizen(const Citizen& citizen);
    void deleteCitizen( const string& surname,int age);
    void show_citizens();
    void show_city();
    int women();
    int city_citizens();
    int adults();
    int uniquePostalCodes();

    const string &getCityName() const;

    void postal_codes();
};
#endif //UNTITLED11_CITY_H
