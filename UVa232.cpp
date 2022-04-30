#include <iomanip>
#include <iostream>
using namespace std;

void solve(int r, int c)
{
    char puzzle[10][10];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            puzzle[i][j] = cin.get();
        }
        cin.get();
    }
    int start[10][10];
    for (int i = 0, count = 1; i < r; ++i)
        for (int j = 0; j < c; ++j)
            start[i][j] = (puzzle[i][j] != '*' && (i == 0 || puzzle[i - 1][j] == '*' || j == 0 || puzzle[i][j - 1] == '*'))
                ? count++
                : 0;

    cout << "Across\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (start[i][j]) {
                cout << setw(3) << start[i][j] << '.' << puzzle[i][j];
                while (++j < c && puzzle[i][j] != '*')
                    cout << puzzle[i][j];
                cout << endl;
            }
        }
    }
    cout << "Down\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (start[i][j]) {
                cout << setw(3) << start[i][j] << '.' << puzzle[i][j];
                for (int row = i + 1; row < r && puzzle[row][j] != '*'; ++row) {
                    cout << puzzle[row][j];
                    start[row][j] = 0; // 在竖着输出时，输出过的方格失去起始资格
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    int r;
    int c;
    for (int kase = 1;; ++kase) {
        cin >> r;
        if (r == 0)
            break;
        cin >> c;
        cin.get();
        if (kase != 1)
            cout << '\n';
        cout << "puzzle #" << kase << ":\n";
        solve(r, c);
    }
}
