#include <iostream>
using namespace std;

// Node structure for the stack
struct Node {
    int data;
    Node* next;
};

// Stack structure
struct Stack {
    Node* head;
    int capacity;
};

// Function to initialize the stack
void init(Stack*& s, int capacity) {
    s = new Stack;
    s->head = nullptr;  // The stack is initially empty
    s->capacity = capacity;
}

// Function to check if the stack is empty
bool isEmpty(Stack* s) {
    return s->head == nullptr;
}

// Function to push an integer onto the stack
bool push(Stack* s, int x) {
    // Check if the stack has reached its capacity
    int size = 0;
    Node* temp = s->head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    if (size >= s->capacity) {
        cout << "Stack is full! Cannot push " << x << endl;
        return false;
    }

    // Create a new node
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = s->head;
    s->head = newNode;
    return true;
}

// Function to pop the top element from the stack
bool pop(Stack* s, int& value) {
    if (isEmpty(s)) {
        cout << "Stack is empty! Cannot pop." << endl;
        return false;
    }

    // Remove the top node
    Node* temp = s->head;
    value = temp->data;
    s->head = s->head->next;
    delete temp;
    return true;
}

// Function to empty the stack
void empty(Stack* s) {
    while (!isEmpty(s)) {
        int value;
        pop(s, value);  // Pop all elements from the stack
    }
    cout << "Stack is now empty." << endl;
}

// Function to get the size of the stack
int size(Stack* s) {
    int count = 0;
    Node* temp = s->head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
