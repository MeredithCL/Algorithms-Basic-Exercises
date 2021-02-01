#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string S) {
        int size = S.length();
        int balance = 0;
        int result = 0;
        for (int i = 0; i < size; ++ i)
        {
            if (S[i] == ')')
            {
                -- balance;
                if (balance == -1)
                {
                    ++ balance;
                    ++ result;
                }
                continue;
            }
            else if (S[i] == '(')
            {
                ++ balance;
            }
        }
        return balance + result;
    }
};
