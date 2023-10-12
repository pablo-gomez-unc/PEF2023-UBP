#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> testedVector(10);
    testedVector.push_back (1);
    vector<int> a(10);
    vector<int> *b;
    b = &testedVector ;
    cout << "hola";
    return 0;
}
