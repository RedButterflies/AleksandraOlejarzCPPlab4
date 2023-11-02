//
// Created by szyns on 01.11.2023.
//

#ifndef UNTITLED11_CITIZEN_H
#define UNTITLED11_CITIZEN_H
#include <iostream>
using namespace std;
class Citizen{
private:
    string name;
    string surname;
    int age{};
    char sex{};
    string postal_code;
public:
    Citizen();

    Citizen(string name, string surname, int age, char sex, string postalCode);
    void show();

    const string &getName() const;

    const string &getSurname() const;

    int getAge() const;

    char getSex() const;

    const string &getPostalCode() const;

};
#endif //UNTITLED11_CITIZEN_H
