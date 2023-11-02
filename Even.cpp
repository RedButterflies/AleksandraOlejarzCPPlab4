//
// Created by szyns on 30.10.2023.
//
#include "Even.h"
#include <iostream>
using namespace std;
 Even:: Even(int divider)
 {
 this->divider=divider;
 }
 bool Even::operator()(int x) const
 {
     if (x%divider == 0)
        return true;
     else
        return false;
 }
