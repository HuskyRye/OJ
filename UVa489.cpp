#include <iostream>
#include <map>
using namespace std;

bool win(map<char, bool>& check)
{
    for (auto pair : check)
        if (pair.second == false)
            return false;
    return true;
}

void game(string& ans, string& guess)
{
    int wrong = 0;
    map<char, bool> check;
    for (char c : ans)
        check[c] = false;
    for (char c : guess) {
        if (check.find(c) != check.end()) {
            check[c] = true;
            if (win(check)) {
                cout << "You win.\n";
                return;
            }
        } else {
            if (++wrong == 7) {
                cout << "You lose.\n";
                return;
            }
        }
    }
    cout << "You chickened out.\n";
}

int main()
{
    while (true) {
        int round;
        cin >> round;
        if (round == -1)
            break;
        cout << "Round " << round << endl;
        string ans;
        cin >> ans;
        string guess;
        cin >> guess;
        game(ans, guess);
    }
}