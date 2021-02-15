#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
        {
            return root;
        }
        queue<Node*> q;
        q.push(root);
        int size;
        Node* temp1;
        Node* temp2;
        while (!q.empty())
        {
            size = q.size();
            if (size == 1)
            {
                temp1 = q.front();
                q.pop();
                temp1->next = NULL;
                if (temp1->left)
                {
                    q.push(temp1->left);
                }
                if (temp1->right)
                {
                    q.push(temp1->right);
                }
                continue;
            }
            ++ size;
            while (size --)
            {
                if (size == 1)
                {
                    temp1 = q.front();
                    q.pop();
                    temp1->next = NULL;
                    if (temp1->left)
                    {
                        q.push(temp1->left);
                    }
                    if (temp1->right)
                    {
                        q.push(temp1->right);
                    }
                    break;
                }
                temp1 = q.front();
                q.pop();
                temp2 = q.front();
                temp1->next = temp2;
                if (temp1->left)
                {
                    q.push(temp1->left);
                }
                if (temp1->right)
                {
                    q.push(temp1->right);
                }
            }
        }
        return root;
    }
};
