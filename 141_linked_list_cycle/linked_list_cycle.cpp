#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
};


// Approach: Two Pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode *slow = head, *fast = head->next;
        //if there is a cycle, fast will eventually catch up slow
        while (slow != fast)
        {
            if (fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main()
{
    ListNode* head = NULL;
    ListNode* second = NULL;
    ListNode* third = NULL;
    ListNode* forth = NULL;

    head = new ListNode();
    second = new ListNode();
    third = new ListNode();
    forth = new ListNode();

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = forth;

    forth->val = 4;
    forth->next = head;


    Solution solution;
    bool result = solution.hasCycle(head);

    cout << result << endl;

    return 0;
}