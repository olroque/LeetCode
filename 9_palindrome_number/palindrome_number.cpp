#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
    {
        // Convert int to string and get length of string
        string y = to_string(x);
        int ySize = y.length();

        // Create empty string to hold palindrome comparison
        string myStr = "";

        // Reverse loop through y to create the palindrome string
        for (int i = ySize - 1; i >= 0; i--)
        {
            myStr += y[i];
        }

        // Compare y with palindrome string
        if (y == myStr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main() {

    int x = -121;

    Solution s;
    s.isPalindrome(x);

    return 0;
}