#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<vector<string>> lines;
    string line;
    vector<size_t> col_width;
    stringstream ss;
    while (getline(cin, line)) {
        vector<string> words;
        ss.str(line);
        string word;
        for (int i = 0; ss >> word; ++i) {
            words.push_back(word);
            if (i == col_width.size())
                col_width.push_back(0);
            col_width[i] = max(col_width[i], word.size());
        }
        lines.push_back(words);
        ss.clear();
    }
    for (vector<string>& words : lines) {
        size_t words_size = words.size();
        for (int i = 0; i < (words_size - 1); ++i) {
            if (i)
                cout << ' ';
            cout << left << setw(col_width[i]) << words[i];
        }
        if (words_size - 1)
            cout << ' ';
        cout << words[words_size - 1] << endl;
    }
    return 0;
}