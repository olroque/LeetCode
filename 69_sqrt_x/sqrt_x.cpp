#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) 
    {
        long long i = 0;
        while (true)
        {
            if (i*i > x)
            {
                return i - 1;
            }
            i++;
        }
    }
};

int main()
{
    int x = 0;

    Solution solution;
    int result = solution.mySqrt(x);

    cout << result << endl;

    return 0;
}