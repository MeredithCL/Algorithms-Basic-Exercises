#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        deque<int> remains;
        int size = bills.size();
        for (int i = 0; i < size; ++ i)
        {
            if (bills[i]  == 5)
            {
                remains.push_front(5);
                continue;
            }
            else if (bills[i] == 10)
            {
                if (!remains.empty() && remains[0] == 5)
                {
                    remains.pop_front();
                    remains.push_back(10);
                    continue;
                }
                return false;
            }
            if (!remains.empty())
            {
                int s = remains.size();
                if (s > 1)
                {
                    if (s == 2)
                    {
                        if (remains[0] == 5 && remains[1] == 10)
                        {
                            remains.pop_front();
                            remains.pop_front();
                            continue;
                        }
                        else if (remains[0] != 5 || remains[1] != 10)
                        {
                            return false;
                        }
                    }
                    else if (remains[0] == 10)
                    {
                        return false;
                    }
                    remains.pop_front();
                    if (remains[remains.size() - 1] == 10)
                    {
                        remains.pop_back();
                    }
                    else
                    {
                        remains.pop_front();
                        remains.pop_front();
                    }
                    continue;
                }
                return false;
            }
            return false;
        }
        return true;
    }
};
