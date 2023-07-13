/**********************************************
Author: Deleting node at the beginnig, end and 
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

    if(head == NULL){
        cout<<"list is empty";
        return;
    }

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

void deleteEnd(node* head){
    node* curr = head->nextNode;
    node* prev = head;

    if(head == NULL){
        cout<<"list is empty";
        return;
    }

    while(curr->nextNode != NULL){
        prev = curr;
        curr = curr->nextNode;
    }

    prev->nextNode = NULL;
    delete curr;
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

    int data = 3;
    deleteMiddle(head, data);
    deleteEnd(head);

    printList(head);

    return 0;
}