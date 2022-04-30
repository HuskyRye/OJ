#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int database[10000][10];

void check(int n, int m)
{
    for (int c1 = 0; c1 < m; ++c1) {
        for (int c2 = c1 + 1; c2 < m; ++c2) {
            map<pair<int, int>, int> pair_to_row;
            for (int i = 0; i < n; ++i) {
                auto tuple = pair<int, int>(database[i][c1], database[i][c2]);
                auto iter = pair_to_row.find(tuple);
                if (iter != pair_to_row.end()) {
                    cout << "NO\n";
                    cout << iter->second + 1 << ' ' << i + 1 << endl;
                    cout << c1 + 1 << ' ' << c2 + 1 << endl;
                    return;
                }
                pair_to_row[tuple] = i;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    int n, m;
    stringstream ss;
    while (cin >> n >> m) {
        cin.get();
        map<string, int> string_to_id;
        for (int i = 0; i < n; ++i) {
            char c;
            int j = 0;
            while (true) {
                c = cin.get();
                if (c == ',' || c == '\n') {
                    string input = ss.str();
                    ss.str("");
                    int string_id;
                    auto iter = string_to_id.find(input);
                    if (iter == string_to_id.end()) {
                        string_id = string_to_id.size();
                        string_to_id[input] = string_id;
                    } else {
                        string_id = iter->second;
                    }
                    database[i][j] = string_id;
                    if (c == '\n')
                        break;
                    ++j;
                    continue;
                }
                ss << c;
            }
        }
        check(n, m);
    }
    return 0;
}