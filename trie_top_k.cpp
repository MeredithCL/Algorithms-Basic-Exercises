#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct Node
    {
        bool end;
        int cnt;
        Node* c[26];
        Node()
        {
            end = false;
            cnt = 0;
            for (int i = 0; i < 26; ++ i)
            {
                c[i] = NULL;
            }
        }
    };
    Node* root = new Node();
    void insertx(string str)
    {
        int l = str.length();
        Node* temp = root;
        int index;
        for (int i = 0; i < l; ++ i)
        {
            index = str[i] - 'a';
            if (!temp->c[index])
            {
                temp->c[index] = new Node();
            }
            temp = temp->c[index];
        }
        temp->end = true;
        temp->cnt ++;
    }
    vector<pair<int, string> > xxx;
    void dfs(Node* root, string temp)
    {
        for (int i = 0; i < 26; ++ i)
        {
            if (root->c[i])
            {
                temp += char(i + 'a');
                if (root->c[i]->end)
                {
                    xxx.push_back({-root->c[i]->cnt, temp});
                }
                dfs(root->c[i], temp);
                temp.pop_back();
            }
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int size = words.size();
        for (int i = 0; i < size; ++ i)
        {
            insertx(words[i]);
        }
        dfs(root, "");
        sort(xxx.begin(), xxx.end());
        vector<string> result;
        for (int i = 0; i < k; ++ i)
        {
            result.push_back(xxx[i].second);
        }
        return result;
    }
};
