/* Pizza parlor accepting maximum M orders. Orders are served in first come first served
basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
using circular queue using array. */

#include <iostream>
#include <string>
using namespace std;

class PizzaParlor {
private:
    int front, rear, size;
    int* arr;
    int capacity;

public:
    // Constructor to initialize the pizza parlor with given capacity M
    PizzaParlor(int M) {
        capacity = M;
        arr = new int[capacity];  // Array to hold orders
        front = 0;
        rear = -1;
        size = 0;
    }

    ~PizzaParlor() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Sorry, the pizza parlor is full. Try again later." << endl;
        } else {
            rear = (rear + 1) % capacity;  // Circular increment
            arr[rear] = orderID;    // Add the new order to the queue
            size++;
            cout << "Order " << orderID << " placed successfully." << endl;
        }
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
        } else {
            int servedOrderID = arr[front];  // Get the front order
            front = (front + 1) % capacity;         // Circular increment
            size--;
            cout << "Order " << servedOrderID << " is being served." << endl;
        }
    }
 
    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders." << endl;
        } else {
            cout << "Pending orders: ";
            int i = front;
            for (int count = 0; count < size; count++) {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
    }
};

int main() {
    PizzaParlor pp(5);
    pp.placeOrder(1);
    pp.placeOrder(2);
    pp.placeOrder(3);
    pp.placeOrder(4);
    pp.placeOrder(5);
    pp.displayOrders();

    pp.serveOrder();
    pp.serveOrder();
    pp.displayOrders();

    pp.placeOrder(6);
    pp.displayOrders();
    return 0;
}

