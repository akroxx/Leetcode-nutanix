class Solution {
public:
    int compress(vector<char>& chars) {        
        int reader = 0, writer = 0;

        if(chars.size() < 2)
            return chars.size();

        while(reader < chars.size()){
            int count = 0;
            chars[writer] = chars[reader];
            while(reader < chars.size() && chars[reader] == chars[writer]){
                reader++;
                count++;
            }

            if(count == 1){
                writer++;
            }
            else{
                string str = to_string(count);
                for(auto ch : str)
                    chars[++writer] = ch;
                writer++;
            }

        }

        return writer;
    }
};