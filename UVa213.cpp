#include <iostream>
using namespace std;

char codes[8][1 << 8];

bool readcodes()
{
    char c;
    if (c = cin.get(), c == EOF)
        return false;
    codes[1][0] = c;
    for (int len = 2; len <= 7; ++len) {
        int max_code = (1 << len) - 1;
        for (int code = 0; code < max_code; ++code) {
            c = cin.get();
            if (c == '\n')
                return true;
            codes[len][code] = c;
        }
    }
    return true;
}

int readint(int len)
{
    char c;
    int result = 0;
    for (int i = 0; i < len;) {
        c = cin.get();
        if (c == '\n')
            continue;
        result <<= 1;
        result += (c - '0');
        ++i;
    }
    return result;
}

int main()
{
    while (readcodes()) {
        // for (int len = 1; len <= 7; ++len) {
        //     int max_code = (1 << len) - 1;
        //     cout << len << endl;
        //     for (int code = 0; code < max_code; ++code) {
        //         cout << code << ": " << codes[len][code] << '\t';
        //     }
        //     cout << '\n';
        // }
        while (true) {
            int len = readint(3);
            if (len == 0)
                break;
            int max_code = (1 << len) - 1;
            while (true) {
                int code = readint(len);
                if (code == max_code)
                    break;
                cout << codes[len][code];
            }
        }
        cout << endl;
        cin.get();
    }
}