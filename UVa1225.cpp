#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int kase = 0; kase < n; ++kase) {
        int N;
        cin >> N;
        int count[10] = { 0 };
        for (int i = 1; i <= N; ++i) {
            // char num[6] = { 0 };
            // sprintf(num, "%d", N);
            // for (int i = 0; i < strlen(num); ++i) {
            //     ++count[num[i] - '0'];
            // }
            for (int num = i; num; num /= 10) {
                ++count[num % 10];
            }
        }
        cout << count[0];
        for (int i = 1; i < 10; ++i)
            cout << ' ' << count[i];
        cout << endl;
    }
    return 0;
}
