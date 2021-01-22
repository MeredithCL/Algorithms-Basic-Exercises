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
    int target;
    bool dfs(TreeNode* root, int current)
    {
        if (root)
        {
            current += root->val;
            if (!root->left && !root->right)
            {
                return current == target;
            }
            return (dfs(root->left, current) || dfs(root->right, current));
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        target = sum;
        return (dfs(root, 0));
    }
};
