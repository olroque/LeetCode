#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
};

Node* createNode(int val)
{
    Node* newNode = new Node();
    newNode->val = val;
    newNode->left =newNode->right = nullptr;
    return newNode;
}

class Solution {
public:
    vector<int> arr;
    
    void inorderTraversalR(Node* root) 
    {        
        if (root == nullptr) return;
        
        inorderTraversal(root->left);
        arr.push_back(root->val);
        inorderTraversal(root->right);
    }

    vector<int> inorderTraversal(Node* root) 
    {        
        inorderTraversalR(root);
        return arr;
    }
};

int main()
{
    // level 1
    Node* root = createNode(1);

    // level 2
    root->right = createNode(2);

    // level 3
    root->right->left = createNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    int i = 0;
    while (i < result.size())
    {
        cout << result[i] << endl;
        i++;
    }

    return 0;
}