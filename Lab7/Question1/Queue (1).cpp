//A menu driven program to perform queue operations
#include <stdio.h>
# define SIZE 5

class queue{
    int arr[SIZE];
    int front =-1;
    int rear =-1;

    public:
    queue(){
        front=-1;
        rear=-1;
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
    if(rear==SIZE-1){
        printf("Overflow!");
    }
    else if (front==-1 && rear==-1){
        front =rear=0;
    }
    else{
        rear++;
    }
    arr[rear]=val;
}

int queue :: Dequeue(){
    if(front ==-1 || front > rear){
        printf("Empty!\n");
        return -1;
    }
    int temp = arr[front];
    if(front == rear){
        front=rear=-1;
    }
    else{
        front++;
    }
    return temp;
}

int queue :: peek(){
    if (front == -1 || front > rear){
        printf("Empty\n");
        return -1;
    }

    return arr[front];
}


