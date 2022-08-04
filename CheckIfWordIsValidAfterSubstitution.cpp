class Solution{
public:
    bool isValid(string s) {
        vector<char> stack;

        for(char c : s){
            if(c == 'c'){
                int n = stack.size();
                if(n < 2 || stack[n-1] != 'b' || stack[n-2] != 'a'){
                    return false;
                }
                stack.pop_back();
                stack.pop_back();
            }
            else{
                stack.push_back(c);
            }
        }

        return stack.size() == 0;
    }
};