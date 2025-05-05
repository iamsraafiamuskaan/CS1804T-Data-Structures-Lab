#include <iostream>
using namespace std;


class cll{
    private:
    struct node{
        int data;
        struct node * link;
    }*head;
    public:
        cll(){
            head=NULL;
        }
        void insertbeg(int);
        void insertend(int);
        void insertprocess(int);
        void execute(int);
        int deletebeg();
        void display();
};


void cll::insertbeg(int num){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num;
    if (head==NULL){
        newnode->data=num;
        newnode->link=newnode;
        head=newnode;
    }
    else{
        struct node*temp=head;
        newnode->link=head;
        while (temp->link != head){
            temp=temp->link;
        }
        temp->link=newnode;
        head=newnode;
    }
    cout<<"\nThe number is inserted\n\n";
}

void cll::insertend(int num){
    struct node * newnode=(struct node*) malloc(sizeof(struct node));
    struct node * temp=head;
    newnode->data=num;
    if (head==NULL){
        insertbeg(num);
    }
    else{
        while(temp->link != head){
            temp=temp->link;
        }
        temp->link=newnode;
        temp->link->link=head;
        cout<<"\nThe number is inserted\n\n";
    }
}


void cll::insertprocess(int num){
    insertend(num);
}


int cll::deletebeg(){
    struct node * temp1=head;
    int count=1;
    while(temp1->link != head){
        count++;
        temp1=temp1->link;
    }
    if (count==1){
        int val1=head->data;
        head=NULL;
        return val1;
    }
    else{
        struct node * temp2=head;
        int val=temp2->data;
        while (temp2->link != head){
            temp2=temp2->link;
        }
        temp2->link=head->link;
        struct node *temp3=head;
        head=head->link;
        temp3->link=NULL;
        return val;
    }
}


void cll::display(){
    struct node * temp=head;
    cout<<"\n";
    if (head==NULL){
        cout<<"\nThe list is empty\n\n";
    }
    else{
        while (temp->link != head){
            cout<<temp->data<<"->";
            temp=temp->link;
        }
        cout<<temp->data<<"\n\n";
    }
   
}


void cll::execute(int shatime){
    int value=deletebeg();
    int number=value-shatime;
    if (number>0){
        insertend(number);
    }
    else{
        cout<<"\nThe number is deleted from the list\n\n";
    }

}
