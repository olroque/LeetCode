#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
        
        int x = 1;
        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            for (int j = x; j < nums.size(); j++)
            {
                if (*i == nums[j])
                {
                    nums.erase(nums.begin() + j);
                    j--;
                }
            }
            x++;
        }
        return nums.size();
    }
};

int main()
{
    vector<int> nums;
    
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    Solution solution;
    int result = solution.removeDuplicates(nums);

    cout << "result: " << result << endl;

    return 0;
}