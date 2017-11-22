//
//  main.cpp
//  Laba3
//
//  Created by Сергей Глушенков on 22.11.17.
//  Copyright © 2017 Сергей Глушенков. All rights reserved.
//

#include <iostream>
#include "ClassChyslo.hpp"


int main() {
    Chyslo a;
    cout<<"a="<<a<<"\n";
    Chyslo b (4,8);
    b.Power(2);
    cout<<"b="<<b<<"\n";
   // a=b;
    cout<<"a="<<a<<"\n";
    a=a-b;
    cout<<"a="<<a<<"\n";
    a=a/(b*b+a);
    cout<<"a="<<a<<"\n";
    return 0;
}
