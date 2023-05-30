#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int fact(int i) {
    if (i == 0)return 0;
    else if (i == 1)return 1;
    else return i * fact(i - 1);
}
float cor(int n) {
    float k = 0;
    for (int i = n; i >0; i--) {
        k = sqrt(fact(i)+k);
    }
    return k;
}
float num(int m) {
    return pow(3,m);
}
int main1()
{
    int n, m;
    cout << "Input m, n: ";
    cin >> m >> n;

    cout << "Den: " << cor(n) << endl;
    cout << "Num: " << num(m) << endl;

    cout << "Res: " << num(m)/cor(n) << endl;

    return 0;
}


template <class T>
struct Element
{
    T data; 
    Element<T>* next;
    Element<T>* prev;
};
template <class T>
class List
{
private:
    Element<T>* begin; 
    Element<T>* end; 
    int count; 

    Element<T>* Move(int index);
    void Copy(const List<T>& obj);

public:
    List();
    List(const List& obj);
    List<T>& operator=(const List& obj);
    ~List();
    void SetElement(T _data, int index);
    void AddEnd(T _data);
    void AddBegin(T _data);
    void Insert(T _data, int index);
    void Del(int index);
    void Clear();
    void Reverse();
    void Print(string msg);
};

template <class T>
Element<T>* List<T>::Move(int index)
{
    Element<T>* t = begin;

    for (int i = 0; i < index; i++)
        t = t->next;

    return t;
}
template <class T>
void List<T>::Copy(const List<T>& obj)
{
    Clear();

    Element<T>* t = obj.begin;

    while (t != nullptr)
    {
        AddEnd(t->data);
        t = t->next;
    }
}
template <class T>
List<T>::List()
{
    begin = end = nullptr;
    count = 0;
}
template <class T>
List<T>::List(const List& obj)
{
    Copy(obj);
}
template <class T>
List<T>& List<T>::operator=(const List& obj)
{
    Copy(obj);
    return *this;
}
template <class T>
List<T>::~List()
{
    Clear();
}
template <class T>
void List<T>::AddEnd(T _data)
{
    try
    {
        Element<T>* t = new Element<T>;
        t->next = nullptr; 
        t->prev = end; 
        t->data = _data; 

        if (end != nullptr)
            end->next = t;

        if (count == 0)
        {
            begin = end = t;
        }
        else
        {
            end = t;
        }

        count++;
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;
    }
}
template <class T>
void List<T>::AddBegin(T _data)
{
    try
    {
        Element<T>* t = new Element<T>;
        t->data = _data; 
        t->prev = nullptr; 

        t->next = begin;

        if (count > 0)
        {
            begin->prev = t;
            begin = t;
        }
        else
        {
            begin = end = t;
        }

        count++;
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;
    }
}
template <class T>
void List<T>::Insert(T _data, int index)
{

    if (index == count)
    {
        AddEnd(_data);
        return;
    }

    if (index == 0)
    {
        AddBegin(_data);
        return;
    }

    try
    {
        Element<T>* itemPrev = Move(index - 1);

        Element<T>* item = Move(index);

        Element<T>* t = new Element<T>;
        t->data = _data;
        t->next = item;
        t->prev = itemPrev;
        itemPrev->next = t;
        item->prev = t;

        count++;
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;
    }
}
template <class T>
void List<T>::Del(int index)
{
    if (count == 0) return;

    Element<T>* item = Move(index);

    Element<T>* itemPrev = item->prev;

    Element<T>* itemNext = item->next;

    if ((count > 1) && (itemPrev != nullptr))
        itemPrev->next = itemNext; 

    if ((itemNext != nullptr) && (count > 1))
        itemNext->prev = itemPrev;

    if (index == 0)
        begin = itemNext;

    if (index == count - 1)
        end = itemPrev;

    delete item;

    count--;
}
template <class T>
void List<T>::Clear()
{
    int n = count; 
    for (int i = 0; i < n; i++)
        Del(0);
}
template <class T>
void List<T>::Reverse()
{
    List<T> L;
    Element<T>* t = begin;

    while (t != nullptr)
    {
        L.AddBegin(t->data);
        t = t->next;
    }
    *this = L;
}
template <class T>
void List<T>::Print(string msg)
{
    cout << msg << " - ";

    Element<T>* t = begin;
    for (int i = 0; i < count; i++)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main2()
{
    List<double> L;

    cout << "Input elements: ";
    int i = 0, i1 = 0, i2=0, i3 = 0, i4 = 0;
    cin >> i >> i1 >> i2 >> i3 >> i4;
    L.AddBegin(i);
    L.AddEnd(i1);
    L.AddEnd(i2);
    L.AddEnd(i3);
    L.AddEnd(i4);
    L.Print("L: ");

    L.Reverse();
    L.Print("L: ");

    List<double> L1 = L;
    L1.Print("L1: ");

    L1.AddEnd(i);
    L1.AddEnd(i1);
    L1.AddEnd(i2);
    L1.AddEnd(i3);
    L1.AddEnd(i4);
    L1.Print("L1: ");

    return 0;
}

int main3()
{
    string t = "Hello, Bye, Hello, Bye, Hello, Bye, Hello, Bye, Hello";
    string w = "Hello";
    string w1 = "Bye";
    cout << "Text: " << t << "\n";
    cout << "Words: " << w << " " << w1 << "\n";

    size_t start = 0;
    while ((start=t.find(w, start))!=string::npos) {
        t.replace(t.find(w), 5, w1);
        start += 5;
    }
    cout << "Res: " << t << "\n";

    return 0;
}

int main()
{
    int n;
    cout << "N: ";
e: cin >> n;

    switch (n) {
    case 1: main1(); break;
    case 2: main2(); break;
    case 3: main3(); break;
    default: cout << "Error\n"; goto e;
    }

    return 0;
}

