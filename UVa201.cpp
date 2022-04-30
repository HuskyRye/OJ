#include <cstring>
#include <iostream>
using namespace std;

bool Hs[10][10];
bool Vs[10][10];

bool check(int size, int i, int j)
{
    // 上
    for (int col = j; col < (j + size); ++col) {
        if (!Hs[i][col])
            return false;
    }
    // 下
    for (int col = j; col < (j + size); ++col) {
        if (!Hs[i + size][col])
            return false;
    }
    // 左
    for (int row = i; row < (i + size); ++row) {
        if (!Vs[row][j])
            return false;
    }
    // 右
    for (int row = i; row < (i + size); ++row) {
        if (!Vs[row][j + size])
            return false;
    }
    return true;
}

int main()
{
    int n, m;
    for (int kase = 1; cin >> n >> m; ++kase) {
        if (kase != 1)
            cout << "\n**********************************\n\n";
        cout << "Problem #" << kase << "\n\n";

        memset(Hs, 0, sizeof(Hs));
        memset(Vs, 0, sizeof(Vs));

        for (int i = 0; i < m; ++i) {
            char direction;
            int r;
            int c;
            cin >> direction >> r >> c;
            if (direction == 'H')
                Hs[r - 1][c - 1]
                    = true;
            else
                Vs[c - 1][r - 1] = true;
        }

        bool notfound = true;
        for (int size = 1; size < n; ++size) {
            int count = 0;
            for (int i = 0; i < (n - size); ++i) {
                for (int j = 0; j < (n - size); ++j) {
                    if (check(size, i, j))
                        ++count;
                }
            }
            if (count) {
                notfound = false;
                cout << count << " square (s) of size " << size << endl;
            }
        }

        if (notfound)
            cout << "No completed squares can be found.\n";
    }
}
