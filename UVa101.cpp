#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> piles[24];

// 找 block 所在的 pile 和 height
void find_block(int block, int& pile, int& height)
{
    for (int i = 0; i < n; ++i) {
        auto iter = find(piles[i].begin(), piles[i].end(), block);
        if (iter != piles[i].end()) {
            pile = i;
            height = iter - piles[i].begin();
            return;
        }
    }
}

// 将 p 堆 h 以上（不包括h）归位
void clear_above(int p, int h)
{
    vector<int>& pile = piles[p];
    int size = pile.size();
    for (int i = h + 1; i < size; ++i) {
        int block = pile[i];
        piles[block].push_back(block);
    }
    pile.resize(h + 1);
}

// 将 pa 堆 ha 及以上摞到 pb 堆
void pile_over(int pa, int ha, int pb)
{
    vector<int>& pile_a = piles[pa];
    vector<int>& pile_b = piles[pb];
    int size_a = pile_a.size();
    for (int i = ha; i < size_a; ++i)
        pile_b.push_back(pile_a[i]);
    pile_a.resize(ha);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        piles[i].push_back(i);
    while (true) {
        string op1;
        cin >> op1;
        if (op1 == "quit")
            break;
        string op2;
        int a, b;
        cin >> a >> op2 >> b;
        int pa, ha, pb, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if (pa == pb)
            continue;
        if (op1 == "move")
            clear_above(pa, ha);
        if (op2 == "onto")
            clear_above(pb, hb);
        pile_over(pa, ha, pb);
    }
    for (int i = 0; i < n; ++i) {
        cout << i << ":";
        for (int block : piles[i])
            cout << ' ' << block;
        cout << endl;
    }
    return 0;
}
