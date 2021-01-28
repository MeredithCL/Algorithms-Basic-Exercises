#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int qval = q->val;
        int pval = p->val;
        int parental = root->val;
        TreeNode* node = root;
        while (node)
        {
            parental = node->val;
            if (pval > parental)
            {
                if (qval > parental)
                {
                    node = node->right;
                }
                else
                {
                    return node;
                }
            }
            else if (pval < parental)
            {
                if (qval < parental)
                {
                    node = node->left;
                }
                else
                {
                    return node;
                }
            }
            else
            {
                return node;
            }
        }
        return NULL;
    }
};
