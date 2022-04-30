#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    while (true) {
        int n, k, m;
        cin >> n >> k >> m;
        if (n == 0 && k == 0 && m == 0)
            break;
        bool* queue = new bool[n + 1] { false };
        for (int left = n, a = 1, b = n; left > 0;) {
            if (left != n)
                cout << ',';
            for (int i = 0; i < k;) {
                if (queue[a] == false)
                    ++i;
                a += 1;
                if (a == (n + 1))
                    a = 1;
            }
            a -= 1;
            if (a == 0)
                a = n;
            --left;
            cout << setw(3) << a;
            for (int i = 0; i < m;) {
                if (queue[b] == false)
                    ++i;
                b -= 1;
                if (b == 0)
                    b = n;
            }
            b += 1;
            if (b == (n + 1))
                b = 1;
            if (b != a) {
                queue[b] = true;
                --left;
                cout << setw(3) << b;
            }
            queue[a] = true;
        }
        cout << '\n';
        delete[] queue;
    }
}