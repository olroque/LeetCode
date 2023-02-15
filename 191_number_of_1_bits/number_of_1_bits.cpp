#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        string str;
        int counter = 0;

        // Convert input int to string
        while (n)
        {
            if (n & 1) { str += '1'; }
            else { str += '0'; }
            n>>=1;
        }

        // Count the 1's
        int i = 0;
        while (i < str.size())
        {
            if (str[i] == '1') {counter++;}
            i++;
        }
        
        return counter;
    }
};

int main()
{
    uint32_t n = 00000000000000000000000000001011;

    Solution solution;
    solution.hammingWeight(n);

    return 0;
}