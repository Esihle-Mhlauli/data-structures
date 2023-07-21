/**********************************************
Author: Esihle Mhlauli

Populate Binary Search Tree
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
bool search(node* root, int data){
    if(root == NULL){
        cout<<"Tree is empty";
        return false;
    }
    
    if(root->data == data){
        return true;
    }

    if(root->data>=data){
        return search(root->left, data);
    }else if(root->data<=data){
        return search(root->right,data);
    }

    return false;
}

//print tree in order
void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<(root->data)<<"\n";
        inorder(root->right);
    }
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

    inorder(root);

    cout<<"\n"<<search(root,8);
    return 0;
}