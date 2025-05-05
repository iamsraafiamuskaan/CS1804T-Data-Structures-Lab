#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();              
    void enqueue(int value); 
    int dequeue();
    int peek();
};


int main() {
    Queue q;
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 4\n");
        }
    }

    return 0;
}

Queue::Queue() {
    front = NULL;
    rear = NULL;
}

void Queue::enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if (front == NULL && rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued successfully\n", value);
}

int Queue::dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }
    
    Node* temp = front;
    int value = temp->data;
    
    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }
    
    free(temp);
    printf("Dequeued %d from queue\n", value);
    return value;
}

int Queue::peek() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty! Nothing to peek\n");
        return -1;
    }
    printf("Front element is: %d\n", front->data);
    return front->data;
}