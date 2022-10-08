#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
};

class Solution {
public:
    int maxDepth(Node* root) 
    {
        int h = height(root);   

        return h;                     
    }

    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int lheight = height(node->left);           
            int rheight = height(node->right);          

            if (lheight > rheight) return (lheight + 1);
            else return (rheight + 1);
        }
    }
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    Solution solution;
    int result = solution.maxDepth(root);

    cout << result << endl;

    return 0;
}