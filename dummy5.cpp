class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);

        res[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            res[i] = nums[i+1] * res[i+1];
        }

        int leftProd = 1;

        for(int i = 0; i < n; i++){
            res[i] = leftProd * res[i];
            leftProd = leftProd * nums[i];
        }
        
        return res;
    }
};