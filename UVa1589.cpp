#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

char qipan[11][10];

struct Point {
    int r;
    int c;
    Point(int row, int col)
    {
        r = row;
        c = col;
    }
};

bool G_row(int r, int c)
{
    for (int row = r + 1; row <= 10; ++row) {
        char qi = qipan[row][c];
        if (qi == 'C' || qi == 'H' || qi == 'R')
            return true;
        if (qi == 'G')
            return false;
    }
    return true;
}

bool GR_row(int r, int c)
{
    for (int row = r + 1; row <= 10; ++row) {
        char qi = qipan[row][c];
        if (qi == 'C' || qi == 'H')
            break;
        if (qi == 'R' || qi == 'G')
            return false;
    }
    for (int row = r - 1; row >= 1; --row) {
        char qi = qipan[row][c];
        if (qi == 'C' || qi == 'H')
            break;
        if (qi == 'R')
            return false;
    }
    return true;
}

bool R_col(int r, int c)
{
    for (int col = c + 1; col <= 9; ++col) {
        char qi = qipan[r][col];
        if (qi == 'C' || qi == 'H')
            break;
        if (qi == 'R')
            return false;
    }
    for (int col = c - 1; col >= 1; --col) {
        char qi = qipan[r][col];
        if (qi == 'C' || qi == 'H')
            break;
        if (qi == 'R')
            return false;
    }
    return true;
}

bool C_row(int r, int c)
{
    bool helper = false;
    for (int row = r + 1; row <= 10; ++row) {
        if (helper && qipan[row][c] == 'C')
            return false;
        if (qipan[row][c] != '\0') {
            if (!helper) {
                helper = true;
                continue;
            }
            break;
        }
    }
    helper = false;
    for (int row = r - 1; row >= 1; --row) {
        if (helper && qipan[row][c] == 'C')
            return false;
        if (qipan[row][c] != '\0') {
            if (!helper) {
                helper = true;
                continue;
            }
            break;
        }
    }
    return true;
}

bool C_col(int r, int c)
{
    bool helper = false;
    for (int col = c + 1; col <= 9; ++col) {
        if (helper && qipan[r][col] == 'C')
            return false;
        if (qipan[r][col] != '\0') {
            if (!helper) {
                helper = true;
                continue;
            }
            break;
        }
    }
    helper = false;
    for (int col = c - 1; col >= 1; --col) {
        if (helper && qipan[r][col] == 'C')
            return false;
        if (qipan[r][col] != '\0') {
            if (!helper) {
                helper = true;
                continue;
            }
            break;
        }
    }
    return true;
}

inline bool valid(int r, int c)
{
    return 1 <= r && r <= 10 && 1 <= c && c <= 9;
}

Point horses[8] = {
    Point(-2, -1),
    Point(-2, 1),
    Point(2, -1),
    Point(2, 1),
    Point(1, 2),
    Point(1, -2),
    Point(-1, 2),
    Point(-1, -2)
};

Point horses_check[8] = {
    Point(-1, -1),
    Point(-1, 1),
    Point(1, -1),
    Point(1, 1),
    Point(1, 1),
    Point(1, -1),
    Point(-1, 1),
    Point(-1, -1)
};

bool H(int r, int c)
{
    for (int i = 0; i < 8; ++i) {
        Point horse = horses[i];
        if (!valid(r + horse.r, c + horse.c))
            continue;
        if (qipan[r + horse.r][c + horse.c] == 'H') {
            Point check = horses_check[i];
            if (qipan[r + check.r][c + check.c] == '\0')
                return false;
        }
    }
    return true;
}

int main()
{
    int n, r, c;
    for (int kase = 1;; ++kase) {
        cin >> n >> r >> c;
        if (n == 0 && r == 0 && c == 0)
            break;
        memset(qipan, 0, sizeof(qipan));
        for (int i = 0; i < n; ++i) {
            char type;
            int row, col;
            cin >> type >> row >> col;
            qipan[row][col] = type;
        }
        vector<Point> possible_move;
        if (c == 4 || c == 6)
            possible_move.push_back(Point(r, 5));
        else {
            possible_move.push_back(Point(r, 4));
            possible_move.push_back(Point(r, 6));
        }
        if (r == 1 || r == 3)
            possible_move.push_back(Point(2, c));
        else {
            possible_move.push_back(Point(1, c));
            possible_move.push_back(Point(3, c));
        }

        if (!G_row(r, c)) {
            cout << "NO\n";
            continue;
        }
        for (auto it = possible_move.begin(); it != possible_move.end();) {
            int row = it->r;
            int col = it->c;
            if (!GR_row(row, col) || !R_col(row, col) || !C_row(row, col) || !C_col(row, col) || !H(row, col)) {
                it = possible_move.erase(it);
                continue;
            }
            ++it;
        }
        cout << (possible_move.size() ? "NO\n" : "YES\n");
    }
}
