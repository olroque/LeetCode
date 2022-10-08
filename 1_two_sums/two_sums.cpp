#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //   Get length of array 
        int numsLength = nums.size();

        for (int i = 0; i < numsLength; i++)
        {
            int x = 0;

            for (int j = 0; j <= x && x < numsLength; j++)
            {
                if (j == i)
                {
                    continue;
                }
                else
                {
                    if (nums[j] + nums[i] == target)
                    {
                        vector<int> x;
                        x.push_back(i);
                        x.push_back(j);
                        return x;
                    }
                }
                x++;
            }
        }
        vector<int> y;
        return y;
        
    }
};

int main() {

    vector<int> nums;

    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);

    int target = 11;

    Solution solution;
    vector<int> z = solution.twoSum(nums, target);

    for (int i = 0; i < 2; i++)
    {
        cout << z[i] << "\n";
    }

    return 0;
}