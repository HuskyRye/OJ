#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    for (int kase = 1;; ++kase) {
        int n, q;
        cin >> n >> q;
        if (n == 0 && q == 0)
            break;
        vector<int> marbles;
        for (int i = 0; i < n; ++i) {
            int marble;
            cin >> marble;
            marbles.push_back(marble);
        }
        sort(marbles.begin(), marbles.end());
        cout << "CASE# " << kase << ":\n";
        for (int i = 0; i < q; ++i) {
            int query;
            cin >> query;
            cout << query;
            auto iter = find(marbles.begin(), marbles.end(), query);
            if (iter == marbles.end())
                cout << " not found";
            else
                cout << " found at " << (iter - marbles.begin() + 1);
            cout << endl;
        }
    }
}
