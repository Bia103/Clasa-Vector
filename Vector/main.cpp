#include <iostream>

using namespace std;
template <class Type, unsigned n> class Vector
{
    Type *a;

public:
    Vector()=default;
    Vector(int x)
    {
        a = new Type[n];
        for(int i = 0;i < n;i++)
            a[i]=x;
    }
    Type &operator[](int i);
};
template <class Type, unsigned n>
Type &Vector<Type,n>::operator[](int i)
{
    try
    {
        if(i<0 || i> n-1)
            throw 1;
        return a[i];
    }
   catch(int y)
   {
        cout<<"Out of range\n";
        return a[0];
   }
}

int main()
{
    Vector <int,10> v(8);
    cout<<v[1]<<endl;
    Vector <char,7> t('a');
    cout<<t[10]<<endl;
    return 0;
}
