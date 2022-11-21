#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
};

TreeNode* newNode(int val)
{
    TreeNode* node = new TreeNode();
    node->val = val;
    node->left = node->right = NULL;

    return node;
}

class Solution {
public:
    vector<int> nodes;

    vector<int> preorderTraversal(TreeNode* root) 
    {
        if (root != NULL)
        {
            nodes.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }

        return nodes;
    }
};

int main()
{
    TreeNode* root = new TreeNode();

    root->val = 2;
    root->right = newNode(3);
    root->right->right = newNode(4);
    root->right->right->right = newNode(5);
    root->right->right->right->right = newNode(6);

    Solution solution;
    solution.preorderTraversal(root);

    return 0;
}