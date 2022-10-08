#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        if (nums.size() == 0) return 0;
        
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                i--;

            }
        }

        for (auto n : nums)
        {
            cout << n << endl;
        }
        return nums.size();
    }
};

int main()
{
    vector<int> nums;
    
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);

    int val = 3;


    Solution solution;
    int result = solution.removeElement(nums, val);

    cout << "result: " << result << endl;
    return 0;
}