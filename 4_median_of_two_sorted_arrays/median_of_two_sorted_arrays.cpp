#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        bool isEven;
        if ((nums1.size() + nums2.size()) % 2 == 0) isEven = true;
        else isEven = false;

        double evenMedian = 0;
        double median = 0;
        int median_index = (nums1.size() + nums2.size()) / 2;

        int nums1_index = 0;
        int nums2_index = 0;
        int i = 0;
        while (i <= median_index)
        {
            if (nums1_index < nums1.size())
            {
                if (nums2_index < nums2.size() && nums1[nums1_index] < nums2[nums2_index])
                {
                    if (isEven && i == median_index - 1) evenMedian = (double)nums1[nums1_index];
                    if (i == median_index) {median = (double)nums1[nums1_index]; break;}
                    nums1_index++;
                }
                else if (nums2_index < nums2.size())
                {
                    if (isEven && i == median_index - 1) evenMedian = (double)nums2[nums2_index];
                    if (i == median_index) {median = (double)nums2[nums2_index]; break;}
                    nums2_index++;
                }
                else
                {
                    if (isEven && i == median_index - 1) evenMedian = (double)nums1[nums1_index];
                    if (i == median_index) median = (double)nums1[nums1_index];
                    nums1_index++;
                }
            }
            else if (nums2_index < nums2.size())
            {
                if (isEven && i == median_index - 1) evenMedian = (double)nums2[nums2_index];
                if (i == median_index) {median = (double)nums2[nums2_index]; break;}
                nums2_index++;
            }
            i++;
        }
        if (isEven) return (evenMedian + median) / 2;
        else return median;
    }
};

int main()
{
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(1);

    nums2.push_back(1);
    nums2.push_back(1);
    
    Solution solution;
    double result = solution.findMedianSortedArrays(nums1, nums2);

    cout << result << endl;
    
    return 0;
}