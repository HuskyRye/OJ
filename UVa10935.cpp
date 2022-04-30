#include <iostream>
#include <queue>
using namespace std;

int main()
{
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        if (n == 1) {
            cout << "Discarded cards:\nRemaining card: 1\n";
            continue;
        }
        queue<int> cards;
        for (int i = 3; i <= n; ++i)
            cards.push(i);
        cards.push(2);
        cout << "Discarded cards: 1";
        while (cards.size() >= 2) {
            cout << ", " << cards.front();
            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }
        cout << "\nRemaining card: " << cards.front() << endl;
    }
    return 0;
}