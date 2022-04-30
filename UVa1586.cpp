#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.get();
    for (int kase = 0; kase < n; ++kase) {
        double mass = 0;
        char s[100];
        cin.getline(s, 100);
        for (int i = 0; i < strlen(s);) {
            char c = s[i++];
            if (isalpha(c)) {
                int times = 0;
                char num;
                while (num = s[i++], isdigit(num)) {
                    times = times * 10 + num - '0';
                }
                --i;
                if (times == 0)
                    times = 1;
                switch (c) {
                case 'C':
                    mass += 12.01 * times;
                    break;
                case 'H':
                    mass += 1.008 * times;
                    break;
                case 'O':
                    mass += 16.00 * times;
                    break;
                case 'N':
                    mass += 14.01 * times;
                    break;
                }
            }
        }
        cout << fixed << setprecision(3) << mass << endl;
    }
}
