#include <stdio.h>
#include <string.h>
#include "stack.h"

// Function to check if parentheses are balanced
int isBalanced(char* expr) {
    Stack s = {NULL};
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            push(&s, '(');
        } else if (expr[i] == ')') {
            if (isEmpty(&s)) return 0; // Unbalanced (extra ')')
            pop(&s);
        }
    }
    
    return isEmpty(&s); // If stack is empty, it's balanced
}

int main() {
    char expr[100];
    int choice;

    do {
        printf("\n1. Check Balance\n2. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter expression: ");
            scanf("%s", expr);

            if (isBalanced(expr)) {
                printf("Balanced!\n");
            } else {
                printf("Not Balanced!\n");
            }
        }
    } while (choice != 2);

    return 0;
}
