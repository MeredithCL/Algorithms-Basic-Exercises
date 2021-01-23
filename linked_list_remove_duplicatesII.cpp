#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int mark = 0;
        if (!head || !head->next)
        {
            return head;
        }
        while (head && head->next && head->next->val == head->val)
        {
            mark = head->val;
            while (head && head->val == mark)
            {
                head = head->next;
            }
        }
        if (!head)
        {
            return head;
        }
        ListNode* prev = head;
        ListNode* nowx = head->next;
        while (prev && nowx)
        {
            if (nowx->next && nowx->val == nowx->next->val)
            {
                mark = nowx->val;
                while (nowx && nowx->val == mark)
                {
                    nowx = nowx->next;
                }
                prev->next = nowx;
            }
            else
            {
                prev = nowx;
                nowx = nowx->next;
            }
        }
        return head;
    }
};
