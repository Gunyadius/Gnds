//
//  ClassChyslo.hpp
//  Laba3
//
//  Created by Сергей Глушенков on 22.11.17.
//  Copyright © 2017 Сергей Глушенков. All rights reserved.
//

#ifndef ClassChyslo_hpp
#define ClassChyslo_hpp
//
#include <stdio.h>

#endif /* ClassChyslo_hpp */
#include <iostream>
using namespace std;

class Chyslo {
public:
    Chyslo();
    Chyslo (int chys, int znam);
    void operator = (Chyslo other);
    bool operator ==(Chyslo one);
    Chyslo operator + (Chyslo other);
    Chyslo operator - (Chyslo other);
    Chyslo operator * (Chyslo other);
    Chyslo operator / (Chyslo other);
    friend ostream& operator << (ostream& str, Chyslo one);
    friend istream& operator >> (istream& stream, Chyslo one); // Как реализовать?
    // Приведение к типу double?
    void Check(Chyslo& one);
    void Power(int pow);
    
private:
    int m;
    int n;
    
};
template <typename T>
class Matrytsia
{
public:
    void operator = (Matrytsia other);
    Matrytsia operator + (Matrytsia other);
    Matrytsia operator - (Matrytsia other);
    Matrytsia operator * (Matrytsia other);
    
private:
    T mas[100][100];
    
};
