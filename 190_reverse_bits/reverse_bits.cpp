#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {        
        string str;
        string output_str;

        // Convert input int to string
        while (n)
        {
            if (n & 1) { str += '1'; }
            else { str += '0'; }
            n>>=1;
        }

        // Add trailing 0's
        while (str.size() < 32) { str.push_back('0'); }

        // Reverse the string
        int i = 0;
        while (i < str.size())
        {
            output_str.push_back(str[i]);
            i++;
        }

        // Converted output string to int
        uint32_t dec_num = 0;
        int power = 0;
        int output_str_length = output_str.size();

        for (int j = output_str_length - 1; j >= 0; j--)
        {
            if (output_str[j] == '1') { dec_num += (1<<power); }
            power++;
        }

        return dec_num;
    }
};

int main()
{
    uint32_t n = 43261596;
    
    Solution solution;
    solution.reverseBits(n);

    return 0;
};