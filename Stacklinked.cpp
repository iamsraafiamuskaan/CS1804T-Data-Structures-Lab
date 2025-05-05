#include<stdio.h>
#include<iostream>
using namespace std;
class Stack{
private:
    struct node{
        char data;
        struct node *next;
    };
node *top;
public:
Stack(){
    top = NULL;
}
void push(char element);
char pop();
char peek();
};
int main(){
    Stack s;
    int choice;
    char element,result;
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
void Stack::push(char element){
    struct node * newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Stack Overflow\n");
    }
    newnode->data=element;
    newnode->next=NULL;
    newnode->next=top;
    top=newnode;
    printf("Pushed %c onto the stack\n",element);
}
char Stack::pop(){
    struct node *temp;
    temp=top;
if(top==NULL){
    printf("Stack is empty\n");
    return 0;
}
 char result=temp->data;
    top=top->next;
    return result;
}
char Stack::peek(){
    if(top==NULL){
        printf("Stack Underflow\n");
    }
    return top->data;
}