#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int kase = 0; kase < n; ++kase) {
        char str[100];
        cin >> str;
        int len = strlen(str);
        for (int i = 1; i <= len; ++i) {
            if (len % i != 0)
                continue;
            bool periodic = true;
            // for (int j = 1; j < len / i; ++j) {
            //     if (strncmp(str, str + j * i, i) != 0) {
            //         periodic = false;
            //         break;
            //     }
            // }
            for (int j = i; j < len; ++j) {
                if (str[j] != str[j % i]) {
                    periodic = false;
                    break;
                }
            }
            if (periodic) {
                if (kase)
                    cout << '\n';
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
