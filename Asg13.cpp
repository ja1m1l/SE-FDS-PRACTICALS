/* A double-ended queue (deque) is a linear list in which additions and deletions may be

made at either end. Obtain a data representation mapping a deque into a one-
dimensional array. Write C++ program to simulate deque with functions to add and

delete elements from either end of the deque. */

#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;         
    int front;        
    int rear;         
    int size;         
    int count;       

public:
    
    Deque(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
        count = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return count == size;
    }

    bool isEmpty() {
        return count == 0;
    }

    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot add to front." << endl;
            return;
        }
        if (front == -1) {  // If deque is empty
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;  // Move front index backward
        }
        arr[front] = value;
        count++;
        cout << "Added " << value << " to the front." << endl;
    }

    void addRear(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot add to rear." << endl;
            return;
        }
        if (rear == -1) {  // If deque is empty
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;  // Move rear index forward
        }
        arr[rear] = value;
        count++;
        cout << "Added " << value << " to the rear." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from front." << endl;
            return;
        }
        cout << "Removed " << arr[front] << " from the front." << endl;
        front = (front + 1) % size;  // Move front index forward
        count--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from rear." << endl;
            return;
        }
        cout << "Removed " << arr[rear] << " from the rear." << endl;
        rear = (rear - 1 + size) % size;  // Move rear index backward
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    // Create a deque with a maximum size of 5
    Deque dq(5);
    dq.addRear(10);
    dq.addRear(20);
    dq.addFront(5);
    dq.addRear(30);
    dq.addFront(1);
    dq.display();

    dq.deleteFront();
    dq.deleteRear();
    dq.display();

    dq.addRear(40);
    dq.addFront(0);
    dq.display();

    dq.deleteFront();
    dq.deleteRear();
    dq.display();
    return 0;
}
