#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int kase = 0; kase < t; ++kase) {
        int n, m;
        cin >> n >> m;
        list<int> q;
        int max_priority = 0;
        for (int i = 0; i < n; ++i) {
            int priority;
            cin >> priority;
            q.push_back(priority);
            max_priority = max(max_priority, priority);
        }
        int wait = 1;
        while (true) {
            if (m == 0 && q.front() >= max_priority)
                break;
            --m;
            if (q.front() >= max_priority) {
                q.pop_front();
                max_priority = *max_element(q.begin(), q.end());
                ++wait;
            } else {
                if (m == -1)
                    m = q.size() - 1;
                q.push_back(q.front());
                q.pop_front();
            }
        }
        cout << wait << endl;
    }
    return 0;
}
