#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        if (n < 1) {return;}
        if (m < 1 && n > 0)
        {
            int y = 0;
            while (y < nums2.size())
            {
                nums1[y] = nums2[y];
                y++;
            }
            return;
        }

        int y = 0;
        while (y < n)
        {
            nums1.pop_back();
            y++;
        }

        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] > nums2[j])
            {
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
            }
            if (i == nums1.size() - 1)
            {
                while (j < nums2.size())
                {
                    nums1.push_back(nums2[j]);
                    j++;
                }
                break;
            }
            i++;
        }
    }
};

int main()
{
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(0); 
    nums1.push_back(0); 
    nums1.push_back(0); 
    nums1.push_back(0); 
    nums1.push_back(0); 

    nums2.push_back(1); 
    nums2.push_back(2); 
    nums2.push_back(3); 
    nums2.push_back(4); 
    nums2.push_back(5); 


    int m = 0;
    int n = 5;

    Solution solution;
    solution.merge(nums1, m, nums2, n);
    return 0;
}