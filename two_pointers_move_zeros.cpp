#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int marker = 0;
        int i = 0;
        while (i < size)
        {
            if (nums[i] != 0)
            {
                nums[marker] = nums[i];
                ++ marker;
                ++ i;
                continue;
            }
            else
            {
                ++ i;
            }
        }
        for (; marker < size; ++ marker)
        {
            nums[marker] = 0;
        }
        return;
    }
};
