#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int kase = 0; kase < t; ++kase) {
        vector<set<int>> sets;
        stack<int> stack_of_set_id;
        map<set<int>, int> set_to_id;
        // 空集
        sets.emplace_back();
        set_to_id[sets[0]] = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string op;
            cin >> op;
            char op0 = op[0];
            if (op0 == 'P') {
                stack_of_set_id.push(0);
            } else if (op0 == 'D') {
                stack_of_set_id.push(stack_of_set_id.top());
            } else {
                int first = stack_of_set_id.top();
                set<int>& first_set = sets[first];
                stack_of_set_id.pop();
                int second = stack_of_set_id.top();
                set<int>& second_set = sets[second];
                stack_of_set_id.pop();
                set<int> new_set;
                if (op0 == 'A') {
                    new_set = second_set;
                    new_set.insert(first);
                } else if (op0 == 'U') {
                    set_union(first_set.begin(), first_set.end(),
                        second_set.begin(), second_set.end(),
                        inserter(new_set, new_set.begin()));
                } else {
                    set_intersection(first_set.begin(), first_set.end(),
                        second_set.begin(), second_set.end(),
                        inserter(new_set, new_set.begin()));
                }
                // push new set
                int new_set_id;
                auto iter = set_to_id.find(new_set);
                if (iter != set_to_id.end()) {
                    new_set_id = iter->second;
                } else {
                    sets.push_back(new_set);
                    new_set_id = sets.size() - 1;
                    set_to_id[new_set] = new_set_id;
                }
                stack_of_set_id.push(new_set_id);
            }
            cout << sets[stack_of_set_id.top()].size() << endl;
        }
        cout << "***\n";
    }
}