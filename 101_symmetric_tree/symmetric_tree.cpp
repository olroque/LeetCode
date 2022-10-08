#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
};

class Solution {
public:
    vector<int> lArr;
    vector<int> rArr;

    bool isSymmetric(Node* root) 
    {
        if (root == NULL) return false;

        levelOrderTraversal(root->left, "left");
        levelOrderTraversal(root->right, "right");

        if (lArr.size() != rArr.size()) return false;

        int i = 0;
        while (i < lArr.size())
        {
            if (lArr[i] != rArr[i]) return false;
            i++;
        }

        return true;
    }

    void levelOrderTraversal(Node* root, string side)
    {
        if (root == NULL) return;

        queue<Node*> q;

        q.push(root);

        while (!q.empty())
        {
            Node* node = q.front();
            if (side == "left") lArr.push_back(node->val);
            else rArr.push_back(node->val);
            q.pop();

            if (side == "left")
            {
                if (node->left != NULL) q.push(node->left);
                else if (node->left == NULL) lArr.push_back(0);
                if (node->right != NULL) q.push(node->right);
                else if (node->right == NULL) lArr.push_back(1);
            }
            else
            {
                if (node->right != NULL) q.push(node->right);
                else if (node->right == NULL) rArr.push_back(0);
                if (node->left != NULL) q.push(node->left);
                else if (node->left == NULL) rArr.push_back(1);
            }
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
    root->left->right = newNode(3);
    root->right->right = newNode(3);

    // Node* root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(2);
    // root->left->left = newNode(3);
    // root->left->right = newNode(4);
    // root->right->left = newNode(4);
    // root->right->right = newNode(3);

    Solution solution;
    bool result = solution.isSymmetric(root);

    cout << result << endl;

    return 0;
}