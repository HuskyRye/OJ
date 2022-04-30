#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Book {
    string title;
    string author;
    Book(string title, string author)
        : title(title)
        , author(author)
    {
    }
};

int main()
{
    stringstream ss;
    vector<Book> books;
    // input books
    while (true) {
        char c = cin.get();
        if (c == 'E') {
            cin.get(); // 'N'
            cin.get(); // 'D'
            break;
        }
        while (c = cin.get(), c != '"')
            ss << c;
        string title = ss.str();
        for (int i = 0; i < 4; ++i) // " by "
            cin.get();
        ss.str("");
        while (c = cin.get(), c != '\n')
            ss << c;
        string author = ss.str();
        ss.str("");
        books.emplace_back(title, author);
    }

    // sort by author then title
    sort(books.begin(), books.end(), [](Book& b1, Book& b2) {
        return (b1.author == b2.author) ? (b1.title < b2.title) : (b1.author < b2.author);
    });

    // simulate
    list<int> shelve;
    map<string, int> title_to_id;
    for (int i = 0; i < books.size(); ++i) {
        shelve.push_back(i);
        title_to_id[books[i].title] = i;
    }
    vector<int> return_books;
    while (true) {
        string op;
        cin >> op;
        char op0 = op[0];
        if (op0 == 'E')
            break;
        if (op0 == 'S') {
            sort(return_books.begin(), return_books.end());
            for (int book_id : return_books) {
                auto iter = shelve.begin();
                // find the correct position to insert
                for (; iter != shelve.end(); ++iter) {
                    if (*iter > book_id)
                        break;
                }
                cout << "Put \"" << books[book_id].title << "\" ";
                if (iter == shelve.begin()) {
                    cout << "first\n";
                } else {
                    cout << "after \"" << books[*(--iter)].title << "\"\n";
                    ++iter;
                }
                shelve.insert(iter, book_id);
            }
            cout << "END\n";
            return_books.clear();
            continue;
        }
        // input book title
        cin.get(); // ' '
        cin.get(); // '"'
        char c;
        while (c = cin.get(), c != '"')
            ss << c;
        string title = ss.str();
        ss.str("");
        int book_id = title_to_id[title];
        if (op0 == 'B')
            shelve.remove(book_id);
        else
            return_books.push_back(book_id);
    }
    return 0;
}
