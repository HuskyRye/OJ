#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool check_zero(vector<int>& sequence, int n)
{
    for (int i = 0; i < n; ++i) {
        if (sequence[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    for (int kase = 0; kase < t; ++kase) {
        int n;
        cin >> n;
        vector<int> sequence;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            sequence.push_back(temp);
        }
        set<vector<int>> sequences;
        sequences.insert(sequence);
        while (true) {
            if (check_zero(sequence, n)) {
                cout << "ZERO\n";
                break;
            }
            vector<int> new_sequence = sequence;
            for (int i = 0; i < n; ++i)
                new_sequence[i] = abs(sequence[i] - sequence[(i + 1) % n]);
            sequence = new_sequence;
            // for (int i = 0; i < n; ++i)
            //     cout << sequence[i] << ' ';
            // cout << endl;
            if (sequences.find(sequence) != sequences.end()) {
                cout << "LOOP\n";
                break;
            }
            sequences.insert(sequence);
        }
    }
    return 0;
}