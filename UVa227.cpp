#include <iostream>
using namespace std;

void solve()
{
    char puzzle[5][5];
    int row;
    int col;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            char c = cin.get();
            puzzle[i][j] = c;
            if (c == ' ') {
                row = i;
                col = j;
            }
        }
        cin.get();
    }
    for (char op; op = cin.get(), op != '0';) {
        int next_row = row;
        int next_col = col;
        if (op == 'A')
            next_row -= 1;
        else if (op == 'B')
            next_row += 1;
        else if (op == 'L')
            next_col -= 1;
        else if (op == 'R')
            next_col += 1;
        if (next_row < 0 || next_row > 4 || next_col < 0 || next_col > 4) {
            cout << "This puzzle has no final configuration." << endl;
            while (op = cin.get(), op != '0')
                ;
            cin.get();
            return;
        }
        puzzle[row][col] = puzzle[next_row][next_col];
        puzzle[next_row][next_col] = ' ';
        row = next_row;
        col = next_col;
    }
    cin.get();
    for (int i = 0; i < 5; ++i) {
        cout << puzzle[i][0];
        for (int j = 1; j < 5; ++j)
            cout << ' ' << puzzle[i][j];
        cout << endl;
    }
}

int main()
{
    for (int kase = 1;; ++kase) {
        char z = cin.get();
        if (z == 'Z') {
            break;
        }
        cin.putback(z);
        if (kase != 1)
            cout << '\n';
        cout << "Puzzle #" << kase << ":\n";
        solve();
    }
    return 0;
}