#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) 
    {
        int i = 0, x = 1, y = 0, z = 0;

        while (i < n)
        {
            z = x + y;
            y = x;
            x = z;
            i++;
        }

        return z;
    }
};

int main()
{
    int n = 5;

    Solution solution;
    int result = solution.climbStairs(n);

    cout << result << endl;
    
    return 0;
}