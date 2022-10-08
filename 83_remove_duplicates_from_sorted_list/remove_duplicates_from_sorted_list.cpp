#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
};

class Solution {
public:
    Node* deleteDuplicates(Node* node) 
    {
        if (node == NULL) {return node;}
        if (node->next == NULL) {return node;}

        if (node->val == node->next->val)
        {
            node->next = deleteDuplicates(node->next->next);

            if (node->next != NULL)
            {
                if (node->val == node->next->val)
                {
                    node->next = deleteDuplicates(node->next->next);
                }
            }
            return node;
        }
        else 
        {
            node->next = deleteDuplicates(node->next);
            return node;
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
    cout << "The list: " << endl;
    while (node)
    {
        // cout << node << endl;
        cout << node->val << endl;
        node = node->next;
    }
}

int main()
{
    Node* list = NULL;

    push(&list, 3);
    push(&list, 3);
    push(&list, 3);
    push(&list, 3);
    push(&list, 3);

    Solution solution;
    Node* result = solution.deleteDuplicates(list);

    printList(result);

    return 0;
}