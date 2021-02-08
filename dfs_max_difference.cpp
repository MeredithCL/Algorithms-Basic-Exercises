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
    int result = INT_MIN;
    void dfs(TreeNode* root, int prev_min, int prev_max)
    {
        if (root->val < prev_min)
        {
            prev_min = root->val;
        }
        if (root->val > prev_max)
        {
            prev_max = root->val;
        }
        result = max(result, prev_max - prev_min);
        if (root->left)
        {
            dfs(root->left, prev_min, prev_max);
        }
        if (root->right)
        {
            dfs(root->right, prev_min, prev_max);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
        {
            return 0;
        } 
        dfs(root, INT_MAX, INT_MIN);
        return result;
    }
};
