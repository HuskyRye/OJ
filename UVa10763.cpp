#include <iostream>
#include <map>
using namespace std;

bool check(map<pair<int, int>, int>& exchange_infos)
{
    for (auto iter : exchange_infos) {
        if (iter.second)
            return false;
    }
    return true;
}

int main()
{
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        map<pair<int, int>, int> exchange_infos;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            auto iter = exchange_infos.find(pair<int, int>(b, a));
            if (iter == exchange_infos.end()) {
                iter = exchange_infos.find(pair<int, int>(a, b));
                if (iter == exchange_infos.end())
                    exchange_infos[pair<int, int>(a, b)] = 1;
                else
                    ++(iter->second);
            } else
                --(iter->second);
        }
        cout << (check(exchange_infos) ? "YES" : "NO") << endl;
    }
}