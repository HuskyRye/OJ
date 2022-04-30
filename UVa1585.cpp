#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        int score = 0;
        for (int count = 0; c = cin.get(), c != EOF;) {
            if (c == 'O')
                score += ++count;
            else
                count = 0;
        }
        cout << score << endl;
    }
}
