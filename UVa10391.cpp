#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    set<string> dict;
    string input;
    while (cin >> input)
        dict.insert(input);
    set<string> compounds;
    for (string word : dict) {
        for (int i = 1; i < (word.size()); ++i) {
            if (dict.find(word.substr(0, i)) != dict.end()
                && dict.find(word.substr(i)) != dict.end())
                compounds.insert(word);
        }
    }
    for (string compound : compounds)
        cout << compound << endl;
    return 0;
}
