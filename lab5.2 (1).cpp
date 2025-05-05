#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    // Insert at the beginning
    void insertBeginning(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // Insert at the end
    void insertEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert at a specific position
    void insertPosition(int value, int pos) {
        if (!tail || pos == 0) {
            insertBeginning(value);
            return;
        }
        Node* temp = tail->next;
        for (int i = 0; temp != tail && i < pos - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }

    // Delete from the beginning
    void deleteBeginning() {
        if (!tail) return;
        Node* temp = tail->next;
        if (tail == tail->next) {
            tail = nullptr;
        } else {
            tail->next = temp->next;
        }
        delete temp;
    }

    // Delete from the end
    void deleteEnd() {
        if (!tail) return;
        Node* temp = tail->next;
        if (tail == tail->next) {
            delete tail;
            tail = nullptr;
            return;
        }
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    // Delete from a specific position
    void deletePosition(int pos) {
        if (!tail || pos == 0) {
            deleteBeginning();
            return;
        }
        Node* temp = tail->next;
        Node* prev = nullptr;
        for (int i = 0; temp != tail && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == tail) {
            deleteEnd();
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Search for an element
    bool search(int value) {
        if (!tail) return false;
        Node* temp = tail->next;
        do {
            if (temp->data == value) return true;
            temp = temp->next;
        } while (temp != tail->next);
        return false;
    }

    // Display the list
    void display() {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList list;
    int choice, value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n";
        cout << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                list.insertPosition(value, pos);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deletePosition(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                if (list.search(value))
                    cout << "Element found!\n";
                else
                    cout << "Element not found.\n";
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}