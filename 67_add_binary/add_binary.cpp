#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) 
    {

        string bigStr;
        string smallStr;

        if (a.size() >= b.size()) { bigStr = a; smallStr = b;}
        else { bigStr = b; smallStr = a;}

        while (bigStr.size() - smallStr.size() > 0) {smallStr.insert(0, "0");}
        
        int i = bigStr.size() -1;

        int carry = 0;

        while (i >= 0)
        {
            int sum = 0;
            if (bigStr[i] - '0' + smallStr[i] - '0' + carry == 0) 
            {   
                carry = 0;
                bigStr[i] = '0';
            }
            else if (bigStr[i] - '0' + smallStr[i] - '0' + carry == 1) 
            {   
                carry = 0;
                bigStr[i] = '1';
            }
            else if (bigStr[i] - '0' + smallStr[i] - '0' + carry == 2) 
            {   
                carry = 1;
                bigStr[i] = '0';
            }
            else
            {   
                carry = 1;
                bigStr[i] = '1';
            }
            if (i == 0 && carry == 1)
            {
                carry = 0;
                bigStr.insert(0, "1");
            }
            i--;
        }
        return bigStr;
    }
};

int main()
{

    string a = "11";
    string b = "1";

    Solution solution;
    string result = solution.addBinary(a, b);

    cout << result << endl;
}