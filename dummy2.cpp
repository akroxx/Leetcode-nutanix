class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length()-1, j = t.length() -1;
        int skipS = 0, skipT= 0;

        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    skipS++;
                    i--;
                }
                else if(skipS > 0){
                    skipS--;
                    i--;
                }
                else{
                    break;
                }
            }

            while(j >= 0){
                if(t[j] == '#'){
                    skipT++;
                    j--;
                }
                else if(skipT > 0){
                    skipT--;
                    j--;
                }
                else{
                    break;
                }
            }

            if(i >=0 && j >= 0 && s[i] != t[i]){
                return false;
            }

            if( (i >= 0) != (j >= 0)){  //if either has been completely traversed
                return false;
            }
            i--;
            j--;
        }

        return true;
    }
};