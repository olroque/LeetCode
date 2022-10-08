#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        // create a list of valid parentheses and get length
        string vp[3] = {"()", "{}", "[]"};
        int vpLength = sizeof(vp) / sizeof(*vp);

        // get lenght of input string 
        int strLength = s.size();

        // check that string is valid length
        if (strLength % 2 != 0)
        {
            return false;
        }

        // loop through string for match 
        for (int i = 0; i < strLength; i++)
        {
            string currentIndex(1, s[i]);
            string nextIndex(1, s[i + 1]);
            string paraenthesesCheck = currentIndex + nextIndex;

            for (int j = 0; j < vpLength; j++)
            {
                if (paraenthesesCheck == vp[j])
                {
                    s.erase(i, 2);
                    strLength = s.size();
                    i = -1;
                    break;
                }
                else 
                {
                    if (j < vpLength - 1)
                    {
                        continue;
                    } 
                    else 
                    {
                        if (i + 1 < strLength)
                        {
                            break;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    string s = "[((((())]))]";

    Solution solution;
    solution.isValid(s);

    return 0;
}