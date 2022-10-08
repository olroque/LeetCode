#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int max_profit = 0;

        int buy_price = prices[0];
        int sell_price = 0;

        int i = 0;
        while (i < prices.size())
        {
            if (prices[i] < buy_price)
            {
                buy_price = prices[i];
                sell_price = prices[i];
            }
            if (prices[i] > sell_price)
            {
                sell_price = prices[i];
                if (sell_price - buy_price > max_profit) max_profit = sell_price - buy_price;
            }
            i++;
        }

        if (max_profit < 0) return 0;
        return max_profit;
    }
};

int main()
{
    vector<int> prices;

    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    Solution solution;
    int result = solution.maxProfit(prices);

    cout << result << endl;

    return 0;
}