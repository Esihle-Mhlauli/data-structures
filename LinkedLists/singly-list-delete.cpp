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

void deleteMiddle(node* head, int data){
    node* curr = head->nextNode;
    node* prev = head;
    while(curr != NULL){
        if(curr->data == data){
            prev->nextNode = curr->nextNode;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->nextNode;
    }
    cout<<"data not found";
}

void printList(node* head){
    node* temp = head;

    while(temp != NULL)
    {   
        cout<<temp->data<<" ";
        temp = temp->nextNode;
    }
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

    int data = 6;
    deleteMiddle(head, data);

    printList(head);

    return 0;
}