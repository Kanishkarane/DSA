# include <stdio.h>
# include <stdlib.h>

class stack{
    struct node{
        char data;
        struct node* next;
    }*top;

    public:
       stack(){
        top=NULL;
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
        printf("\n   Menu:\n");
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
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL){
        printf("Empty!");
    }
    newnode->data=element;
    newnode->next=top;
    top=newnode;
}

void stack :: pop(){
    if(top==NULL){
        printf("Empty!");
    }
    else{
        struct node* temp=top;
        top=top->next;
        free(temp);
    }
}

char stack :: peek(){
    if(top == NULL){
        printf("Empty!");
    }
    return top->data;
}
