/* Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue. */

#include <iostream>
#include <string>
using namespace std;

class jobQueue {
private:
    int front, rear, size;
    int* arr;
    int capacity;

public:
    // Constructor to initialize the pizza parlor with given capacity M
    jobQueue(int M) {
        capacity = M;
        arr = new int[capacity];  // Array to hold orders
        front = 0;
        rear = -1;
        size = 0;
    }

    ~jobQueue() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void addJob(int jobID) {
        if (isFull()) {
            cout << "Sorry, the Job is full. Try again later." << endl;
        } else {
            rear = (rear + 1) % capacity;  // Circular increment
            arr[rear] = jobID;    // Add the new order to the queue
            size++;
            cout << "Job " << jobID << " added to the queue." << endl;
        }
    }

    void deleteJobs() {
        if (isEmpty()) {
            cout << "No Jobs to delete." << endl;
        } else {
            int deleteJob = arr[front];  // Get the front order
            front = (front + 1) % capacity;         // Circular increment
            size--;
            cout << "Job " << deleteJob << " is being deleted from the queue." << endl;
        }
    }
 
    void displayJobs() {
        if (isEmpty()) {
            cout << "No pending jobs." << endl;
        } else {
            cout << "Pending jobs:  "<<endl;
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
    jobQueue JQ(5);

    // Adding jobs to the queue
    JQ.addJob(1);
    JQ.addJob(2);
    JQ.addJob(3);
    JQ.addJob(4);
    JQ.addJob(5);
    JQ.deleteJobs();
    JQ.displayJobs();
    JQ.deleteJobs();  // Process Job 1
    JQ.displayJobs();  // Display remaining jobs
   
    return 0;
}
