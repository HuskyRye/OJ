#include <iostream>
using namespace std;

bool solve()
{
    int bar1[100];
    int bar2[100];
    int length1 = 0, length2 = 0;
    char c;
    while (c = cin.get(), c != EOF && c != '\n')
        bar1[length1++] = c - '0';
    if (c == EOF)
        return false;
    while (c = cin.get(), c != '\n')
        bar2[length2++] = c - '0';

    int* longer = bar1;
    int* shorter = bar2;
    if (length1 < length2) {
        swap(longer, shorter);
        swap(length1, length2);
    }
    int result = length1 + length2;
    for (int i = -length2 + 1; i < length1; ++i) {
        int j = 0, k = i;
        for (; j < length2 && k < length1; ++j, ++k) {
            if (k < 0)
                continue;
            if (longer[k] + shorter[j] > 3)
                break;
        }
        if (j == length2 || k == length1) {
            int length = length1 + length2 - j;
            if (i < 0) {
                length -= i;
            }
            result = min(length, result);
            continue;
        }
    }
    cout << result << endl;
    return true;
}

int main()
{
    while (solve())
        ;
}
