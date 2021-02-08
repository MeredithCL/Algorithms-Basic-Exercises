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
    int size;
    TreeNode* root = new TreeNode();
    void buildx(vector<int>& nums, int startx, int endx, TreeNode* root)
    {
        int mark = 0;
        int maxi = INT_MIN;
        for (int i = startx; i <= endx; ++ i)
        {
            if (nums[i] > maxi)
            {
                maxi = nums[i];
                mark = i;
            }
        }//find the biggest;
        root->val = maxi;
        if (mark > startx)
        {
            root->left = new TreeNode();
            buildx(nums, startx, mark - 1, root->left);
        }
        if (mark < endx)
        {
            root->right = new TreeNode();
            buildx(nums, mark + 1, endx, root->right);
        }
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        size = nums.size();
        if (!size)
        {
            return root;
        }
        buildx(nums, 0, size - 1, root);
        return root;
    }
};
