/**********************************************
Author: Esihle Mhlauli

Taking advantage that an inorder BST traversal
is sorted, store the tree data to a vector and 
check if vector is sorted.
***********************************************/
#include <iostream>
#include <vector>

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

/*This is where a newly created node is inserted
in the tree (linked to parent)*/
node* insertNode(node* root, int data){
        if(root == NULL){
            root = newNode(data);
        }else if(root->data>=data){  //left insert condition
            root->left = insertNode(root->left,data);
        }else if(root->data<=data){  //right insert
            root->right = insertNode(root->right,data);
        }
return root;
}

vector<int> inorder(node* root){

    vector<int>treeData;

    if(root != NULL){    //populate vector using inorder traversal
        inorder(root->left);
        treeData.push_back(root->data);
        inorder(root->right);
    }

    return treeData;
}

bool validate(vector<int>treeData){

    if(treeData.size()==0){  //If the root is null, it is valid
        return true;
    }

    for(int i=1; i<treeData.size(); i++){    //Check if vector is sorted
        if(treeData.at(i)<=treeData.at(i-1)){
            return false;
        }
    }
    return true;
}

int main(){
    node* root = NULL; //this is the root pointer (not the container)
    root = insertNode(root,15);
    root = insertNode(root,10);
    root = insertNode(root,20);
    root = insertNode(root,8);
    root = insertNode(root,12);
    root = insertNode(root,17);
    root = insertNode(root,25);

    vector<int>treeData = inorder(root);
    cout<<validate;

    return 0;
}