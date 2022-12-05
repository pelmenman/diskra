#include <iostream>
using namespace std;

int main() {
    long long int evoStep, p1, p2;
    cin >> evoStep >> p1 >> p2;

    while (p1 != p2) {
        (p1 > p2)? p1 /= 2 : p2 /= 2;
    }
    cout << p1;
    return 0;
}
