//
//  ClassChyslo.cpp
//  Laba3
//
//
//  Created by Сергей Глушенков on 22.11.17.
//  Copyright © 2017 Сергей Глушенков. All rights reserved.
//

#include "ClassChyslo.hpp"
#include <cmath>
Chyslo::Chyslo()
{
    this->m=0;
    this->n=1;
}
Chyslo::Chyslo(int chys,int znam)
{
    this->m=chys;
    this->n=znam;
    Check(*this);
}
void Chyslo::operator=(Chyslo other)
{
    this->m=other.m;
    this->n=other.n;
}
bool Chyslo::operator==(Chyslo other)
{
    if ((this->m==other.m)&&(this->n==other.n))
        return true;
    else
        return false;
}
Chyslo Chyslo::operator+(Chyslo other)
{
    if (this->n==other.n)
    {
        this->m=this->m+other.m;
        Check(*this);
        return *this;
    }
    else
    {
        this->m=this->m*other.n;
        other.m=other.m*this->n;
        this->m=this->m+other.m;
        this->n=this->n*other.n;
        Check(*this);
        return *this;
    }
}
Chyslo Chyslo::operator-(Chyslo other)
{
    if (this->n==other.n)
    {
        this->m=this->m-other.m;
        Check(*this);
        return *this;
    }
    else
    {
        this->m=this->m*other.n;
        other.m=other.m*this->n;
        this->m=this->m-other.m;
        this->n=this->n*other.n;
        Check(*this);
        return *this;
    }
}
Chyslo Chyslo::operator * (Chyslo other)
{
    this->m=this->m*other.m;
    this->n=this->n*other.n;
    Check(*this);
    return *this;
}
Chyslo Chyslo::operator / (Chyslo other)
{
    this->m=this->m*other.n;
    this->n=this->n*other.m;
    Check(*this);
    return *this;
}
ostream& operator << (ostream & stream, Chyslo other)
{
    stream<<to_string(other.m)<<"/"<<to_string(other.n)<<"\n";
    return stream;
}
istream& operator >> (istream & stream, Chyslo other)
{
    other.m=cin.get();
    return stream;
}
void Chyslo::Check(Chyslo& one)
{
    if ((one.m<=0)&&(one.n<0))
    {
        one.m=abs(one.m);
        one.n=abs(one.n);
    }
    int i=2;
    bool flag=true;
    while ((i<=abs(one.m))&&(i<=abs(one.n)))
    {
        while (flag)
        {
        if (((one.m)%i==0)&&((one.n)%i==0))
        {
            one.m=one.m/i;
            one.n=one.n/i;
        }
        else
            flag=false;
        }
        flag=true;
        i++;
    }
}
void Chyslo::Power(int pow)
{
    int i=1;
    int chys=this->m;
    int znam=this->n;
    while(i<pow)
    {
        this->m=this->m*chys;
        this->n=this->n*znam;
        i++;
    }
}

