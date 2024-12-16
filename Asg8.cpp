/* Department of Computer Engineering has student's club named 'Pinnacle Club'. Students
of second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is reserved for president of
club and last node is reserved for secretary of club. Write C++ program to maintain club
member‘s information using singly linked list. Store student PRN and Name. Write
functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists. */

#include <iostream>
#include <string>
using namespace std;

struct Member {
    string prn;
    string name;
    Member* next;
    Member(string prn, string name) {
        this->prn = prn;
        this->name = name;
        this->next = NULL;
    }
};

class Club {
private:
    Member* head;
    Member* tail;
public:
    Club() {
        head = NULL;
        tail = NULL;
    }

    void addMember(string prn, string name) {
        Member* newMember = new Member(prn, name);
        if (head == NULL) {
            head = newMember;
            tail = newMember;
        } else {
            tail->next = newMember;
            tail = newMember;
        }
    }

    void deleteMember(string prn) {
        if (head == NULL) {
            cout << "No members in the club." << endl;
            return;
        }
        Member* temp = head;
        Member* prev = NULL;
        // If the member to delete is the president
        if (temp != NULL && temp->prn == prn) {
            head = temp->next; // Change the head
            delete temp;
            cout << "Member with PRN " << prn << " deleted successfully." << endl;
            return;
        }
        // Search for the member to delete
        while (temp != NULL && temp->prn != prn) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Member with PRN " << prn << " not found." << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
            return;
        }
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp;
        cout << "Member with PRN " << prn << " deleted successfully." << endl;
    }
    int totalMembers() {
        int count = 0;
        Member* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count - 2; // Exclude president and secretary from count
    }

    void displayMembers() {
        if (head == NULL) {
            cout << "No members in the club." << endl;
            return;
        }
        Member* temp = head;
        cout << "Members of Pinnacle Club:" << endl;
        while (temp != NULL) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }
    void concatenate(Club& otherClub) {
        if (this->tail != NULL && otherClub.head != NULL) {
            this->tail->next = otherClub.head;
            this->tail = otherClub.tail;
            otherClub.head = NULL;
            otherClub.tail = NULL;
        }
    }
    ~Club() {
        while (head != NULL) {
            Member* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    Club division1, division2;
    division1.addMember("PRN001", "Alice");
    division1.addMember("PRN002", "Bob");
    division2.addMember("PRN003", "Charlie");
    division2.addMember("PRN004", "David");
    cout << "Division 1:" << endl;
    division1.displayMembers();
    cout << "\nDivision 2:" << endl;
    division2.displayMembers();
    division1.concatenate(division2);
    cout << "\nAfter concatenation of Division 2 to Division 1:" << endl;
    division1.displayMembers();
    cout << "\nTotal number of members: " << division1.totalMembers() << endl;
    cout << "\nDeleting member with PRN 'PRN002'..." << endl;
    division1.deleteMember("PRN002");
    division1.displayMembers();
    return 0;
}