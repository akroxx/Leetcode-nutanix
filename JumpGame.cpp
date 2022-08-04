// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         int last = n-1, i, j;

//         for(i = n-2; i>= 0; i--){
//             if(i+nums[i] >= last)
//                 last = i;
//         }
        
//         return last <= 0;
//     }
// };
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool canJump(vector<int>& nums){
        int n = nums.size(), farest = 0;

        for(int i = 0; i < n; i++){
            if(farest < i) return false;
            farest = max(farest, i + nums[i]);
        }

        return true;
    }

};

int main(){
    Solution sol;
    
    vector<int> nums;
    vector<int> nums2;

    int x;

    for(int i= 0; i < 5; i++){
        cout<<"Enter vector 1 values : ";
        cin>>x;
        nums.push_back(x);
    }
    cout<< "Vector 1" <<sol.canJump(nums)<<endl;
    
    for(int i= 0; i < 5; i++){
        cout<<"Enter vector 2 values : ";
        cin>>x;
        nums2.push_back(x);
    }

    cout<<"Vector 2" <<sol.canJump(nums2);

    return 0;
}

