#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList : public Node{ 

public:
    LinkedList(){
        first = nullptr;
    };
    LinkedList(int* A, int num);
    ~LinkedList(){};
    void Insert(int index, int data);
    void Display();

private:
    int Length();
    Node* first=nullptr;
};