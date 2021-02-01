#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1)
        {
            return true;
        }
        long long in = 1;
        long long ax;
        if (num <= 10)
        {
            ax = num;
        }
        else
        {
            ax = num/2;
        }
        if (in*in == num)
        {
            return true;
        }
        else if (ax*ax == num)
        {
            return true;
        }
        long long middle;
        while (ax - in > 1)
        {
            middle = (ax + in) / 2;
            if (middle*middle == num)
            {
                return true;
            }
            else if (middle*middle < num)
            {
                in = middle + 1;
            }
            else if (middle*middle > num)
            {
                ax = middle - 1;
            }
            if (in*in == num)
            {
                return true;
            }
            else if (ax*ax == num)
            {
                return true;
            }
        }
        return false;
    }
};
