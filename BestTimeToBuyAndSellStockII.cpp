class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices.at(i) > prices.at(i-1)){  //Since we hold at most one share, maxProf would be the summation of all purchase and sell options opted, hence +=
                maxProf += prices[i] - prices[i-1];
            }
        }

        return maxProf;
    }
};