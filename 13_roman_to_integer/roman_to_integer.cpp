#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) 
    {
        map<string, int> romanNumns;

        romanNumns.insert(pair<string, int>("I", 1));
        romanNumns.insert(pair<string, int>("IV", 4));
        romanNumns.insert(pair<string, int>("V", 5));
        romanNumns.insert(pair<string, int>("IX", 9));
        romanNumns.insert(pair<string, int>("X", 10));
        romanNumns.insert(pair<string, int>("XL", 40));
        romanNumns.insert(pair<string, int>("L", 50));
        romanNumns.insert(pair<string, int>("XC", 90));
        romanNumns.insert(pair<string, int>("C", 100));
        romanNumns.insert(pair<string, int>("CD", 400));
        romanNumns.insert(pair<string, int>("D", 500));
        romanNumns.insert(pair<string, int>("CM", 900));
        romanNumns.insert(pair<string, int>("M", 1000));

        // Create a string that will hold roman numberal characters
        string x;

        // Create an int that will hold the sum
        int total = 0;

        // Loop through the string 
        int stringSize = s.length();
        for (int i = 0; i < stringSize; i++)
        {
            
            string currentIndex(1, s[i]);
            string nextIndex(1, s[i + 1]);

            string twoCharNumerals = currentIndex + nextIndex;

            map<string, int>::iterator it;
            map<string, int>::iterator it1;

            it = romanNumns.find(currentIndex);
            it1 = romanNumns.find(twoCharNumerals);

            if (i + 1 <= stringSize - 1 && it1 != romanNumns.end())
            {
                total += romanNumns.at(twoCharNumerals);
                i++;
            }
            else if (it != romanNumns.end())
            {
                total += romanNumns.at(currentIndex);
            }
            else
            {
                continue;
            }
        }
        return total;
    }
};

int main() {

    string s = "IIII"; 

    Solution solution;
    cout << solution.romanToInt(s) << endl;

    return 0;
}