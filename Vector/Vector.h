#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cassert>
using namespace std;
template <class Type, unsigned n> class Vector
{
    Type *a;
public:
    Vector();                                       // constructorul fara parametrii
    Vector(Type x);                                 // constructorul cu parametru
    Vector(Vector &b);                              // constructorul de copiere
    Type &operator[](int i);                        // supraincarcarea []
    Vector operator =(const Vector<Type,n>& );      // supraincarcarea =
    Vector operator +(const Vector<Type,n>& );      // supraincarcarea +
    Vector operator -(const Vector<Type,n>& );      // supraincarcarea -
    Type operator*(const Vector<Type,n>&);          // supraincarcarea * pentru produsul scalar
    void Modify(int ,int);                          // metoda ce modifica elemente din vector
    Type E(int);
    int Size();                                     // metoda ce returneaza marimea vectorului
    template<class U,unsigned m>
    friend ostream& operator<< (ostream& of, const Vector<U,m>& dt);    // supraincarcarea operatorului de afisare
    template<class U,unsigned m>
    friend Vector<U,m> operator*(int x, const Vector<U,m>& right);      // supraincarcarea inmultirii la stanga
};
template<class Type, unsigned n>
ostream& operator<<(ostream& of,const Vector<Type,n>& dt)               // supraincarcarea operatorului de afisare
{
    for(int i=0;i<n;i++)
        of<<dt.a[i];                                                    // afisarea elementelor din vector
    return of;
}
template<class Type, unsigned n>
Vector<Type, n> operator*(int x,const Vector<Type, n>& right){          // inmultirea la stanga se realizeaza printr-o functie friend
    Vector<Type, n> temp;
     for(int i = 0;i < n;i++)
        {
            temp.a[i]=right.a[i]*x;
            }
     return temp;
}
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
template <class Type, unsigned n>
Vector <Type, n> :: Vector(Vector &b)                   // constructorul de copiere
{
    a=new Type[n];                                      // se aloca spatiu
    for(int i=0;i<n;i++)
        a[i]=b.a[i];                                    // se copiaza fiecare element

}
template <class Type, unsigned n>
Vector <Type, n> :: Vector(Type x)                      // constructorul cu parametru
{
        a = new Type[n];
        for(int i = 0;i < n;i++)
            a[i]=x;                                     // toate elementek=le vectorului primesc valoarea lui x
}
template <class Type, unsigned n>
Vector <Type, n> :: Vector ()                           // constructorul fara parametru
{
    a=new Type[n];
}
template <class Type, unsigned n>
Vector<Type, n> Vector<Type, n>::operator+(const Vector<Type, n> & op2) //supraincarcarea adunarii
{
    Vector <Type, n> temp;
    for(int i=0;i<n;i++)
        temp.a[i]=op2.a[i]+a[i];
    return temp;
}
template <class Type, unsigned n>
Vector<Type, n> Vector<Type, n>::operator-(const Vector<Type, n> & op2) //supraincarcarea scaderii
{
    Vector <Type, n> temp;
    for(int i=0;i<n;i++)
        temp.a[i]=a[i]-op2.a[i];
    return temp;
}
template <class Type, unsigned n>
int Vector <Type,n>::Size()                 // metoda ce returneaza marimea unui vector
{
    return n;
}
template <class Type, unsigned n>
Type Vector<Type, n>::operator*(const Vector<Type, n> & op2)
{

    Type s=a[0]-a[0];
    for(int i=0; i<n;i++)
        {
            s=s+a[i]*op2.a[i];
        }
    return s;
}
template <class Type, unsigned n>
Vector<Type, n> Vector<Type, n>::operator=(const Vector<Type, n> & op2) //supraincarcarea operatorului =
{
    delete []a;
    a=new Type[n];
    for(int i=0;i<n;i++)
        a[i]=op2.a[i];
    return *this;
}
template <class Type, unsigned n>
Type &Vector<Type,n>::operator[](int i)             // supraincarcarea [ ] pt returnarea unui element din vector
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
        assert (y==0);
   }
//   return 0;
}

#endif // VECTOR_H
