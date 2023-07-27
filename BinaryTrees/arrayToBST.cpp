/**********************************************
Author: Esihle Mhlauli

Convert a Sorted Array to a BST using 
inorder traversal.
***********************************************/
#include <iostream>
#include <vector>
#include <math.h>

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

node* convertHelper(vector<int>sorterdVec, int start, int end){

    if(sorterdVec.size() == 0){
        return NULL;
    }
    if(start>end){
        return NULL;
    }
    if(start==end){
        return newNode(sorterdVec.at(start));
    }

    int mid = (start + end)/2;   //identify middle element;
    node* root = newNode(sorterdVec.at(mid));  //create new node and insert middle element

    root->left = convertHelper(sorterdVec, start, mid-1);
    root->right = convertHelper(sorterdVec, mid+1, end);

    return root;
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<(root->data)<<"\n";
        inorder(root->right);
    }
}

int main(){
    node* root = NULL; //this is the root pointer (not the container)

    vector<int>sorted = {8,10,12,15,17,20,25};

    root = convertHelper(sorted, 0, sorted.size()-1);
    inorder(root);

    return 0;
}