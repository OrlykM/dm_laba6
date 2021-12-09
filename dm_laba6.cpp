#include <iostream>
#include <set>
#include <math.h>
#include <Windows.h>
using namespace std;
int factorial(int n) {

    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }

}
int f(int n)
{
    if (n <= 1) return 1;
    else return f(n - 1) * n;
}
void binomial()
{
    int* a, k = 5, k1 = 0, m, x, y, q, kil = 5, kil1 = -1, s = 1, s1 = 1, s2 = 1, sum, q1;
    cout << endl << "(x+y)^6 = ";
    for (int i = 0; i <= 6; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            s *= j;
        }
        kil1++;
        for (q = 1; q < 7 - kil1; q++)
        {
            s1 *= q;
        }
        for (q1 = 1; q1 <= kil1; q1++)
        {
            s2 *= q1;
        }
        sum = s / (s1 * s2);
        if (i != 6)cout << sum << "x^" << k << "*y^" << k1 << "+";
        else  cout << sum << "x^" << k << "*y^" << k1;
        s = 1; s1 = 1; s2 = 1; sum = 0;
        k--; k1++;
    }
    cin.get(); cin.get();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, r;
    cout << "Уведіть значення n: ";
    cin >> n;
    cout << "Уведіть значення r: ";
    cin >> r;
    int* placement = new int[r];
    for (int i = 0; i < r; i++) {
        placement[i] = i + 1;
    }
    for (int i = 0; i < r; i++) {
        cout << placement[i] << " ";
    }
    cout << endl;
    set<int> remainders;

    for (int i = r; i < n; i++) {
        remainders.insert(i + 1);
    }
    int i = r - 1;
    while (i >= 0) {
        int suitableRemainder = INT_MAX;
        for (int remainder : remainders) {
            if (placement[i] < remainder) {
                suitableRemainder = remainder;
                break;
            }
        }

        remainders.insert(placement[i]);
        if (suitableRemainder != INT_MAX) {
            placement[i] = suitableRemainder;
            remainders.erase(suitableRemainder);

            for (int k = i + 1; k < r; k++) {
                int foundMinRemainder = *remainders.begin();
                remainders.erase(foundMinRemainder);

                placement[k] = foundMinRemainder;
            }
            for (int i = 0; i < r; i++) {
                cout << placement[i] << " ";
            }
            cout << endl;
            i = r - 1;
        }
        else {
            i--;
        }
    }
    binomial();
}