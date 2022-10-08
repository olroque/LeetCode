using System;
using System.Collections.Generic;

class Solution
{
  public bool IsPalindrome(int x)
  {

    // Convert int to string and get length of string
    string y = x.ToString();
    int ySize = y.Length;

    // Create empty string to hold palindrome comparison
    string myStr = "";

    // Reverse loop through y to create the palindrome string
    for (int i = ySize - 1; i >= 0; i--)
    {
      myStr += y[i];
    }

    // Compare y with palindrome string
    if (y == myStr)
    {
      return true;
    }
    else 
    {
      return false;
    }
  }

  static void Main(string[] args)
  {
    int x = 121;

    Solution s = new Solution();
    Console.WriteLine(s.IsPalindrome(x));
  }
}