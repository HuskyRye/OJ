#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<pair<int, int>>& points, double avg_x)
{
    int size = points.size();
    if (size % 2 == 1 && fabs(points[size / 2].first - avg_x) > 1e-4)
        return false;
    for (int i = 0; i < size / 2; ++i) {
        pair<int, int>& left = points[i];
        pair<int, int>& right = points[size - i - 1];
        if (left.first >= avg_x)
            break;
        if (left.second != right.second)
            return false;
        if ((2 * avg_x - left.first - right.first) > 1e-4)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    for (int kase = 0; kase < t; ++kase) {
        int n;
        cin >> n;
        vector<pair<int, int>> points;
        double avg_x = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            avg_x += x;
            points.emplace_back(x, y);
        }
        avg_x /= n;
        sort(points.begin(), points.end(), [avg_x](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                return (a.first < avg_x) ? (a.second > b.second) : (a.second < b.second);
            }
            return a.first < b.first;
        });
        // for (auto point : points) {
        //     cout << point.first << ' ' << point.second << endl;
        // }
        cout << (check(points, avg_x) ? "YES" : "NO") << endl;
    }
    return 0;
}