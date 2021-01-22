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
    bool flag = true;
    int dfs(TreeNode* root, int nowcnt)
    {
        if (!root)
        {
            return nowcnt;
        }
        nowcnt ++;
        int left = dfs(root->left, nowcnt);
        int right = dfs(root->right, nowcnt);
        if (abs(left - right) > 1)
        {
            flag = false;
        }
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        dfs(root, 0);
        if (flag)
        {
            return true;
        }
        return false;
    }
};
