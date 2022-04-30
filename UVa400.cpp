#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        vector<string> files;
        size_t longest = 0;
        for (int i = 0; i < n; ++i) {
            string file;
            cin >> file;
            files.push_back(file);
            longest = max(longest, file.length());
        }
        sort(files.begin(), files.end());
        cout << "------------------------------------------------------------\n";
        int col = 62 / (longest + 2);
        int row = files.size() / col;
        int remainder = files.size() % col;
        if (remainder) {
            ++row;
            remainder = files.size() % row;
        } else
            remainder = row;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < (col - 1); ++j) {
                if (j)
                    cout << "  ";
                cout << left << setw(longest) << files[j * row + i];
            }
            if (i < remainder) {
                if (col - 1)
                    cout << "  ";
                cout << left << setw(longest) << files[(col - 1) * row + i];
            }
            cout << endl;
        }
    }
    return 0;
}