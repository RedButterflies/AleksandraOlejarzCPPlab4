//
// Created by szyns on 01.11.2023.
//
#include "Citizen.h"
#include <iostream>
#include <utility>
using namespace std;

Citizen::Citizen(string name, string surname, int age, char sex, string postalCode) : name(std::move(name)),
                                                                                                           surname(std::move(surname)),
                                                                                                           age(age),
                                                                                                           sex(sex),
                                                                                                           postal_code(std::move(
                                                                                                                   postalCode)) {}

void Citizen::show() {
    cout<<"Name: "<<name<<endl;
    cout<<"Surname: "<<surname<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Sex: "<<sex<<endl;
    cout<<"Postal code: "<<postal_code<<endl;


}

const string &Citizen::getName() const {
    return name;
}

const string &Citizen::getSurname() const {
    return surname;
}

int Citizen::getAge() const {
    return age;
}

char Citizen::getSex() const {
    return sex;
}

const string &Citizen::getPostalCode() const {
    return postal_code;
}

Citizen::Citizen() = default;
