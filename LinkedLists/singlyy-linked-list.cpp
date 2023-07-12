/**********************************************
Author: Inserting node at the beginnig, end and 
        middle of a list.
***********************************************/

#include <iostream>

using namespace std;

struct node
{
    int data = 0;
    node *nextNode = NULL;  //type Node because it is pointing to a Node.
};

void addMiddle(int pos,int newNodeData, node* head){

    node* temp = head;
    for(int i=0; i<pos; i++){    //traverse list until the desired insert position

        if(temp->nextNode == NULL){
            cout<<"position does not exist";
            return;
        }
        temp = temp->nextNode;
    }

    node* n = new node;   //create new node
    n->data = newNodeData;
    n->nextNode = temp->nextNode;  //connect the list
    temp->nextNode = n;
    
}
void addBegin(node* head,int newNodeData){

    node* n = new node;   //create new node
    n->data = newNodeData;
    if(head->nextNode != NULL){
        n->nextNode = head->nextNode;  //connect list
    }else{
        n->nextNode = NULL;
    }
    head = n;
}
void addEnd(node* head,int newNodeData){
    node* temp = head;

    while(temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }

    node* n = new node;   //create new node
    n->data = newNodeData;
    temp->nextNode = n;
    n->nextNode = NULL;

}
int main(){

    node* n = new node;  //This is a new node
    node* temp = n;  //This is the temporary node used for linking the nodes
    node* head = n; //This is the Head node
     n->data = 0;

    for(int i=1; i<5; i++)  
    {
        n = new node; 
        n->data = i;
        temp->nextNode = n;
        temp = n;
    }

    n->nextNode = NULL;

    //middle insert
    int pos = 3;
    int newNodeData = 33;
    addMiddle(pos, newNodeData, head);

    //begining insert
    newNodeData = 11;
    addBegin(head,newNodeData);

    //end insert
    newNodeData = 44;
    addEnd(head,newNodeData);
    
    return 0;
}

