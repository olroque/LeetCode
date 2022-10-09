#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) 
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (s[i] == s[j]) {i++; j--;}
            else if (!isalnum(s[i])) i++;
            else if (!isalnum(s[j])) j--;
            else return 0;
        }
        return 1;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";

    Solution solution;
    bool result = solution.isPalindrome(s);

    return 0;
}