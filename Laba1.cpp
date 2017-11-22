//
//  main.cpp
//  Test
//
//  Created by Сергей Глушенков on 05.09.17.
//  Copyright © 2017 Сергей Глушенков. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
const double p=1000.;

// Блок для равномерных генераторов

int calc1(int &q){
    q=(37*q+76)%1000;
    return q;
}
double calc2(int &q){
    q=(40*q^2+5*q+199)%1000;
    return q/p;
}
double calc3(int &q,int &w){
    w=q;
    q=(q+w)%1000;
    return q/p;
}
double calc4(int &q){
    int b = 0;
    while (q*b % 1000 != 1 && b<1000) b++;
    if (b == 1000) b = 0;
    q = (49 * b + 30) % 1000;
    return q/p;

}
double calc5(int &q){
    int x;
    x=(calc1(q)+calc1(q))%1000;
    return x/p;
}
int a[10];
int b[60];
int choice;
void first(int X0, int X1)
{
    double w=X0/p;
    int y=0;
    for(int i=0;i<100;i++)
    {
        switch (choice) {
            case 1:
                w=calc1(X0)/p;
                break;
            case 2:
                w=calc2(X0);
                break;
            case 3:
                w=calc3(X0,X1);
                break;
            case 4:
                w=calc4(X0);
                break;
            case 5:
                w=calc5(X0);
                break;
            default:
                break;
        }
        //cout<<w<<"\n";
        y=(int) (w*10);
        a[y]=a[y]+1;
    }
   // double r=0;
    for (int j=0;j<10;j++){
        cout<<"["<<j/10.<<","<<(j+1)/10.<<"]"<<" ";
        if ((j==0)||(j==9))
        {
            cout<<"  ";
        }
      //  r=r+a[j];
        cout<<a[j]/100.<<"\n";
    }
   // cout<<r;

}

// Блок для нормальных генераторов

double calc6(int &q){
    double sum=0;
    for (int i=1;i<=12;i++){
        sum=sum+calc1(q)/p;
    }
    return 0+(sum - 6)*1;
}
double calc7(int &q, double &w2){
    double s=1;
    double v1=2*calc1(q)/p-1;
    double v2=2*calc1(q)/p-1;
    s=v1*v1+v2*v2;
    if (s>=1)
        return calc7(q,w2);
    else
    {
        w2=v2*sqrt(-2*log(s)/s);
        return v1*sqrt(-2*log(s)/s);
    }
}
double calc8(int &q){
    double v=calc1(q)/p;
    double u=0;
    while (u==0)
    {
        u=calc1(q)/p;
    }
    double X=sqrt(8/M_E)*(v-0.5)/u;
    if (X*X<=5-4*exp(2.8)*u)
        return X;
    else
        if (X*X>=(4*exp(-1.35)/u)+1.4)
            return calc8(q);
        else
            if (X*X<=-4*log(u))
                return X;
            else
                return calc8(q);
}
void second(int X0)
{
    int y=0;
    double w1=X0/p;
    double w2=0;
    for(int i=0;i<600;i++)
    {
            switch (choice) {
            case 6:
                {
                w1=calc6(X0);
                    y=(int)(w1+6.5);
                    b[y]=b[y]+1;
                }
                break;
            case 7:
                   {
                       //cout<<w1<<"\n";
                       w1=calc7(X0,w2);
                       y=(int)(w1+6.5);
                       b[y]=b[y]+1;
                       y=(int)(w2+6.5);
                       b[y]=b[y]+1;
                       i++;
                       //cout<<w2<<"\n";
                   }
                break;
            case 8:
                {
                w1=calc8(X0);
                    y=(int)(w1+6.5);
                    b[y]=b[y]+1;
                }
                break;
            default:
                break;
        }
        //cout<<w1<<"\n";
    }
    int i=0;
    for (int j=5;j>=0;j--){
        cout<<"["<<-(j+1)/2.<<","<<-j/2.<<"]"<<" "<<b[i]/600.<<"\n";
        i++;
    }
    for (int j=0;j<=5;j++){
        cout<<"["<<j/2.<<","<<(j+1)/2.<<"]"<<" "<<b[i]/600.<<"\n";
        i++;
    }
    
}

// Блок для остальных генераторов

double calc9(int &q){
    return (-18)*log(calc1(q)/p);
}
double calc10(int &q){
    double u=calc1(q)/p;
    double w;
    double y=tan(M_PI*u);
    double x=sqrt(2*47-1)*y+47-1;
    if (x<=0)
        return calc10(q);
    else
        w=calc1(q)/p;
        if (w>((1+y*y)*exp((47-1)*log(x/(47-1))-sqrt(2*47-1)*y)))
            return calc10(q);
        else
            return x;
}
void third(int X0)
{
    double w=0;
    int y=0;
    for(int i=0;i<100;i++)
    {
    switch (choice){
        case 9:
        {
            w=calc9(X0);
            break;
        }
        case 10:
        {
            w=calc10(X0);
            break;
        }
        default:
            break;
    }
    //cout<<w<<"\n";
    y=(int)(w/10);
    a[y]=a[y]+1;
    }
    for (int j=0;j<10;j++){
        cout<<"["<<j*10<<","<<(j+1)*10<<"]"<<" "<<a[j]/100.<<"\n";
    }

}

// Основная функция

int main() {
    
    for (int j=0;j<10;j++){
        a[j]=0;
    }
    int X0=181;
    int X1=285;
    cout<<"Enter the number of generator:"<<"\n";
    cin>>choice;
    if ((1<=choice)&&(choice<=5))
        first(X0,X1);
    else
         if ((6<=choice)&&(choice<=8))
             second(X0);
         else
             if ((9<=choice)&&choice<=10)
             third(X0);
                else
                    cout<<"Wrong expression!"<<"\n";
    return 0;
}
