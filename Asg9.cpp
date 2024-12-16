/* Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
B of students like butterscotch ice-cream. Write C++ program to store two sets using
linked list. compute and display-
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch */


#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node(string name) : name(name), next(NULL) {}
};

class StudentSet {
private:
    Node* head;

    bool contains(const string& name) const {
        Node* temp = head;
        while (temp) {
            if (temp->name == name) return true;
            temp = temp->next;
        }
        return false;
    }

public:
    StudentSet() : head(nullptr) {}

    void addStudent(const string& name) {
        if (!contains(name)) {
            Node* newNode = new Node(name);
            newNode->next = head;
            head = newNode;
        }
    }

    void displaySet() const {
        if (!head) {
            cout << "The set is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    StudentSet intersection(const StudentSet& otherSet) const {
        StudentSet result;
        Node* temp = head;
        while (temp) {
            if (otherSet.contains(temp->name)) {
                result.addStudent(temp->name);
            }
            temp = temp->next;
        }
        return result;
    }

    StudentSet symmetricDifference(const StudentSet& otherSet) const {
        StudentSet result;
        Node* temp = head;

        while (temp) {
            if (!otherSet.contains(temp->name)) {
                result.addStudent(temp->name);
            }
            temp = temp->next;
        }

        temp = otherSet.head;
        while (temp) {
            if (!contains(temp->name)) {
                result.addStudent(temp->name);
            }
            temp = temp->next;
        }

        return result;
    }

    int countNeither(const StudentSet& setA, const StudentSet& setB, const StudentSet& allStudents) const {
        int count = 0;
        Node* temp = allStudents.head;

        while (temp) {
            if (!setA.contains(temp->name) && !setB.contains(temp->name)) {
                count++;
            }
            temp = temp->next;
        }

        return count;
    }
};

int main() {
    StudentSet vanillaSet, butterscotchSet;

    vanillaSet.addStudent("Alice");
    vanillaSet.addStudent("Bob");
    vanillaSet.addStudent("Charlie");

    butterscotchSet.addStudent("Bob");
    butterscotchSet.addStudent("David");
    butterscotchSet.addStudent("Eve");

    cout << "Students who like Vanilla Ice-cream:" << endl;
    vanillaSet.displaySet();

    cout << "Students who like Butterscotch Ice-cream:" << endl;
    butterscotchSet.displaySet();

    StudentSet intersectionSet = vanillaSet.intersection(butterscotchSet);
    cout << "Students who like both Vanilla and Butterscotch:" << endl;
    intersectionSet.displaySet();

    StudentSet symDiffSet = vanillaSet.symmetricDifference(butterscotchSet);
    cout << "Students who like either Vanilla or Butterscotch but not both:" << endl;
    symDiffSet.displaySet();

    StudentSet allStudents;
    allStudents.addStudent("Alice");
    allStudents.addStudent("Bob");
    allStudents.addStudent("Charlie");
    allStudents.addStudent("David");
    allStudents.addStudent("Eve");
    allStudents.addStudent("Frank");

    int count = allStudents.countNeither(vanillaSet, butterscotchSet, allStudents);
    cout << "Number of students who like neither Vanilla nor Butterscotch: " << count << endl;

    return 0;
}