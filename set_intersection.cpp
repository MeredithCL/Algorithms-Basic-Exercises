#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> x1;
        set<int> x2;
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> result;
        for (int i = 0; i < size1; ++ i)
        {
            x1.insert(nums1[i]);
        }
        for (int i = 0; i < size2; ++ i)
        {
            x2.insert(nums2[i]);
        }
        size1 = x1.size();
        size2 = x2.size();
        if (size1 < size2)
        {
            auto p1 = x1.begin();
            auto end = x2.end();
            for (int i = 0; i < size1; ++ i)
            {
                if (x2.find(*p1) != end)
                {
                    result.push_back(*p1);
                }
                p1 ++;
            }
        }
        else
        {
            auto p2 = x2.begin();
            auto end = x1.end();
            for (int i = 0; i < size2; ++ i)
            {
                if (x1.find(*p2) != end)
                {
                    result.push_back(*p2);
                }
                p2 ++;
            }
        }
        return result;
    }
};
