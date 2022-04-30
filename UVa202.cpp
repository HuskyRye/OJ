#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    while (true) {
        int a, b;
        if (!(cin >> a))
            break;
        cin >> b;
        cout << a << '/' << b << " = ";
        cout << a / b;
        int remainder = a % b;
        map<int, int> remainders;
        stringstream rss;
        while (remainders.count(remainder) == 0 && remainder != 0) {
            remainders[remainder] = remainders.size();
            remainder *= 10;
            rss << remainder / b;
            remainder = remainder % b;
        }
        cout << '.';
        string rs = rss.str();
        if (remainder != 0) {
            int pos = remainders[remainder];
            int i = 0;
            while (i < pos)
                cout << rs[i++];
            cout << '(';
            while (i < rs.length() && i < 50)
                cout << rs[i++];
            if (i < rs.length())
                cout << "...";
            cout << ")\n   "
                 << remainders.size() - pos << " = number of digits in repeating cycle\n\n";
        } else {
            cout << rs << "(0)\n   1 = number of digits in repeating cycle\n\n";
        }
    }
    return 0;
}
