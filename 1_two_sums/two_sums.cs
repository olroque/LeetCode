using System;
using System.Collections.Generic;

class Solution
{
  public int[] TwoSum(int[] nums, int target)
  {
    for (int i = 0; i < nums.Length; i++)
    {
      int x = 0;

      for (int j = 0; j <= x && x < nums.Length; j++)
      {
        if (j == i)
        {
          continue;
        }
        else
        {
          if (nums[j] + nums[i] == target)
          {
            return new int[] {j, i};
          }
        }
        x++;
      }
    }
    return Array.Empty < int > ();
  }

  static void Main(string[] args)
  {
    int[] nums = {3, 3};
    int target = 6;

    Solution s = new Solution();
    int[] checkWork = s.TwoSum(nums, target);
    foreach(int x in checkWork)
    {
      Console.WriteLine(x);
    }
  }
}