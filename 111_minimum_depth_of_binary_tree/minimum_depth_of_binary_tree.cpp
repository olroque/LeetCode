#include <iostream>

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
    int minDepth(TreeNode* root) 
    {
        if (root == NULL) return 0;

        int lh = minDepth(root->left) + 1;
        int rh = minDepth(root->right) + 1;

        if (lh == 1 && rh > 1) return rh;
        else if (rh == 1 && lh > 1) return lh;

        if (lh < rh) return lh;
        return rh;
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
    int result = solution.minDepth(root);

    cout << result << endl;

    return 0;
}