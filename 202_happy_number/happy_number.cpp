#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) 
    {
        bool is_happy = false;
        int counter = 0;
        int n_sum = n;
        
        while (true)
        {
            n = n_sum;
            n_sum = 0;
            vector<int> n_digits;
            string str_n = to_string(n);
            for (int i = 0; i < str_n.size(); i++)
            {
                stringstream string;
                string << str_n[i];
                int n_digit;
                string >> n_digit;
                n_digits.push_back(n_digit);
            }

            int num_digit_len = n_digits.size();

            for (int j = 0; j < num_digit_len; j++)
            {
                n_sum += (n_digits[j] * n_digits[j]);
            }
            counter++;
            if (n_sum == 1)
            {
                return true;
            }
            else if (counter > 9)
            {
                return false;
            }
        }
        return false;
    }
};

int main()
{
    int n = 19;

    Solution solution;
    solution.isHappy(n);

    return 0;
};