#include "1_LinkedList.hpp"

LinkedList::LinkedList(int* A, int num){

    Node *newNode, *lastNode;

    first = new Node;
    first->data=A[0];
    first->next=nullptr;

    lastNode=first;

    for(int x=1; x<num; x++){
        newNode=new Node;
        newNode->data=A[x];
        newNode->next=nullptr;

        lastNode->next=newNode;
        lastNode=newNode;
    }
}

void LinkedList::Insert(int index, int data)
{
    Node *newNode = new Node;
    Node *traverse = first;

    newNode->data = data;
    newNode->next = nullptr;

    if(index<0 || index > Length()){
        cout << "Invalid index" << endl;
        return;
    }
    else if(index == 0){
        newNode->next = first;
        first=newNode;
    }
    else{
        for(int i=1; i<index-1;i++){
            traverse = traverse->next;
        }
        newNode->next=traverse->next;
        traverse->next=newNode; 
    }
}

void LinkedList::Display(){
    Node *traverse=first;
    while(traverse != nullptr){
        cout <<"Data = " << traverse->data << endl;
        traverse = traverse->next;
    }
}

int LinkedList::Length(){
    int length = 1;
    Node* traverse = first;

    while(traverse->next != nullptr){
        traverse=traverse->next;
        length++;
    }

    return length;
}

int main(){ 
    
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);
    
    l.Insert(3,10);
    l.Display();
    
    return 0;  
}
