#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

class stack{
    char arr[SIZE];
    int top;

    public:
    stack(){
    top=-1;
   }

   void push(char);
   void pop();
   char peek();
};

int main() {
    stack s; 
    int choice;
    char element;

    do {
        printf("\n  Menu\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to push: ");
                scanf(" %c", &element);
                s.push(element);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                char x;
                x=s.peek();
                printf("%c",x);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void stack :: push(char element){
    if (top == SIZE-1){
        printf("Stack is full!");
    }
    else{
        arr[++top]=element;
    }
}

void stack :: pop(){
    if(top==-1){
        printf("Stack is empty!");
    }
    else{
        arr[top--];
    }
}

char stack :: peek(){
    if(top==-1){
        printf("Stack is empty!");
    }
    else{
        return arr[top];
    }
}