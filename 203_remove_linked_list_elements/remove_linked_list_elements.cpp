#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* newHead = new ListNode();
        ListNode* prevHead = new ListNode();
        ListNode* curHead = new ListNode();

        //Pass by any leading val's
        while (head && head->val == val)
        {
            if (!head->next) {return 0;}
            head = head->next;
        }

        // Create new head after checking for leading val's
        newHead = head;

        // Process rest of the Linked List
        while (head)
        {
            if (head->val != val)
            {
                prevHead = head;
            }
            if (head->next && head->next->val != val)
            {
                curHead = head->next;
                prevHead->next = curHead;
            }
            if (head->val == val && !head->next)
            {
                prevHead->next = nullptr;
            }
            head = head->next;
        }

        return newHead;
    }
};

int main()
{
    return 0;
}