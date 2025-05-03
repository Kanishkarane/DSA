#include <stdio.h>
#include <stdlib.h>

class list{
    struct node{
        int data;
        struct node *next;
    }*head;
    public:
       list(){
           head =NULL;
       }
    void insertBeg(int);
    void insertEnd(int); 
    void insertPos(int,int);
    void delbeg(int);
    void delend(int);
    void delpos(int,int);
    int search(int);
    void display(); 
};


int main(){
    list L1;
    int choice;
    do{
        printf(" Menu\n");
        printf("1.Insert beginning\n");
        printf("2.Insert End\n");
        printf("3.Insert position\n");
        printf("4.Delete beginning\n");
        printf("5.Delete end\n");
        printf("6.Delete position\n");
        printf("7.Search\n");
        printf("8.Display\n");
        printf("9.Exit\n");
        printf("Enter a number from (1-9):");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                int value;
                printf("Enter a no you want to insert:");
                scanf("%d",&value);
                L1.insertBeg(value);
                break;

            case 2:
                int value1;
                printf("Enter a no you want to insert:");
                scanf("%d",&value1);
                L1.insertEnd(value1);
                break;

            case 3:
                int value2;
                int pos;
                printf("Enter a no you want to insert:");
                scanf("%d",&value2);
                printf("Enter in which position do you want to insert:");
                scanf("%d",&pos);
                L1.insertPos(value2,pos);
                break;

            case 4:
                int value3;
                printf("Enter a value you want to delete:");
                scanf("%d",&value3);
                L1.delbeg(value3);
                break;

            case 5:
                int value4;
                printf("Enter a value you want to delete:");
                scanf("%d",&value4);
                L1.delend(value4);
                break;
                
            case 6:
                int value5;
                int pos1;
                printf("Enter a no you want to delete:");
                scanf("%d",&value5);
                printf("Enter in which position do you want to delete:");
                scanf("%d",&pos1);
                L1.delpos(value5,pos1);
                break;
                
            case 7:
                int value6;
                printf("Enter a number you want to search:");
                scanf("%d",&value6);
                if(L1.search(value6)!=-1){
                    printf("Element found at",L1.search(value6));
                }
                else{
                    printf("Not found!");
                }
                break;

            case 8:
                printf("The elements in the given linked list:");
                L1.display();
                break;
                 
            case 9:
                break;
                
            default:
                printf("Enter a no between 1 and 9:");    
                        

        }
    }while (choice!=9);
    return 0;

} 

void list :: insertBeg(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        struct node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
    newnode->next=head;
    temp->next=newnode;
    head=newnode;
    }   
} 
void list :: insertEnd(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        newnode->next=head;
        return;
    }
    else{
        struct node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    
}

void list :: insertPos(int val,int pos){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    int count=1;
    struct node* temp=head;
    while(temp != NULL && count<pos-1){
        temp=temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void list :: delbeg(int){
    if(head==NULL){
        printf("List empty\n");
    }
    struct node* temp=head;
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    struct node* temp1=head;
    while(temp1->next!=head){
        temp1=temp1->next;
    }
    head=head->next;
    temp1->next=head;
    free(temp);
}

void list :: delend(int val){
    if(head==NULL){
        printf("List empty\n");
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    prev = temp;
    free(temp->next);
    prev->next = head;

}

void list :: delpos(int val,int pos){
    if (head == NULL) {
        printf("List is empty!\n");
    }
    struct node* temp = head;
    struct node* prev = NULL;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && pos > 1) {
        printf("Position out of range!\n");
    }
    prev->next = temp->next;
    free(temp);

}

int list :: search(int val){
    struct node* temp=head;
    int cur=0;
    while(temp->next!=head){
        if(temp->data == val){
            return cur;
        }
        temp=temp->next;
        cur++;
    }
    if(temp->data==val){
        return cur++;
    }

    return -1;
}

void list :: display(){
    if(head==NULL){
        printf("List empty.\n");
    }
    struct node* temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
}