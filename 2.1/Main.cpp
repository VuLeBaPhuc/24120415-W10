#include <iostream>
#include <string.h>
using namespace std;

struct Stack {
	int* data; // dynamic array
	int top; // index of top element
	int capacity; // size of stack
};

void init(Stack*& s, int capacity) {
	s = new Stack;
	s->data = new int[capacity];
	s->capacity = capacity;
	s->top = -1;
}

void push(Stack*& s, int value) {
	if (s->top == s->capacity - 1)
	{
		cout << "Stack full. Cannot push.\n";
		return;
	}
	s->top++;
	s->data[s->top] = value;
}

int pop(Stack*& s) {
	if (s->top == -1)
	{
		cout << "Stack empty. Cannot pop.\n";
		return -1;
	}
	int value;
	value = s->data[s->top];
	s->data[s->top] = 0;
	s->top--;
	return value;
}

bool isEmpty(Stack*& s) {
	return s->top == -1;
}

void empty(Stack*& s) {
	s->top = -1;
}

int size(Stack* s) {
	return s->top + 1;
}
