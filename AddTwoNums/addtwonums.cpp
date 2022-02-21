#include <iostream>

 struct ListNode 
 {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// My First-thought solution, not great but it works. Will research better solution and write those as well.
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* res = new ListNode(0);
    ListNode* temp = res;
    int carryOver = 0;

    // While either list has nodes or we have a carry, we continue looping.
    while(l1 != nullptr || l2 != nullptr || carryOver > 0)
    {
        ListNode* next = new ListNode();
        int addRes = carryOver;
        carryOver = 0;

        if(l1 != nullptr)
        {
            addRes += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr)
        {
            addRes += l2->val;
            l2 = l2->next;
        }

        // Check if we need to handle a carry-over.
        if(addRes >= 10)
        {
            temp->val = (addRes % 10);

            while(addRes >= 10)
            {
                addRes = addRes-10;
                carryOver += 1;
            }
        }
        else
        {
            temp->val = addRes;
        }

        // Check if we need to add another node to the list.
        if(l1 != nullptr || l2 != nullptr || carryOver > 0)
        {
            temp->next = next;
        }
        else
        {
            delete next;
            temp->next = nullptr;
        }

        temp = temp->next;
    }

    return res;
};

// Refined solution after looking over better implementations.
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2)
{
    ListNode* result = new ListNode();
    ListNode* temp = result;
    
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr || carry != 0)
    {
        ListNode* next = new ListNode();
        int sum = carry;

        if(l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        };
        if(l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        };
        
        carry = sum/10;
        temp->val = sum%10;

        if(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            temp->next = next;
        }
        else
        {
            delete next;
            temp->next = nullptr;
        }

        temp = temp->next;
    }

    return result;
};

ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2)
{
    ListNode* result = new ListNode();
    ListNode* temp = result;
    int carryOver = 0;

    while(l1 != nullptr || l2 != nullptr || carryOver != 0)
    {
        int sum = carryOver;

        if(l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        ListNode* next = new ListNode(sum%10);
        carryOver = sum/10;
        temp->next = next;
        temp = temp->next;
    };

    temp = result->next;
    delete result;
    return temp;
};

int main()
{
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    ListNode* l2 = new ListNode(9);

    //ListNode* l3 = addTwoNumbers(l1, l2);
    //ListNode* l3 = addtwo(l1, l2);
    ListNode* l3 = addTwoNumbers3(l1, l2);

    while(l3 != nullptr)
    {
        std::cout << l3 << std::endl;
        
        l3 = l3->next;
    }

    return 0;
};