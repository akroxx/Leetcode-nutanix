/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> checker;

        ListNode* curr = head;

        while(curr != nullptr){
            checker.push_back(curr);
            curr = curr->next;
        }

        int l = 0, r = checker.size()-1;
        
        while(l <= r){
            if(checker[l]->val == checker[r]->val){
                l++;
                r--;
            }
            else{
                return false;
            }
        }

        return true;

    }
};