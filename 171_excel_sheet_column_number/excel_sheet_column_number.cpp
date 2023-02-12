#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int num = 0;
    int columnLength;
    int columnTitleSize;

    int titleToNumber(string columnTitle) 
    {
        columnTitleSize = columnTitle.size() - 1;
        columnLength = columnTitle.size() - 1;

        int i = 0;
        while (i < columnTitle.size())
        {
            num += columnValue(columnTitle[i], i);
            i++;
        }
        return num;
    }

    int columnValue(char columnChar, int columnIndex)
    {
        int j = 0;
        while (j < alphabet.size())
        {
            if (columnChar == alphabet[j])
            {
                if (columnIndex < columnTitleSize)
                {
                    columnLength--;
                    return (pow(26, columnLength+1)) * (j + 1);
                }
                else
                {
                    return j + 1;
                }
            }
            j++;
        }
        return 0;
    }
};

int main() 
{
    return 0;
}