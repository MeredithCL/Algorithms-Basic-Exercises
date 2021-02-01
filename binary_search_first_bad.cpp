#include <bits/stdc++.h>
using namespace std;
// The API isBadVersion is defined for you.
bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        long long in = 1;
        long long ax = n;
        if (isBadVersion(1))
        {
            return 1;
        }
        long long middle;
        while (in <= ax)
        {
            middle = (in + ax) / 2;
            if (middle == 1)
            {
                ++ middle;
            }
            if (isBadVersion(middle) && !isBadVersion(middle - 1))
            {
                return middle;
            }
            else if (isBadVersion(middle) && isBadVersion(middle - 1))
            {
                ax = middle - 1;
            }
            else if (!isBadVersion(middle - 1))
            {
                in = middle + 1;
            }
        }
        return middle;
    }
};
