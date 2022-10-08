#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

// Breadth First Traversal (Or Level Order Traversal)
// Preorder Travsal 
// Root-Left-Right


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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if (nums.size() == 1)
        {
            TreeNode* node = new TreeNode;
            node->val = nums[0];
            return node;
        }

        if (nums.size() == 2)
        {
            TreeNode* node = new TreeNode;
            node->val = nums[0];
            TreeNode* next = new TreeNode;
            next->val = nums[1];
            node->right = next;
            return node;
        }

        int mid = ceil((float)nums.size() / 2) - 1;

        TreeNode* node = newNode(nums[mid]);

        vector<int> l_nums;
        vector<int> r_nums;

        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] < nums[mid]) l_nums.push_back(nums[i]);
            if (nums[i] > nums[mid]) r_nums.push_back(nums[i]);
            i++;
        }

        TreeNode* cur_left = new TreeNode;
        node->left = sortedArrayToBST(l_nums);

        TreeNode* cur_right = new TreeNode;
        node->right = sortedArrayToBST(r_nums);


        return node;
    }
};

void printLevelOrder(TreeNode* root)
{
    if (root == NULL) return;

    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        cout << node->val << " ";
        q.pop();

        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
}

int main()
{
    vector<int> nums;

    nums.push_back(-10);
    nums.push_back(-3);
    nums.push_back(0);
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(11);

    Solution solution;
    TreeNode* result = solution.sortedArrayToBST(nums);

    printLevelOrder(result);

    return 0;
}