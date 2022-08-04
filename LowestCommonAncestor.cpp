#include <iostream>

class Solution{
public:
    class Node{
        int val;
        Node *left;
        Node *right;
        Node(){}
        Node(int value){
            this->val = value;
        }
    };


    Node* lCA(Node *root, Node *p, Node *q){
        if(root == nullptr || root == p || root == q){
            return root;
        }

        Node *left = lCA(root->left, p, q);
        Node *right = lCA(root->right, p, q);

        if(left == nullptr)
            return right;
        else if(right == nullptr)
            return left;
        else
            return root;

        
    }

    int main(){

        

        return 0;
    }




};