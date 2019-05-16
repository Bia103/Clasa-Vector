#include <iostream>

using namespace std;
template <class Type, unsigned n> class Vector
{
    Type *a;
public:
    Vector();
    Vector(Type x);
    Vector(Vector &b);
    Type &operator[](int i);
    Vector operator =(const Vector<Type,n>& );
    Vector operator +(const Vector<Type,n>& );
    Vector operator -(const Vector<Type,n>& );
    Type operator*(const Vector<Type,n>&);
    Vector operator*(int x);
    void Modify(int ,int);
    Type E(int);
   // friend Vector<Type, n> operator*(int x,const Vector<Type,n>& m);
    int Size();
   // friend ostream& operator<< <Type,n>(ostream& , const Vector<Type,n>& );

};
//template <class Type, unsigned n>
/*ostream& operator<< <Type,n>(ostream& os, const Vector<Type,n>& t)
{
    for(int i = 0; i < n; i++)
        os<<t.a[i];
    return os;
}*/
//Vector<Type, n> operator*( int x,const Vector<Type, n>& m)
template <class Type, unsigned n>
void Vector<Type, n> :: Modify(int i,int x)
{
    a[i]=x;
}
template <class Type, unsigned n>
Type Vector<Type, n> ::E(int i)
{
    return a[i];
}
/*template <class Type, unsigned n>
Vector<Type, n> operator*(int x,const Vector<Type, n>& right){
    Vector<Type, n> temp;
     // do res=left*right
     for(int i = 0;i < n;i++)
        {
            temp.Modify(i,(right.E)*x);
            }
     return temp;
}*/
template <class Type, unsigned n>
Vector<Type, n> Vector <Type, n> :: operator*( int x)
{
    Vector <Type, n> temp;
    for(int i = 0;i < n;i++)
        temp=a[i]*x;
    return temp;
}
template <class Type, unsigned n>
Vector <Type, n> :: Vector(Vector &b)
{
    a=new Type[n];
    for(int i=0;i<n;i++)
        a[i]=b.a[i];

}
template <class Type, unsigned n>
Vector <Type, n> :: Vector(Type x)
{
        a = new Type[n];
        for(int i = 0;i < n;i++)
            a[i]=x;
}
template <class Type, unsigned n>
Vector <Type, n> :: Vector ()
{
    a=new Type[n];
}
template <class Type, unsigned n>
Vector<Type, n> Vector<Type, n>::operator+(const Vector<Type, n> & op2)
{
    Vector <Type, n> temp;
    for(int i=0;i<n;i++)
        temp.a[i]=op2.a[i]+a[i];
    return temp;
}
template <class Type, unsigned n>
Vector<Type, n> Vector<Type, n>::operator-(const Vector<Type, n> & op2)
{
    Vector <Type, n> temp;
    for(int i=0;i<n;i++)
        temp.a[i]=a[i]-op2.a[i];
    return temp;
}
template <class Type, unsigned n>
int Vector <Type,n>::Size()
{
    return n;
}
template <class Type, unsigned n>
Type Vector<Type, n>::operator*(const Vector<Type, n> & op2)
{

    Type s=a[0]-a[0];
    for(int i=0; i<n;i++)
        {s=s+a[i]*op2.a[i]; }//cout<<s<<" "<<"a["<<i<<"]"<<a[i]<<" op2["<<i<<"]="<<op2.a[i]<<endl;
    return s;
}
template <class Type, unsigned n>
Vector<Type, n> Vector<Type, n>::operator=(const Vector<Type, n> & op2)
{
    delete []a;
    a=new Type[n];
    for(int i=0;i<n;i++)
        a[i]=op2.a[i];
    return *this;
}

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
    Vector <int,10> v(1),o(v),y(7),v1(3);
    cout<<v[1]<<endl;
    Vector <char,7> t('a'),u('u');
    cout<<t[10]<<endl;
    v1=v;
    cout<<y[0];
    cout<<"\nSize: "<<y.Size()<<endl;
    cout<<"\n"<<v*y<<" ";
     //cout<<"\n"<<t*u;
     v=v-y;
     cout<<v[0];
     v=v*3;
     cout<<"\n"<<v[0];
    //cout<<t;
   // cout<<
    return 0;
}
