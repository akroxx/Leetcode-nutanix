class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // target - distance to be covered
        // position[i] is position of the i-th car
        // speed[i] is speed of i-th car in mph
        map<int, double> time;  //ORDERED_MAP stores : car start position and time taken to reach target line
        for(int i = 0; i < position.size(); i++){
            time[position[i]] = (double)(target - position[i]) / speed[i];
        }
        
        int res = 0;
        double slowest = 0;
        for(auto itr = time.rbegin(); itr != time.rend(); itr++){   //Iterating from end to beginning i.e. rbegin to rend because the car at the max initial starting position is likely to take lesser time
            if(itr->second > slowest){
                slowest = itr->second;
                res++;
            }
        }
        return res;
    }
};