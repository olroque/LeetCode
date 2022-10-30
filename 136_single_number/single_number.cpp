#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int i = 0;
        int j = i;
        while (i < nums.size())
        {
            while (j < nums.size())
            {
                j++;
                if (j == nums.size())
                {
                    return nums[i];
                }
                else if (nums[j] == nums[i])
                {
                    nums.erase(nums.begin() + j);
                    i++;
                    j = i;
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);

    Solution solution;
    int res = solution.singleNumber(nums);

    cout << res << endl;

    return 0;
}
