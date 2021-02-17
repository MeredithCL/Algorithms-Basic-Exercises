#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int nowx = nums[0] + nums[1] + nums[2];
        int i, j;
        for (int x = 0; x < size; ++ x)
        {
            i = x + 1;
            j = size - 1;
            while (i < size && j >= 0 && i < j)
            {
                int temp = nums[x] + nums[i] + nums[j];
                if (abs(temp - target) < abs(nowx - target))
                {
                    nowx = temp;
                }
                if (temp < target)
                {
                    ++ i;
                }
                else if (temp > target)
                {
                    -- j;
                }
                else
                {
                    return target;
                }
            }
        }
        return nowx;
    }
};
