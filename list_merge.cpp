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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* returnhead;
        ListNode* temp1;
        ListNode* temp2;
        if (a == 0)
        {
            returnhead = list2;
            temp1 = list2;
            while (temp1->next)
            {
                temp1 = temp1->next;
            }
            temp2 = list1;
            for (int i = 0; i < b; ++ i)
            {
                temp2 = temp2->next;
            }
            temp1->next = temp2;
            return returnhead;
        }
        returnhead = list1;
        temp1 = list1;
        temp2 = list2;
        ListNode* temp3;
        for (int i = 1; i < a; ++ i)
        {
            temp1 = temp1->next;
        }
        while (temp2->next)
        {
            temp2 = temp2->next;
        }
        temp3 = temp1;
        for (int i = a; i <= b + 1; ++ i)
        {
            temp3 = temp3->next;
        }
        temp1->next = list2;
        temp2->next = temp3;
        return returnhead;
    }
};
