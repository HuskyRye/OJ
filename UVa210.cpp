#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Program {
    vector<string> insts;
    int pc = 0;
};

int main()
{
    int t;
    cin >> t;
    for (int kase = 0; kase < t; ++kase) {
        if (kase)
            cout << endl;
        int n, t1, t2, t3, t4, t5, Q;
        cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
        cin.get();
        vector<Program> programs;
        string input;
        for (int i = 0; i < n; ++i) {
            Program program;
            while (true) {
                getline(cin, input);
                program.insts.push_back(input);
                if (input == "end")
                    break;
            }
            programs.push_back(program);
        }

        // for (int i = 0; i < n; ++i) {
        //     cout << i << endl;
        //     for (string& inst : programs[i].insts) {
        //         cout << '\t' << inst << endl;
        //     }
        // }

        deque<int> wait_list;
        for (int i = 0; i < n; ++i)
            wait_list.push_back(i);
        queue<int> stop_list;
        map<string, int> vals;
        int lock = -1;
        stringstream ss;
        while (!wait_list.empty()) {
            int current_program = wait_list.front();
            wait_list.pop_front();
            Program& program = programs[current_program];
            int time = Q;
            while (true) {
                // cout << "#" << current_program + 1 << ": " << program.insts[program.pc] << endl;
                ss.clear();
                ss.str(program.insts[program.pc++]);
                string op1;
                ss >> op1;
                if (op1 == "end") {
                    break;
                } else if (op1 == "lock") {
                    if (lock == -1) {
                        lock = current_program;
                    } else {
                        stop_list.push(current_program);
                        --program.pc;
                        break;
                    }
                    time -= t3;
                } else if (op1 == "unlock") {
                    lock = -1;
                    if (!stop_list.empty()) {
                        wait_list.push_front(stop_list.front());
                        stop_list.pop();
                    }
                    time -= t4;
                } else if (op1 == "print") {
                    string op2;
                    ss >> op2;
                    cout << current_program + 1 << ": " << vals[op2] << endl;
                    time -= t2;
                } else {
                    int op2;
                    ss.ignore(3);
                    ss >> op2;
                    vals[op1] = op2;
                    time -= t1;
                }
                if (time <= 0) {
                    wait_list.push_back(current_program);
                    break;
                }
            }
        }
    }
    return 0;
}