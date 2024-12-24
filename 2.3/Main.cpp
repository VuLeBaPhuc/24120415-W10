#include <iostream>
using namespace std;

struct Queue {
    int* data;  // Dynamic array to hold queue elements
    int in;     // Index where the next element will be enqueued
    int out;    // Index where the next element will be dequeued
    int capacity;  // Maximum number of elements the queue can hold
    int size;  // Current number of elements in the queue
};

// Function to initialize the queue
void init(Queue*& q, int capacity) {
    q = new Queue;
    q->data = new int[capacity];  // Create dynamic array for queue
    q->capacity = capacity;
    q->in = 0;
    q->out = 0;
    q->size = 0;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to enqueue an element into the queue
bool enqueue(Queue* q, int x) {
    if (q->size == q->capacity) {
        cout << "Queue is full. Cannot enqueue.\n";
        return false;
    }
    q->data[q->in] = x;  // Add element to the 'in' position
    q->in = (q->in + 1) % q->capacity;  // Move 'in' pointer forward, wrap around if necessary
    q->size++;  // Increase the size of the queue
    return true;
}

// Function to dequeue an element from the queue
bool dequeue(Queue* q, int& value) {
    if (isEmpty(q)) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return false;
    }
    value = q->data[q->out];  // Get the element at the 'out' position
    q->out = (q->out + 1) % q->capacity;  // Move 'out' pointer forward, wrap around if necessary
    q->size--;  // Decrease the size of the queue
    return true;
}

// Function to make the queue empty
void empty(Queue* q) {
    q->in = 0;
    q->out = 0;
    q->size = 0;
    cout << "Queue is now empty.\n";
}

// Function to get the size of the queue
int size(Queue* q) {
    return q->size;
}

// Function to delete the queue
void deleteQueue(Queue* q) {
    delete[] q->data;  // Delete the dynamic array
    delete q;  // Delete the queue object itself
}
