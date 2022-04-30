#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

char board[9][9];
int drows[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dcols[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

inline bool valid(int row, int col)
{
    return 1 <= row && row <= 8 && 1 <= col && col <= 8;
}

void move(char current, int r, int c)
{
    board[r][c] = current;
    for (int direction = 0; direction < 8; ++direction) {
        int drow = drows[direction];
        int dcol = dcols[direction];
        bool meet = false;
        for (int row = r + drow, col = c + dcol; valid(row, col); row += drow, col += dcol) {
            if (board[row][col] == '-')
                break;
            if (board[row][col] == current) {
                if (meet) {
                    for (int i = r + drow, j = c + dcol; i != row || j != col; i += drow, j += dcol)
                        board[i][j] = current;
                }
                break;
            } else {
                meet = true;
            }
        }
    }
}

bool check(int i, int j, char current)
{
    if (board[i][j] != '-')
        return false;
    for (int direction = 0; direction < 8; ++direction) {
        int drow = drows[direction];
        int dcol = dcols[direction];
        bool meet = false;
        for (int row = i + drow, col = j + dcol; valid(row, col); row += drow, col += dcol) {
            if (board[row][col] == '-')
                break;
            if (board[row][col] == current) {
                if (meet)
                    return true;
                break;
            } else {
                meet = true;
            }
        }
    }
    return false;
}

bool moves(char current, bool print)
{
    bool has_move = false;
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            if (check(i, j, current)) {
                if (print) {
                    if (has_move)
                        cout << ' ';
                    cout << '(' << i << ',' << j << ')';
                    has_move = true;
                } else {
                    return true;
                }
            }
        }
    }
    if (print) {
        if (!has_move)
            cout << "No legal move.";
        cout << endl;
    }
    return has_move;
}

void count()
{
    int black = 0;
    int white = 0;
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            char c = board[i][j];
            if (c == 'W')
                ++white;
            else if (c == 'B')
                ++black;
        }
    }
    cout << "Black - " << setw(2) << black << " White - " << setw(2) << white << endl;
}

int main()
{
    int N;
    cin >> N;
    for (int kase = 0; kase < N; ++kase) {
        if (kase)
            cout << '\n';
        memset(board, 0, sizeof(board));
        cin.get();
        for (int i = 1; i <= 8; ++i) {
            for (int j = 1; j <= 8; ++j) {
                board[i][j] = cin.get();
            }
            cin.get();
        }
        char current;
        cin >> current;
        while (true) {
            char op;
            cin >> op;
            if (op == 'Q') {
                for (int i = 1; i <= 8; ++i) {
                    for (int j = 1; j <= 8; ++j) {
                        cout << board[i][j];
                    }
                    cout << endl;
                }
                break;
            }
            if (op == 'L') {
                moves(current, true);
            } else {
                int r = cin.get() - '0';
                int c = cin.get() - '0';
                if (!moves(current, false))
                    current = (current == 'W') ? 'B' : 'W';
                move(current, r, c);
                count();
                current = (current == 'W') ? 'B' : 'W';
            }
        }
    }
}
