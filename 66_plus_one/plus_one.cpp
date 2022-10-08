#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> myArray;
        string s = "";
        string temp_s = "";
        long long myint;

        for (int i = 0; i < digits.size(); i++)
        {
            s += to_string(digits[i]);
        }

        if (s.size() <= 18)
        {
            long long temp = stoll(s);
            myint = temp+ 1;

            string myString = to_string(myint);

            for (int i = 0; i < myString.size(); i++)
            {
                stringstream string;
                string << myString[i];
                int n;
                string >> n;
                myArray.push_back(n);
            }
        }
        else 
        {
            int caseSize;
            int erase_amount;
            bool allNines = true;

            for (int i = 0; i < digits.size(); i++)
            {
                if (digits[i] != 9)
                {
                    allNines = false;
                    break;
                }
            }
            if (!allNines)
            {
                if (s[s.size() - 5] == '0')
                {
                    caseSize = s.size() - 4;
                    erase_amount = 4;
                }
                else 
                {
                    cout << "here" << endl;
                    caseSize = s.size() -5;
                    erase_amount = 5;
                }

                for (int i = caseSize; i < s.size(); i++)
                {
                    temp_s += s[i];
                }
                s.erase(s.end() - erase_amount, s.end());

                int temp = stoi(temp_s);
                myint = temp + 1;

                string myString = to_string(myint);

                for (int i = 0; i < s.size(); i++)
                {
                    stringstream string;
                    string << s[i];
                    int n;
                    string >> n;
                    myArray.push_back(n);
                }
                for (int i = 0; i < myString.size(); i++)
                {
                    stringstream string;
                    string << myString[i];
                    int n;
                    string >> n;
                    myArray.push_back(n);
                }
            }
            else 
            {
                myArray.push_back(1);
                for (int i = 0; i < digits.size(); i++)
                {
                    myArray.push_back(0);
                }
            }
        }
        return myArray;
    }
};

int main()
{

    vector<int> digits;

    digits.push_back(6);
    digits.push_back(1);
    digits.push_back(4);
    digits.push_back(5);
    digits.push_back(3);
    
    digits.push_back(9);
    digits.push_back(0);
    digits.push_back(1);
    digits.push_back(9);
    digits.push_back(5);

    digits.push_back(1);
    digits.push_back(8);
    digits.push_back(6);
    digits.push_back(7);
    digits.push_back(0);

    digits.push_back(5);
    digits.push_back(5);
    digits.push_back(4);
    digits.push_back(3);
    // digits.push_back(1);

    Solution solution;
    vector<int> result = solution.plusOne(digits);
    
    // solution.plusOne(digits);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}