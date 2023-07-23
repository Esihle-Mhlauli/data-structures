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

//Delete node function
node* delete_(node* root, int data){
    if(root==NULL){
        return root;
    }else if(root->data>data){  //proceed left
        root->left = delete_(root->left,data);
        return root;
    }else if(root->data<data){
        root->right = delete_(root->right,data);
        return root;
    }else{  //this is where deletion happens

        //node with no child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root=NULL;
            return root;
        }
        else if(root->left == NULL){ //node has right child
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){ //node has right child
            node* temp = root->left;
            delete root;
            return temp;
        }
    }

}


//print tree in order (traversal)
void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<(root->data)<<"\n";
        inorder(root->right);
    }
}

/* PreOrder traversal
void preorder(node* root){
    if(root != NULL){
        cout<<(root->data)<<"\n";
        preorder(root->left);
        preorder(root->right);
    }
}

*/

/* PostOrder traversal
void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<(root->data)<<"\n";.
    }
}

*/

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
    root = delete_(root, 12);
    cout<<endl;
    inorder(root);
    root = delete_(root, 10);
    cout<<endl;
    inorder(root);
    
    return 0;
}