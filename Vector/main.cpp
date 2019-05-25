#include <iostream>
#include <cassert>
#include "Vector.h"
using namespace std;

int main()
{

    Vector <int,10> v(1),o(v),y(7),v1(3);
    cout<<v[1]<<endl;
    Vector <char,7> t('a'),u('u');
    v1=v;
    cout<<y[0];
    cout<<"\nSize: "<<y.Size()<<endl;
    cout<<v*y<<" ";
     v=v-y;
     cout<<v[0];
     v=3*v;
     cout<<"\n"<<v[0]<<"\n";
     cout<<t;

    return 0;
}
