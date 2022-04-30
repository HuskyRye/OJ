#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void solve(const string& a, const string& b)
{
    unsigned int count1[26] = { 0 };
    unsigned int count2[26] = { 0 };
    for (char c : a)
        count1[c - 'A'] += 1;
    for (char c : b)
        count2[c - 'A'] += 1;
    sort(count1, count1 + 26);
    sort(count2, count2 + 26);
    for (int i = 0; i < 25; ++i) {
        if (count1[i] != count2[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main()
{
    string a, b;
    while (cin >> a >> b) {
        solve(a, b);
    }
}