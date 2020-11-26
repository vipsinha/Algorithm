/*
Date: 2020-11-26
https://www.learn-c.org/en/Linked_lists
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct NODE{
    int data;
    struct NODE* next;
};

typedef struct NODE node;

void insertNodeAtEnd(node* head);
void insertNodeAtStart(node** head);
void removeNodeAtEnd(node* head);
void removeNodeAtStart(node** head);
void removeNodeByValue(node** head);
void printNode(node* head);

int main(void){

    int choice =0;
    node* headNode = (node*)malloc(sizeof(node));
    headNode->next = NULL;
    headNode->data = 0;

    do{
        printf("Enter 0 to exit\n");
        printf("Enter 1 to insert node at end\n");
        printf("Enter 2 to insert node at start\n");
        printf("Enter 3 to remove node at end\n");
        printf("Enter 4 to remove node at start\n");
        printf("Enter 5 to remove node at value\n");
        printf("Enter 6 to print nodes\n"); 
        printf("Enter choice\n");
        scanf("%d", &choice);

        if(choice == 1){
            insertNodeAtEnd(headNode);
        }  
        else if(choice == 2){
            insertNodeAtStart(&headNode);
        }   
        else if(choice == 3){
            removeNodeAtEnd(headNode);
        }
        else if(choice == 4){
            removeNodeAtStart(&headNode);
        }
        else if(choice == 5){
            removeNodeByValue(&headNode);
        }
        else if(choice == 6){
            printNode(headNode);
        }
        else{
            choice = 0;
            free(headNode);
        }
         
    }while(choice != 0);

    return 0;
}

void insertNodeAtEnd(node* head){

    node* temp = head;
    node* newNode = (node*)malloc(sizeof(node));

    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
     
    while (temp->next!=NULL){
        temp = temp->next;    
    }

    temp->next = newNode;
}

void insertNodeAtStart(node** head){
    node* newNode = (node*)malloc(sizeof(node));

    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    newNode->next = *head;
    *head = newNode;
}

void removeNodeAtEnd(node* head){
    node* temp = head;

    while (temp->next->next!=NULL){
        temp = temp->next;
    }
    
    printf("Value at last node = %d\n", temp->next->data);
    temp->next = NULL;
    free(temp->next);
}

void removeNodeAtStart(node** head){
    node* temp = (*head)->next;
    
    printf("Value at start node = %d\n", (*head)->data);
    free(*head);
    *head = temp;  
}

void removeNodeByValue(node** head){
    int data;
    node* temp = (*head);

    printf("Enter the data to be removed\n");
    scanf("%d", &data);

    if((*head)->data == data){
        printf("Data removed at node head\n");
        free((*head));
        *head = temp->next;
    }else{
        while(temp->next->next != NULL){
            if(temp->next->data == data){
                temp->next = temp->next->next;
                free(temp->next);
                break;
            }
            temp = temp->next;
        }
    }
}

void printNode(node* head){
    node* temp = head;

    while (temp!=NULL){
        printf("Value = %d\n", temp->data);
        temp = temp->next;
    }
}
