#include <stdio.h>
#include <stdlib.h>

class queue{
    struct node{
        int data;
        struct node* next;
    }*front,*rear;

    public:
       queue(){
        front=NULL;
        rear=NULL;
      }
       
    void Enqueue(int);
    int Dequeue();
    int peek();
};

int main(){
    int choice;
    queue q;
    do{
        printf("  Menu\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Exit\n");

        printf("Enter a number from 1-4:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int val;
                printf("Enter the element you want to Enqueue:");
                scanf("%d",&val);
                q.Enqueue(val);
                break;
            case 2:{
                int deque = q.Dequeue();
                if (deque!=-1){
                    printf("The Dequeued Element is:%d\n",deque);
                }
                else{
                    printf("Empty");
                }
                break;
            }
            case 3:{
                int peek = q.peek();
                if(peek!=-1){
                    printf("The topmost element in the queue is:%d\n",peek);
                }
                else{
                    printf("Empty");
                }
                break;
            }    
            case 4:
                printf("EXiting.....\n");
                break;            
        }

    }while(choice !=4);
    return 0;
}

void queue :: Enqueue(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

int queue :: Dequeue(){
    struct node* temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp->next->next;
    free(temp->next->next);

}

int queue :: peek(){
    if(head==NULL){
        printf("Empty Queue");
    }
    else{
        int temp=head->data;
    }
    return temp;
}