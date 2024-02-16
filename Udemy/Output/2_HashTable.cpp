#include <iostream>
#include "1_LinkedList.hpp"

class HashTable : public LinkedList {

private:
    int CalculateHash(int key);
    Node **hashTable;
    int sizeOfHashtable{0};

public:
    HashTable() : sizeOfHashtable(0) {};
    HashTable(int size);
    ~HashTable(){};
    void Insert(int data);
    void Display();
};

int HashTable::CalculateHash(int key){
    return key % sizeOfHashtable;
}

HashTable::HashTable(int size){
    sizeOfHashtable = size;

    hashTable = new Node* [sizeOfHashtable];
    for(int i=0; i<sizeOfHashtable; i++){
        hashTable[i] = nullptr;
    }
}

void HashTable::Insert(int data){

    int hash = CalculateHash(data);
    Node* traverseNode = hashTable[hash];
    Node* traverseNodeCopy = hashTable[hash];

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if(hashTable[hash] == nullptr){
        hashTable[hash] = newNode;
    }else{
        while ((traverseNode != nullptr) && traverseNode->data < data){
            traverseNodeCopy = traverseNode;
            traverseNode = traverseNode->next;
        }

        if(traverseNode == hashTable[hash]){
            hashTable[hash] = newNode;
        }else{
            newNode->next = traverseNodeCopy->next;
            traverseNodeCopy->next = newNode;
        }
    }
}

void HashTable::Display(){

    for(int i=0; i<sizeOfHashtable; i++){
        int hash = CalculateHash(i);
        Node *traverse= hashTable[hash];
        
        while(traverse != nullptr){
            cout <<"Data = " << traverse->data << endl;
            traverse = traverse->next;
        }
    }

}

int main() {
	int A[] = {16, 25, 12, 39, 6, 122, 5, 68, 75, 5};
	int n = sizeof(A)/sizeof(A[0]);
	HashTable H(n);
	for (int i=0; i<n; i++){
		H.Insert(A[i]);
	}

    H.Display();

	return 0;
}