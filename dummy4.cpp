class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastSeen[26];

        for(int i = 0; i < s.length(); i++){
            lastSeen[s[i] - 'a'] = i;
        }

        int prvIdx = 0, count = 0;
        vector<int> res;

        for(int i = 0; i < s.length(); i++){
            prvIdx = max(prvIdx, lastSeen[s[i] - 'a']);
            count++;

            if(i == prvIdx){
                res.push_back(count);
                count = 0;
            }
        }

        return res;
    }
};