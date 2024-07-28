#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

class Queuee {
    int arr[SIZE];
    int front;
    int rear;

public:
    // Default Constructor
    Queuee() : front(-1), rear(-1) {}

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
        } else {
            if (front == -1) {
                front = 0; 
            }
            arr[++rear] = val;
            cout << val << " added to the queue" << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
        } else {
            int x = arr[front++];
            cout << x << " removed from queue" << endl;
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
    }

    void queueFront() {
        if (isEmpty()) {
            cout << "Queue Empty" << endl;
        } else {
            cout << arr[front] << " is at the front of the queue" << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queuee q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.queueFront();   
    q.display();       
    q.dequeue();
    q.dequeue();
    q.queueFront();    
    q.display();     

    return 0;
}
