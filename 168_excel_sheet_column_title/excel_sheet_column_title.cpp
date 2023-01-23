#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string title;
    bool mode_26;

    string convertToTitle(int columnNumber) 
    {
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if (columnNumber % 26 == 0)
        {
            mode_26 = true;
            title.append(1, alphabet[25]);

            if (columnNumber == 26)
            {
                reverse(title.begin(), title.end());
                return title;
            }
            else
            {
                convertToTitle(columnNumber /= 26);
            }
        }
        else 
        {
            if (columnNumber <= 27)
            {
                if (!mode_26)
                {
                    if (columnNumber == 27)
                    {
                        title.append(1, alphabet[0]);
                        convertToTitle(columnNumber /= 26);
                    }
                    else 
                    {
                        title.append(1, alphabet[columnNumber - 1]);
                        reverse(title.begin(), title.end());
                        return title;
                    }
                }
                else 
                {
                    title.append(1, alphabet[columnNumber - 2]);
                    reverse(title.begin(), title.end());
                    return title;
                }
            }
            else 
            {
                if (!mode_26)
                {
                    title.append(1, alphabet[(columnNumber % 26) - 1]);
                    convertToTitle(columnNumber /= 26);
                }
                else 
                {
                    title.append(1, alphabet[(columnNumber % 26) - 2]);
                    convertToTitle(columnNumber /= 26);
                }
            }
        }

        return title;
    }
};

int main() 
{
    // int columnNumber = 28;
    int columnNumber = 702;
    // int columnNumber = 728;

    Solution solution;
    string output;

    // int x = 0;
    // while (x < 9) 
    // {
    //     output = solution.convertToTitle(columnNumber);
    //     cout  << columnNumber << ": " << output << endl;
    //     columnNumber += 26;
    //     x++;
    // }

    output = solution.convertToTitle(columnNumber);
    cout  << columnNumber << ": " << output << endl;

    return 0;
}