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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        bool flag = false;
        if (!root)
        {
            return 0;
        }
        q.push(root);
        TreeNode* temp;
        int result = 0;
        while (!q.empty())
        {
            int size = q.size();
            flag = false;
            for (int i = 0; i < size; ++ i)
            {
                temp = q.front();
                q.pop();
                if (temp->left)
                {
                    flag = true;
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    flag = true;
                    q.push(temp->right);
                }
                else if (!temp->left && !temp->right && !i)
                {
                    result = temp->val;
                }
            }
            if (!flag)
            {
                return result;
            }
        }
        return 0;
    }
};
