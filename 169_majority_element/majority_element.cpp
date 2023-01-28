#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        if (nums.size() == 1) {return nums[0];}
        
        int tempNum = nums[0];
        int majorElement = nums[0];
        int count = 0;
        int majorElementCount = 0;

        int i = 0;
        while (nums.size() > 0)
        {
            if (tempNum == nums[i])
            {
                nums.erase(nums.begin() + i);
                count += 1;
                if (i == nums.size())
                {
                    if (nums.size() == 0 && count > majorElementCount)
                    {
                        majorElementCount = count;
                        majorElement = tempNum;
                    }
                    i = 0;
                }
            }
            else if (i != nums.size() - 1) 
            {
                i++;
            }
            else
            {
                if (count > majorElementCount)
                {
                    majorElementCount = count;
                    majorElement = tempNum;
                }
                i = 0; 
                count = 0;
                tempNum = nums[0];
            }
        }
        return majorElement;
    }
};

int main()
{
    vector<int> nums;

    nums.push_back(6);
    nums.push_back(6);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(7);
 
    Solution solution;

    cout << "output: " << solution.majorityElement(nums) << endl;

    return 0;
}