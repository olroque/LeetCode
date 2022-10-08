#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        // Empty string to hold common prefix 
        string comPrefix = "";

        // Get size of string 
        int strsSize = strs.size();

        // Check that the vector has more than one element 
        if (strsSize < 2)
        {
            return strs[0];
        }
        else if (strs[0].size() < 1)
        {
            return "";
        }

        // Iterate through string 
        for (int i = 0; i < strs[0].size(); i++)
        {
            string currentIndex(1, strs[0][i]);

            for (int j = 0; j < strsSize; j++)
            {
                string checker(1, strs[j][i]);
                if (checker == currentIndex)
                {
                    continue;
                }
                else 
                {
                    return comPrefix;
                }
            }
            comPrefix += currentIndex;
        }
        return comPrefix;
    }
};

int main() 
{
    vector<string> strs;

    strs.push_back("flower");
    strs.push_back("flower");
    strs.push_back("flower");
    strs.push_back("flower");
    strs.push_back("flowir");
    strs.push_back("flower");


    Solution solution;
    cout << solution.longestCommonPrefix(strs) << endl;

    return 0;
}