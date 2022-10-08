#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        if (s.size() == 0) {return 0;}

        int k = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (s[j] != ' ')
                    {
                        k++;
                        if (s[j + 1] == ' ' || j == s.size() -1)
                        {
                            return k;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                k++;
            }
        }

        return k;
    }
};

int main()
{
    string s = "a";


    Solution solution;
    int result = solution.lengthOfLastWord(s);

    cout << "result: " << result << endl;

    return 0;
}