#include <stdio.h>
#include <stdlib.h>

class list{
    struct node{
        int data;
        struct node* prev;
        struct node* next;
    }*head;
    public:
       list(){
        head=NULL;
       }
    void insertBeginning(int); 
    void insertEnd(int);
    void insertPosition(int,int);
    void deleteBeginning(int);
    void deleteEnd(int);
    void deletePosition(int,int);
    void search(int);
    void display();  
};

int main(){
    list L1;
    int choice;
    L1.insertBeginning(5);
    L1.insertBeginning(2);    
    L1.insertBeginning(7);
    //L1.insertEnd(10);
    //L1.insertPosition(3,2);
    //L1.deleteBeginning(7);
    //L1.deleteEnd(10);
    //L1.deletePosition(5,3);
    L1.search(2);
    L1.display();
    return 0;
}

void list :: insertBeginning(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    newnode->prev=NULL;

    if(head!=NULL){
        head->prev=newnode;
    }

    head=newnode;
}


void list :: insertEnd(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;
        return;
    }

    struct node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;

}

void list :: insertPosition(int val,int pos){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    struct node* temp=head;
    int count =1;
    while(temp!=NULL && count<=pos-1){
        temp=temp->next;
        count++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;

    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }
    temp->next=newnode;
}

void list :: deleteBeginning(int){
    if(head==NULL){
        printf("List if empty\n.");
    }
    struct node* temp=head;
    head=head->next;

    if(head!=NULL){
        head->prev=NULL;
    }
    free(temp);
}

void list :: deleteEnd(int){
    if(head==NULL){
        printf("List is empty\n");
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void list::deletePosition(int val, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    int count = 1;

    
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp); 
}

void list::search(int val) {
    struct node* temp = head;
    int pos = 0;

    while (temp != NULL) {
        if (temp->data == val) {
            printf("Value %d found at position %d\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Value %d not found in the list.\n", val);
}

void list :: display(){
    struct node* temp=head;
    struct node* tail=NULL;
    //forward direction
    if(head==NULL){
        printf("List is empty!");
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        tail=temp;
        temp=temp->next;
    }
    printf("\n");
    while(tail!=NULL){
        printf("%d ",tail->data);
        tail=tail->prev;
    }
    printf("\n");
}
