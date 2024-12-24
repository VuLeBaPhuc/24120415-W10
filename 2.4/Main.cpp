#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* head;   // Phần tử đầu hàng đợi
    Node* tail;   // Phần tử cuối hàng đợi
    int capacity;
    int size;     // Kích thước hàng đợi hiện tại
};

void init(Queue*& q) {
    q = new Queue;
    q->head = nullptr;
    q->tail = nullptr;
    q->size = 0;
    q->capacity = 0;  // Có thể thêm điều kiện cho capacity nếu cần
}

bool enqueue(Queue*& q, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (q->tail == nullptr) { // Nếu hàng đợi trống
        q->head = newNode;
        q->tail = newNode;
    }
    else {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->size++;
    return true;
}

bool dequeue(Queue*& q, int& value) {
    if (q->head == nullptr) {
        cout << "Queue is empty, cannot dequeue.\n";
        return false;
    }

    Node* temp = q->head;
    value = temp->data; // Lưu giá trị phần tử đầu tiên
    q->head = q->head->next;
    if (q->head == nullptr) {
        q->tail = nullptr;  // Nếu sau khi dequeue, hàng đợi trống
    }

    delete temp;  // Xóa nút đã bị loại bỏ
    q->size--;
    return true;
}

bool isEmpty(Queue* q) {
    return q->head == nullptr;
}

void empty(Queue*& q) {
    while (!isEmpty(q)) {
        int value;
        dequeue(q, value);
    }
    cout << "Queue is now empty.\n";
}

int size(Queue* q) {
    return q->size;
}

int main() {
    Queue* q;
    init(q); // Khởi tạo hàng đợi

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    cout << "Queue size: " << size(q) << endl;

    int value;
    if (dequeue(q, value)) {
        cout << "Dequeued value: " << value << endl;
    }

    cout << "Queue size after dequeue: " << size(q) << endl;

    empty(q);  // Xóa tất cả phần tử trong hàng đợi

    cout << "Queue size after empty: " << size(q) << endl;

    return 0;
}
