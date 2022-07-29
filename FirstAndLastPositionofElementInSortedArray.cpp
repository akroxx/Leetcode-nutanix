class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //For O(log n) complexity,
        // Simply run binary search for left and right sequentially returning left index && right index respectively

        int left = searchLeftIndex(nums, target);
        int right = searchRightIndex(nums, target);

        return left <= right ? vector<int> {left, right} : vector<int> {-1,-1};
        
    }

    int searchLeftIndex(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1, mid;

        while(left <= right){
            mid = right + left/2;
            if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }

        return left;
    }

     int searchRightIndex(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1, mid;

        while(left <= right){
            mid = right + left/2;
            if(nums[mid] <= target)
                left = mid+1;
            else
                right = mid-1;
        }

        return right;
    }
};