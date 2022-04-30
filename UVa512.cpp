#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct OP {
    string oper;
    vector<int> opes;
};

int main()
{
    int r, c;
    for (int kase = 1;; ++kase) {
        cin >> r >> c;
        if (r == 0 && c == 0)
            break;
        if (kase != 1)
            cout << '\n';
        cout << "Spreadsheet #" << kase << endl;
        int n;
        cin >> n;
        vector<OP> ops;
        for (int i = 0; i < n; ++i) {
            OP op = OP();
            cin >> op.oper;
            int A;
            if (op.oper == "EX")
                A = 4;
            else
                cin >> A;
            for (int j = 0; j < A; ++j) {
                int ope;
                cin >> ope;
                op.opes.push_back(ope);
            }
            ops.push_back(op);
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int row, col;
            cin >> row >> col;
            cout << "Cell data in (" << row << ',' << col << ") ";
            bool gone = false;
            for (OP op : ops) {
                string oper = op.oper;
                if (oper == "DC") {
                    if (find(op.opes.begin(), op.opes.end(), col) != op.opes.end()) {
                        gone = true;
                        break;
                    }
                    col -= count_if(op.opes.begin(), op.opes.end(), [col](int ope) { return ope < col; });
                } else if (oper == "DR") {
                    if (find(op.opes.begin(), op.opes.end(), row) != op.opes.end()) {
                        gone = true;
                        break;
                    }
                    row -= count_if(op.opes.begin(), op.opes.end(), [row](int ope) { return ope < row; });
                } else if (oper == "IC") {
                    col += count_if(op.opes.begin(), op.opes.end(), [col](int ope) { return ope <= col; });
                } else if (oper == "IR") {
                    row += count_if(op.opes.begin(), op.opes.end(), [row](int ope) { return ope <= row; });
                } else if (oper == "EX") {
                    if (row == op.opes[0] && col == op.opes[1]) {
                        row = op.opes[2];
                        col = op.opes[3];
                    } else if (row == op.opes[2] && col == op.opes[3]) {
                        row = op.opes[0];
                        col = op.opes[1];
                    }
                }
            }
            if (gone)
                cout << "GONE\n";
            else
                cout << "moved to (" << row << ',' << col << ")\n";
        }
    }
    return 0;
}