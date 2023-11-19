#include <iostream>
using namespace std;

union Union1 {
    int i;
    char c;
    short s;
    double d;
};

int main () {
    Union1 s1;
    s1.s = 1;
    cout << sizeof (s1) << endl;
    s1.c = 'a';
    s1.i = 32;
    s1.d = 20.0;
}