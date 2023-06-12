#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <numeric>

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

int main2()
{
    list<double>L;
    cout << "Input n: ";
    int n, e;
    cin >> n;
    cout << "Input elements: ";
    for (int i = 0; i < n; i++) {
        cin >> e;
        L.push_back(e);
    }
    cout << "L: ";
    for (auto i : L) cout << i << " ";

    L.reverse();
    cout << "\nL: ";
    for (auto i : L) cout << i << " ";

    list<double> L1 = L;
    cout << "\nL1: ";
    for (auto i : L1) cout << i << " ";
    L.reverse();
    L1.splice(L1.end(), L);

    cout << "\n\nL1: ";
    int t = 0;
    for (auto i : L1) 
    {
        if(t==5) 
        {
            cout << "\n";
            t = 0;
        }
        cout << i << " ";
        t += 1;
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

int main4() {

    vector<float> v{};
    ifstream n("name1.txt", std::ios::in | std::ifstream::binary);
    istream_iterator<float> In{n};
    istream_iterator<float> end{};
    copy(In, end, std::back_inserter(v));


    std::ofstream n1("name2.txt", std::ios::out | std::ofstream::binary);
    std::ostream_iterator<float> Out{n1, "\n"};
    std::copy_if(v.begin(), v.end(), Out, [](int i) {return i != 0; });
    
    return 0;
}

int main5() {
    list<int> m;
    cout << "Input n: ";
    int n, e;
    cin >> n;
    cout << "Input elements: ";
    for (int i = 0; i < n; i++) {
        cin >> e;
        m.push_back(e);
    }
    cout << "The original list is : ";
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";

    list<int>::iterator it = m.end();
    int j = (size(m) / 2);
    advance(it, -j);
    list<int> m1;
    for (auto i = m.begin(); i != it; i++) {
        m1.push_back(*i);
    }

    it = m1.end();
    advance(it, -j);
    replace_copy_if(m1.begin(), m1.end(),
        it,
        [](int k) { return k < 0; }, 0);

    reverse(m1.begin(), m1.end());
    for (auto i = m1.begin(); i != m1.end(); i++) {

        m.push_back(*i);
    }
    cout << "New : ";
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";

    return 0;
}

int main6() {
    vector<int> a = { 1, 2, 3, 5, 10, 11, 12, 13, 14, 15,20, 21 };
    cout << "V: ";
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n\n";
    map<int, int> m;
    int s0 = 0;
    int s = 0;
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int s4 = 0;
    int s5 = 0;
    int s6 = 0;
    int s7 = 0;
    int s8 = 0;

    int k0 = 0;
    int k = 0;
    int k1 = 0;
    int k2 = 0;
    int k3 = 0;
    int k4 = 0;
    int k5 = 0;
    int k6 = 0;
    int k7 = 0;
    int k8 = 0;

    vector<int> b0;
    vector<int> b;
    vector<int> b1;
    vector<int> b2;
    vector<int> b3;
    vector<int> b4;
    vector<int> b5;
    vector<int> b6;
    vector<int> b7;
    vector<int> b8;

    for (int i = 0; i < size(a); i++) {
        if (a[i] % 10) {
            if ((a[i] % 10) == 1) {
                b.push_back(a[i]);
                k += 1;
            }

            if ((a[i] % 10) == 2) {
                b1.push_back(a[i]);
                k1 += 1;
            }

            if ((a[i] % 10) == 3) {
                b2.push_back(a[i]);
                k2 += 1;
            }

            if ((a[i] % 10) == 4) {
                b3.push_back(a[i]);
                k3 += 1;
            }

            if ((a[i] % 10) == 5) {
                b4.push_back(a[i]);
                k4 += 1;
            }

            if ((a[i] % 10) == 6) {
                b5.push_back(a[i]);
                k5 += 1;
            }

            if ((a[i] % 10) == 7) {
                b6.push_back(a[i]);
                k6 += 1;
            }

            if ((a[i] % 10) == 8) {
                b7.push_back(a[i]);
                k7 += 1;
            }

            if ((a[i] % 10) == 9) {
                b8.push_back(a[i]);
                k8 += 1;
            }
        }
        else {
            b0.push_back(a[i]);
            k0 += 1;
        }
    }
    s0 = accumulate(b0.begin(), b0.end(), 0);
    s = accumulate(b.begin(), b.end(), -1);
    s1 = accumulate(b1.begin(), b1.end(), -2);
    s2 = accumulate(b2.begin(), b2.end(), -3);
    s3 = accumulate(b3.begin(), b3.end(), -4);
    s4 = accumulate(b4.begin(), b4.end(), -5);
    s5 = accumulate(b5.begin(), b5.end(), -6);
    s6 = accumulate(b6.begin(), b6.end(), -7);
    s7 = accumulate(b7.begin(), b7.end(), -8);
    s8 = accumulate(b8.begin(), b8.end(), -9);

    if (k0 == 1)s0 = 0;
    if ((s == -1) || (k == 1))s = 0;
    if ((s1 == -2) || (k1 == 1))s1 = 0;
    if ((s2 == -3) || (k2 == 1))s2 = 0;
    if ((s3 == -4) || (k3 == 1))s3 = 0;
    if ((s4 == -5) || (k4 == 1))s4 = 0;
    if ((s5 == -6) || (k5 == 1))s5 = 0;
    if ((s6 == -7) || (k6 == 1))s6 = 0;
    if ((s7 == -8) || (k7 == 1))s7 = 0;
    if ((s8 == -9) || (k8 == 1))s8 = 0;


    m.insert(pair<int, int>(0, s0));
    m.insert(pair<int, int>(1, s));
    m.insert(pair<int, int>(2, s1));
    m.insert(pair<int, int>(3, s2));
    m.insert(pair<int, int>(4, s3));
    m.insert(pair<int, int>(5, s4));
    m.insert(pair<int, int>(6, s5));
    m.insert(pair<int, int>(7, s6));
    m.insert(pair<int, int>(8, s7));
    m.insert(pair<int, int>(9, s8));


    map<int, int>::iterator it;
    it = m.find(0);
    cout << it->first << " : " << it->second << endl;
    it = m.find(1);
    cout << it->first << " : " << it->second << endl;
    it = m.find(2);
    cout << it->first << " : " << it->second << endl;
    it = m.find(3);
    cout << it->first << " : " << it->second << endl;
    it = m.find(4);
    cout << it->first << " : " << it->second << endl;
    it = m.find(5);
    cout << it->first << " : " << it->second << endl;
    it = m.find(6);
    cout << it->first << " : " << it->second << endl;
    it = m.find(7);
    cout << it->first << " : " << it->second << endl;
    it = m.find(8);
    cout << it->first << " : " << it->second << endl;
    it = m.find(9);
    cout << it->first << " : " << it->second << endl;

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
    case 4: main4(); break;
    case 5: main5(); break;
    case 6: main6(); break;
    default: cout << "Error\n"; goto e;
    }

    return 0;
}

