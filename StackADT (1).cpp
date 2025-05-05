#include <stdio.h>
#include <iostream>
#define SIZE 5

class Stack {
private:
    char arr[SIZE];
    int top;

public:
    Stack() {
        top = -1; 
    }
    void push(char element);
    char pop();
    char peek();
    void print();
};

int main() {
    int choice;
    char element, result;
    Stack s;

    do {
        printf("\nMenu\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be inserted at the top: ");
            scanf(" %c", &element);
            s.push(element);
            break;
        case 2:
            result = s.pop();
            if (result != 0) {
                printf("The value deleted at the end is: %c\n", result);
            }
            break;
        case 3:
            result=s.peek();
            if(result!=0){
                printf("The value at the top is:%c\n",result);
            }
            break;
        case 4:
            printf("EXITING\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
void Stack::push(char element) {
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    top = top + 1;
    arr[top] = element;
    printf("Pushed '%c' onto the stack.\n", element);
}
char Stack::pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return 0;
    }
    char element = arr[top];
    top = top - 1;
    return element;
}
char Stack::peek(){
    if(top==-1){
        printf("Stack is empty\n");
        return 0;
    }
    return arr[top];
}
void Stack::print() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}
