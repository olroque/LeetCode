using System;
using System.Collections.Generic;

class Solution
{
  public int RomanToInt(string s) 
  {
    Dictionary<string, int> romanNumeral = new Dictionary<string, int>() 
    {
      {"I", 1},
      {"IV", 4},
      {"V", 5},
      {"IX", 9},
      {"X", 10},
      {"XL", 40},
      {"L", 50},
      {"XC", 90},
      {"C", 100},
      {"CD", 400},
      {"D", 500},
      {"CM", 900},
      {"M", 1000}
    };

    // Create a string that will hold roman numberal characters 
    string x;

    // Create an int that will hold the sum
    int total = 0;

    // Loop through the string
    for (int i = 0; i < s.Length; i++)
    {
      if (i + 1 <= s.Length - 1 && romanNumeral.ContainsKey(s[i].ToString() + s[i + 1].ToString()))
      {
        x = s[i].ToString() + s[i + 1].ToString();
        total += romanNumeral[x];
        i++;
      }
      else if (romanNumeral.ContainsKey(s[i].ToString()))
      {
        x = s[i].ToString();
        total += romanNumeral[x];
      }
      else
      {
        continue;
      }
    }
    return total;      
  }

  static void Main(string[] args)
  {
    string s = "MCMXCIV";

    Solution solution = new Solution();
    Console.WriteLine(solution.RomanToInt(s));
  }
}