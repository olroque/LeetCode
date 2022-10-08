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
    newNode->right = newNode->right = nullptr;
    return newNode;
}

class Solution {
public:
    vector<int> pArr;
    vector<int> qArr;

    int p_counter = 0;
    int q_counter = 0;

    vector<int> pNull;
    vector<int> qNull; 

    void inorderTraversal(Node* root, int listNum)
    {
        if (listNum == 0) {p_counter++;}
        else {q_counter++;}
        
        if (root == nullptr) 
        {
            if (listNum == 0) {pNull.push_back(p_counter);}
            else {qNull.push_back(q_counter);}

            return;
        }
        inorderTraversal(root->left, listNum);
        if (listNum == 0) {pArr.push_back(root->val);}
        else {qArr.push_back(root->val);}
        inorderTraversal(root->right, listNum);
    }

    bool isSameTree(Node* p, Node* q) 
    {
        inorderTraversal(q, 1);
        inorderTraversal(p, 0);

        if (pArr.size() != qArr.size()) {return false;}
        if (pNull.size() != qNull.size()) {return false;}


        int i = 0;
        while (i < pArr.size())
        {
            if (pArr[i] != qArr[i]) {return false;}
            i++;
        }

        int x = 0;
        while (x < pNull.size())
        {
            if (pNull[x] != qNull[x]) {return false;}
            x++;
        }

        return true;
    }
};

int main()
{
    Node* p = createNode(1);
    Node* q = createNode(1);

    p->left = createNode(1);
    // q->left = createNode(2);

    // p->right = createNode(3);
    q->right = createNode(1);

    Solution solution;
    bool result = solution.isSameTree(p, q);

    cout << result << endl;

}