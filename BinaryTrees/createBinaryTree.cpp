/**********************************************
Author: Esihle Mhlauli

Initializing a binary tree
***********************************************/
#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//new node creation (return the node)

node* newNode(int data){
    node* newNode_ = new node;

    newNode_->data = data;
    newNode_->left = NULL;
    newNode_->right = NULL;
    return newNode_;
}

int main(){

    return 0;
}