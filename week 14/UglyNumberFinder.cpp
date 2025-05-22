/*Given a number n, write an algorithm and a program to find nth ugly
number. Ugly numbers are those numbers whose only prime factors are 2, 3 or
5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24,. is sequence of
ugly numbers.*/

#include <iostream>
#include <vector>
using namespace std;

int getNthUglyNumber(int n) {
    vector<int> ugly(n); // To store ugly numbers
    ugly[0] = 1; // First ugly number is 1

    int i2 = 0, i3 = 0, i5 = 0; // Indices for multiples of 2, 3, 5
    int next2 = 2, next3 = 3, next5 = 5;

    for (int i = 1; i < n; i++) {
        int nextUgly = min(next2, min(next3, next5));
        ugly[i] = nextUgly;

        if (nextUgly == next2) {
            i2++;
            next2 = ugly[i2] * 2;
        }
        if (nextUgly == next3) {
            i3++;
            next3 = ugly[i3] * 3;
        }
        if (nextUgly == next5) {
            i5++;
            next5 = ugly[i5] * 5;
        }
    }

    return ugly[n - 1];
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "Enter value of n: ";
        cin >> n;
        int result = getNthUglyNumber(n);
        cout << result << endl;
    }

    return 0;
}
