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
    vector<TreeNode*> result;
    set<int> dx;
    void dfs(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        auto endx = dx.end();
        if (dx.find(root->val) != endx)
        {
            if (root->left)
            {
                if (dx.find(root->left->val) == endx)
                {
                    result.push_back(root->left);
                    dfs(root->left);
                }
                else
                {
                    dfs(root->left);
                }
            }
            if (root->right)
            {
                if (dx.find(root->right->val) == endx)
                {
                    result.push_back(root->right);
                    dfs(root->right);
                }
                else
                {
                    dfs(root->right);
                }
            }
            return;
        }
        //root can be preserved
        if (root->left)
        {
            if (dx.find(root->left->val) == endx)
            {
                dfs(root->left);
            }
            else
            {
                TreeNode* temp1 = root->left;
                root->left = NULL;
                dfs(temp1);
            }
        }
        if (root->right)
        {
            if (dx.find(root->right->val) == endx)
            {
                dfs(root->right);
            }
            else
            {
                TreeNode* temp2 = root->right;
                root->right = NULL;
                dfs(temp2);
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root)
        {
            return result;
        }
        int size = to_delete.size();
        if (!size)
        {
            result.push_back(root);
            return result;
        }
        for (int i = 0; i < size; ++ i)
        {
            if (dx.find(to_delete[i]) == dx.end())
            {
                dx.insert(to_delete[i]);
            }
        }
        if (dx.find(root->val) == dx.end())
        {
            result.push_back(root);
        }
        dfs(root);
        return result;
    }
};
