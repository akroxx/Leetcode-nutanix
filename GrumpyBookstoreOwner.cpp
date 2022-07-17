class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // customer[i] = number of customers entering at i-th minute
        // grumpy[i] == 1 ? grumpy : not grumpy
        // minutes -> not grumpy for minutes int val, but only once a day

        int satisfied = 0, totalCust = 0;

        for(int i = 0; i < customers.size(); i++){
            totalCust += customers[i];
            if(grumpy[i] == 0)
                satisfied += customers[i];
        }

        if(minutes == customers.size())
            return totalCust;

        // calc window size
        int start = 0, end = 0, unsatis = 0;
        int max_unsatis = INT_MIN;

        while(end < minutes){
            if(grumpy[end] == 1)
                unsatis += customers[end];
            end++;
        }

        max_unsatis = max(max_unsatis, unsatis);

        while(end < customers.size()){
            if(grumpy[start] == 1)
                unsatis -= customers[start];
            
            start++;

            if(grumpy[end] == 1)
                unsatis += customers[end];

            max_unsatis = max(max_unsatis, unsatis);
            end++;
        }

        return max_unsatis+satisfied;




    }
};