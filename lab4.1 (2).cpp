#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int value, int pos);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);
    bool search(int value);
    void display();
    void displayReverse(Node* node);
    void displayReverseWrapper();
    void reverseLink();
    ~SinglyLinkedList();
};

void SinglyLinkedList::insertBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void SinglyLinkedList::insertEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void SinglyLinkedList::insertPosition(int value, int pos) {
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) {
        insertBeginning(value);
        return;
    }
    Node* newNode = new Node{value, nullptr};
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; ++i) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Position out of range!" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void SinglyLinkedList::deleteBeginning() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void SinglyLinkedList::deleteEnd() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void SinglyLinkedList::deletePosition(int pos) {
    if (!head || pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp->next && i < pos - 1; ++i) {
        temp = temp->next;
    }
    if (!temp->next) {
        cout << "Position out of range!" << endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

bool SinglyLinkedList::search(int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

void SinglyLinkedList::display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void SinglyLinkedList::displayReverse(Node* node) {
    if (!node) return;
    displayReverse(node->next);
    cout << node->data;
    if (node != head) cout << " -> ";
}

void SinglyLinkedList::displayReverseWrapper() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    displayReverse(head);
    cout << " -> NULL" << endl;
}

void SinglyLinkedList::reverseLink() {
    if (!head) {
        cout << "List is empty! Cannot reverse." << endl;
        return;
    }
    Node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    cout << "Linked list reversed successfully." << endl;
}

SinglyLinkedList::~SinglyLinkedList() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Memory freed. List destroyed." << endl;
}

int main() {
    SinglyLinkedList list;
    int choice, value, position;
    while (true) {
        cout << "\n1. Insert Beginning\n 2. Insert End\n 3. Insert Position\n 4. Delete Beginning\n 5. Delete End\n 6. Delete Position\n 7. Search\n 8. Display\n 9. Display Reverse\n 10. Reverse Link\n 11. Exit\n Enter choice: ";
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
                cin >> value >> position;
                list.insertPosition(value, position);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                list.deletePosition(position);
                break;
            case 7:
                cout << "Enter value: ";
                cin >> value;
                cout << (list.search(value) ? "Found" : "Not Found") << endl;
                break;
            case 8:
                list.display();
                break;
            case 9:
                list.displayReverseWrapper();
                break;
            case 10:
                list.reverseLink();
                break;
            case 11:
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}