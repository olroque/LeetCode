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
    bool hasPathSum(TreeNode* root, int targetSum, int curSum = 0) 
    {
        if (root == NULL) return false;

        curSum += root->val;

        if (root->left == NULL && root->right == NULL && curSum == targetSum) return true;

        if (root->left != NULL)
        {
            if (hasPathSum(root->left, targetSum, curSum) == true) return true;
        } 
        if (root->right != NULL)
        {
            if (hasPathSum(root->right, targetSum, curSum) == true) return true;
        } 
        return false;
    }
};

int main()
{
    int targetSum = 1;

    TreeNode* root = new TreeNode();

    root->val = 0;
    root->left = newNode(1);
    root->right = newNode(1);

    Solution solution;
    bool result = solution.hasPathSum(root, targetSum);

    cout << result << endl;

    return 0;
}