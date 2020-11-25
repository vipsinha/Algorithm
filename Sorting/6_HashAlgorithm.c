#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STRING_LEN 10
#define KEY_LEN 5

struct ITEM{
    char* key;
    char* value;
};

typedef struct ITEM items;

struct TABLE{
    items** itemsOnTable;
    int size;
    int count;
};

typedef struct TABLE table;

table* createTable(void);
items* createItem(char* key, char* value);
table* insertItem(table* node);
void printItem(table* node);
void searchItem(table* node);
int calculateHash(char* key, int size);

int main(){

    int choice =0;
    int size = 0;
    table* tableNode;

    do{
        printf("Enter 1 to exit\n");
        printf("Enter 2 to create a table\n");
        printf("Enter 3 to enter key and value\n");
        printf("Enter 4 to search key value pair\n");
        printf("Enter 5 to show table\n"); 
        printf("Enter choice\n");
        scanf("%d", &choice);

        if(choice == 2){
            tableNode = createTable();
        }  
        else if(choice == 3){
            tableNode = insertItem(tableNode);
        }   
        else if(choice ==4){
            searchItem(tableNode);
        }
        else if(choice ==5){
            printItem(tableNode);
        }
        else{
            choice = 1;
        }
         
    }while(choice != 1);

    return 0;
}
int calculateHash(char* key, int size){
    int hashValue;

    for(int i=0; i<strlen(key); i++)
        hashValue += key[i];
    return (hashValue % size);
}

table* createTable(void){
    table* node = (table*)malloc(sizeof(table));

    printf("Enter the node size\n");
    scanf("%d",&node->size);

    node->itemsOnTable = (items**)calloc(node->size, sizeof(items*));
    for(int i=0; i<node->size; i++){
        node->itemsOnTable[i] = NULL;
    }

    node->count = 0;
        
    return (node);
}

items* createItem(char* key, char* value){
    items* node = (items*)malloc(sizeof(items));
    
    node->key = (char*)malloc(strlen(key)+1);
    node->value = (char*)malloc(strlen(value)+1);

    strcpy(node->key, key);
    strcpy(node->value, value);
        
    return (node);
}

table* insertItem(table* node){
    char* key = (char*)malloc(KEY_LEN*sizeof(char));
    char* data = (char*)malloc(STRING_LEN*sizeof(char));
    int hash;

    if(node->count!= node->size){
        printf("Enter the key and value\n");
        scanf("%s", key);
        scanf("%s", data);

        hash = calculateHash(key, node->size);
        node->itemsOnTable[hash] = createItem(key, data);
        node->count++;
    }
    else{
        printf("Table is full\n");
    }
    return (node);    
}

void searchItem(table* node){
    char* key = (char*)malloc(KEY_LEN*sizeof(char));
    int hash;

    printf("Enter the key to search\n");
    scanf("%s", key);

    hash = calculateHash(key, node->size);

    if(strcmp(key, node->itemsOnTable[hash]->key) == 0){
        printf("Value = %s\n", node->itemsOnTable[hash]->value);
        printf("Hash = %d\n", hash);
    }
    else{
        printf("Key is not there\n");
    }
}

void printItem(table* node){
    for(int i=0; i<node->size; i++){
        if(node->itemsOnTable[i]!= NULL){
            printf("Index=%d, Key=%s, Values = %s\n",i, node->itemsOnTable[i]->key, node->itemsOnTable[i]->value);
        }        
    }
}
