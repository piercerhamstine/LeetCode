#include <iostream>

 struct ListNode 
 {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    // While either list has nodes, we continue looping.
    while(l1->next || l2->next)
    {
        int addRes = 0;

        if(l1)
        {
            addRes += l1->val;
        }

        if(l2)
        {
            addRes += l2->val;
        }

        // Check if we need to handle a carry-over.
        if(addRes >= 10)
        {
            // Handle carry over.
        }
    }
};

int main()
{

};