//
// Created by szyns on 31.10.2023.
//
#include "Compare.h"
bool Compare::operator() (Student &s1, Student &s2)
{
    return s1.getMark() < s2.getMark();
}
