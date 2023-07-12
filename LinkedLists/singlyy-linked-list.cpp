/**********************************************
Author: Esihle Mhlauli
Summary: A simple recap on singly linked lists
         using c++.
***********************************************/

#include <iostream>

using namespace std;

struct node
{
    int data = 0;
    node *nextNode;  //type Node because it is pointing to a Node.
};

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
    
    return 0;
}