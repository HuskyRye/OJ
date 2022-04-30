#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int kase = 0; kase < n; ++kase) {
        int m, n;
        cin >> m >> n;
        cin.get();

        char** sequences = new char*[m];
        for (int i = 0; i < m; ++i)
            sequences[i] = new char[n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sequences[i][j] = cin.get();
            }
            cin.get();
        }

        int dist = 0;
        for (int j = 0; j < n; ++j) {
            int A = 0;
            int C = 0;
            int G = 0;
            int T = 0;
            for (int i = 0; i < m; ++i) {
                if (sequences[i][j] == 'A')
                    ++A;
                else if (sequences[i][j] == 'C')
                    ++C;
                else if (sequences[i][j] == 'G')
                    ++G;
                else if (sequences[i][j] == 'T')
                    ++T;
            }
            if (A >= C && A >= G && A >= T) {
                cout << 'A';
                dist += (C + G + T);
            } else if (C >= A && C >= G && C >= T) {
                cout << 'C';
                dist += (A + G + T);
            } else if (G >= A && G >= C && G >= T) {
                cout << 'G';
                dist += (A + C + T);
            } else if (T >= A && T >= C && T >= G) {
                cout << 'T';
                dist += (A + C + G);
            }
        }
        cout << '\n'
             << dist << '\n';

        for (int i = 0; i < m; ++i)
            delete[] sequences[i];
        delete[] sequences;
    }
}
