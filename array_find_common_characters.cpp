#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int markt[26] = {0};
        int size = A.size();
        int cnt[26] = {0};
        vector<string> result;
        if (!size)
        {
            return result;
        }
        int longevity = 0;
        longevity = A[0].length();
        for (int j = 0; j < longevity; ++ j)
        {
            markt[A[0][j] - 'a'] ++;
        }
        for (int i = 1; i < size; ++ i)
        {
            longevity = A[i].length();
            for (int j = 0; j < 26; ++ j)
            {
                cnt[j] = 0;
            }
            for (int j = 0; j < longevity; ++ j)
            {
                cnt[A[i][j] - 'a'] ++;
            }
            for (int j = 0; j < 26; ++ j)
            {
                markt[j] = min(cnt[j], markt[j]);
            }
        }
        for (int i = 0; i < 26; ++ i)
        {
            for (int j = 0; j < markt[i]; ++ j)
            {
                char c = (char)(i + 'a');
                string str = "";
                str += c;
                result.push_back(str);
            }
        }
        return result;
    }
};
