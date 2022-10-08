#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
};


class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) 
    {
        if (!list1) 
        {
            return list2;
        }
        if (!list2) 
        {
            return list1;
        }
        
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        

    }
};

void push(Node** head_ref, int new_val)
{
    Node* new_node = new Node();
    new_node->val = new_val;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node *node)
{
    while (node)
    {
        cout << node->val << endl;
        node = node->next;
    }
}

int main() {

    Node* l1 = NULL;
    Node* l2 = NULL;
    
    push(&l1, 4);
    push(&l1, 2);
    push(&l1, 1);
    
    push(&l2, 17);
    push(&l2, 7);
    push(&l2, 7);
    push(&l2, 3);
    push(&l2, 0);

    
    Solution solution;
    Node* mergedHead = solution.mergeTwoLists(l1, l2);
    printList(mergedHead);

}