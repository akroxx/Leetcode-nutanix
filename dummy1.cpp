class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int totalCust = 0, satis;

        for(int i = 0; i < customers.size();i++){
            totalCust += customers[i];
            if(grumpy[i] == 0 )
                satis += customers[i];
        }

        if(minutes == customers.size())
            return totalCust;

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
            
            if(grumpy[end] == 1)
                unsatis += customers[end];
            
            //shifting window of size = minutes
            max_unsatis = max(max_unsatis, unsatis);
            start++;
            end++;
        }

        return max_unsatis+satis;


    }
};