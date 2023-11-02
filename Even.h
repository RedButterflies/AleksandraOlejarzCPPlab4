//
// Created by szyns on 30.10.2023.
//
#ifndef EVEN_H_INCLUDED
#define EVEN_H_INCLUDED
 class Even
 {
 private:
     int divider;
 public:
 Even(int divider);
bool operator( )(int x) const;
 };
 #endif // EVEN_H_INCLUDED