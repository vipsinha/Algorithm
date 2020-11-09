#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STRING_LEN 10

struct ITEM{
    int key;
    char* value;
};

typedef struct ITEM items;

items* createATable(int size);
items* insertData(items* node);
void printData(items* node, int size);
void searchData(items* node, int size);
int hashTable(int key);

int main(){

    int choice =0;
    int size = 0;
    items* node;

    do{
        printf("Enter 1 to exit\n");
        printf("Enter 2 to create a value in hash\n");
        printf("Enter 3 to Enter the key and value\n");
        printf("Enter 4 to search key value pair\n");
        printf("Enter 5 to show values in hash\n"); 
        printf("Enter choice\n");
        scanf("%d", &choice);

        if(choice == 2){

            printf("Enter the node size\n");
            scanf("%d",&size);
            node = createATable(size);
        }  
        else if(choice == 3){
            node = insertData(node);
        }   
        else if(choice ==4){
            searchData(node, size);
        }
        else if(choice ==5){
            printData(node, size);
        }
        else{
            choice = 1;
        }
         
    }while(choice != 1);

    return 0;
}
int hashTable(int key){
    int hashValue;

    hashValue = (key % 0xA);
    return (hashValue);
}

items* createATable(int size){
    items* node;

    node = (items*)malloc(size*sizeof(items));
    for(int i=0; i<size; i++){
        node[i].key = 0;
        node[i].value = (char*)calloc(STRING_LEN, sizeof(char));
    }
        
    return (node);
}

items* insertData(items* node){
    int key;
    char* data=(char*)malloc(STRING_LEN*sizeof(char));
    char temp[20];
    int hash;

    printf("Enter the key and value of length 10\n");
    scanf("%d",&key);
    fgets(data, STRING_LEN, stdin);
    hash = hashTable(key);
    node[hash].key = hash;
    strcpy(node[hash].value, data);

    return (node);    
}

void searchData(items* node, int size){
    int key, hash;

    printf("Enter the key to search\n");
    scanf("%d", &key);

    hash = hashTable(key);

    if(hash == node[hash].key){
        printf("Value = %s\n", node[hash].value);
    }
    else{
        printf("Key is not there\n");
    }

}

void printData(items* node, int size){
    for(int i=0; i<size; i++){
        if(node[i].key!=0){
            printf("\n%d - %s ",node[i].key, node[i].value);
        }
    }
}