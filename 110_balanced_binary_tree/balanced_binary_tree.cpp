#include <iostream>
#include <cmath>

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
    bool is_balanced;

    bool isBalanced(TreeNode* root) 
    {
        is_balanced = true;

        getHeight(root);

        return is_balanced;
    }

    int getHeight(TreeNode* node)
    {
        if (node == NULL) return -1;

        int lh = getHeight(node->left) + 1;
        int rh = getHeight(node->right) + 1;

        if (abs(lh - rh) > 1) is_balanced = false;

        if (lh > rh) return lh;
        else return rh;
    }
};

int main()
{
    TreeNode* root = new TreeNode();
    
    root->val = 3;
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    root->right->right->left = newNode(2);

    Solution solution;
    bool result = solution.isBalanced(root);

    cout << result << endl;

    return 0;
}