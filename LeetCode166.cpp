#include <map>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        stringstream result;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            result << '-';
        long long a = abs(numerator);
        long long b = abs(denominator);
        result << a / b;
        long long remainder = a % b;
        if (remainder == 0) {
            return result.str();
        }
        map<long long, int> remainders;
        stringstream rss;
        while (remainders.count(remainder) == 0 && remainder != 0) {
            remainders[remainder] = remainders.size();
            remainder *= 10;
            rss << remainder / b;
            remainder = remainder % b;
        }
        result << '.';
        string rs = rss.str();
        if (remainder != 0) {
            int pos = remainders[remainder];
            int i = 0;
            while (i < pos)
                result << rs[i++];
            result << '(';
            while (i < rs.length())
                result << rs[i++];
            result << ')';
        } else {
            result << rs;
        }
        return result.str();
    }
};
