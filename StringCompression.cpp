#include <iostream>
#include <vector>

using namespace std;

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

int main(){
    Solution obj;

    vector<char> ip1;
    char c;
    for(int i = 0; i < 7; i++){
        cout<<"Enter ip "<<i+1<< " : ";
        cin>>c;
        ip1.push_back(c);
    }

    int res = obj.compress(ip1);

    cout<<"Function called";

    for(int i = 0; i < res; i++){
        cout<<"\t"<<ip1[i];
    }

    return 0;

}