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

void Print(const list<float>& lst) {
    for (auto i = lst.begin(); i != lst.end(); i++) {
        cout << *i << " ";
    }
}
int main2() {
    list<float>numb = { 1.2,7,8,6,5,2,9,10,3,1.1 };

    cout << "List: ";
    Print(numb);

    cout << "\nSort: ";
    numb.sort();
    Print(numb);
    list<float>numb1 = numb;

    cout << "\nNew list: ";

    numb.merge(numb1);

    int n = 0;
    for (auto i = numb.begin(); i != numb.end(); i++) {
        if (n == 5) { cout << "\n"; n = 0; }
        n += 1;
        cout << *i << " ";
    }

    cout << "\n\nOR\n";
    list<float>k = { 1.2,7,8,6,5,2,9,10,3,1.1 };
    cout << "\nSort: ";
    k.sort();
    list<float>k1 = k;
    k.reverse();
    for (auto i = k.begin(); i != k.end(); i++) {
        if (n == 5) { cout << "\n"; n = 0; }
        n += 1;
        cout << *i << " ";
    }
    for (auto i = k1.begin(); i != k1.end(); i++) {
        if (n == 5) { cout << "\n"; n = 0; }
        n += 1;
        cout << *i << " ";
    }

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

