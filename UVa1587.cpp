#include <iostream>
#include <map>
#include <set>
using namespace std;

bool solve()
{
    map<int, int> counts;
    set<int> squares;
    int length1, length2;
    for (int i = 0; i < 6; ++i) {
        if (!(cin >> length1 >> length2))
            return false;
        if (counts.find(length1) == counts.end())
            counts[length1] = 0;
        if (counts.find(length2) == counts.end())
            counts[length2] = 0;
        ++counts[length1];
        ++counts[length2];
        if (length1 == length2) {
            squares.insert(length1);
        }
    }

    for (auto pair : counts) {
        int length = pair.first;
        int count = pair.second;
        if (squares.find(length) != squares.end()) {
            if (count < 8 || count % 4 != 0) {
                cout << "IMPOSSIBLE\n";
                return true;
            }
        } else if (count < 4 || count % 4 != 0) {
            cout << "IMPOSSIBLE\n";
            return true;
        }
    }
    cout << "POSSIBLE\n";
    return true;
}

int main()
{
    while (solve())
        ;
}