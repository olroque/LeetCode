#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) {return 0;}

        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == target)
            {
                return i;
            }
            i++;
        }
        i = 0;
        while (i < nums.size())
        {
            if (nums[i] > target)
            {
                return i;
            }
            i++;
        }
        return nums.size();
    }
};

int main()
{
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);

    int target = 5;

    Solution s;
    int result = s.searchInsert(nums, target);

    cout << result << endl;

    return 0;
}