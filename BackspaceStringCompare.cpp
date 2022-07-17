// class Solution {
// public:

#include <iostream>
// #include <char>
#include <stack>
#include <stdio.h>

using namespace std;
bool backspaceCompare(string s, string t);
int main(){
    cout<<backspaceCompare("ad#c","ad#c");
    return 0;
}
bool backspaceCompare(string s, string t) {
    stack<char> ans1;
    stack<char> ans2;

    for(char c : s){
        if(c != '#'){
            ans1.push(c);
        }
        else if( !ans1.empty()){
            ans1.pop();
        }
    }

    for(char d : t){
        if( d != '#'){
            ans2.push(d);
        }
        else if( !ans2.empty()){
            ans2.pop();
        }
    }

    return (ans1 == ans2);
}
// };