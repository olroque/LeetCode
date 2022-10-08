#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> arr;

    vector<vector<int>> generate(int numRows) 
    {
        int i = 0;
        while (i < numRows)
        {
            generateVector(i);
            i++;
        }

        return arr;
    }

    void generateVector(int cur_row)
    {
        vector<int> temp;

        if (cur_row == 0)
        {
            temp.push_back(1);
            arr.push_back(temp);
        }
        else if (cur_row == 1)
        {
            temp.push_back(1);
            temp.push_back(1);
            arr.push_back(temp);
        }
        else
        {
            temp.push_back(1);

            int i = 1;
            while (i < arr[cur_row - 1].size())
            {
                int cur_index = arr[cur_row - 1][i];
                int prev_index = arr[cur_row - 1][i - 1];
                int new_entry = prev_index + cur_index;
                
                temp.push_back(new_entry);
                i++;
            }
            temp.push_back(1);
            arr.push_back(temp);
        }
    }
};

int main()
{
    int numRows = 5;

    Solution solution;
    vector<vector<int > > result = solution.generate(numRows);

    cout << result.size() << endl;

    // solution.generate(numRows);

    return 0;
}