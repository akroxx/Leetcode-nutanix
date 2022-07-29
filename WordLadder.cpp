class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList[wordList.size()-1] != endWord)
            return 0;
        
        return 1;
    }
};