#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

double ME[10][31];

int main()
{
    for (int M = 0; M <= 9; ++M) {
        for (int E = 1; E <= 30; ++E) {
            double m = 1 - pow(2, -M - 1);
            double e = pow(2, E) - 1;
            ME[M][E] = log10(m) + e * log10(2);
        }
    }
    while (true) {
        string input;
        cin >> input;
        if (input == "0e0")
            break;
        input[17] = ' ';
        double A;
        int B;
        stringstream ss;
        ss << input;
        ss >> A >> B;
        double AeB = log10(A) + B;
        for (int M = 0; M <= 9; ++M) {
            for (int E = 1; E <= 30; ++E) {
                if (fabs(AeB - ME[M][E]) < 1e-4)
                    cout << M << ' ' << E << endl;
            }
        }
    }
    return 0;
}
