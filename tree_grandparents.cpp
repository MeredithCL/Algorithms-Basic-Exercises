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
    int sumEvenGrandparent(TreeNode* root) {
        int result = 0;
        if (!root)
        {
            return result;
        }
        queue<TreeNode*> q;
        TreeNode* temp1;
        TreeNode* temp2;
        TreeNode* temp;
        q.push(root);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (!(temp->val % 2))
            {
                if (temp->left)
                {
                    temp1 = temp->left;
                    q.push(temp1);
                    if (temp1->left)
                    {
                        result += temp1->left->val;
                    }
                    if (temp1->right)
                    {
                        result += temp1->right->val;
                    }
                }
                if (temp->right)
                {
                    temp2 = temp->right;
                    q.push(temp2);
                    if (temp2->left)
                    {
                        result += temp2->left->val;
                    }
                    if (temp2->right)
                    {
                        result += temp2->right->val;
                    }
                }
            }
            else
            {
                if (temp->left)
                {
                    temp1 = temp->left;
                    q.push(temp1);
                }
                if (temp->right)
                {
                    temp2 = temp->right;
                    q.push(temp2);
                }
            }
        }
        return result;
    }
};
