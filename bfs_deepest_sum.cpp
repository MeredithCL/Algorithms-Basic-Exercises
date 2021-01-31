#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int result = 0;
        if (!root)
        {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        int size;
        int flag = true;
        while (!q.empty())
        {
            size = q.size();
            flag = true;
            result = 0;
            for (int i = 0; i < size; ++ i)
            {
                temp = q.front();
                result += temp->val;
                q.pop();
                if (temp->left)
                {
                    flag = false;
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    flag = false;
                    q.push(temp->right);
                }
            }
            if (flag)
            {
                return result;
            }
        }
        return result;
    }
};
