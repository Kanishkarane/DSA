#include <stdio.h>
#include <stdlib.h>

class list {
    struct node {
        int data;
        struct node* next;
    } *head;

public:
    list() {
        head = NULL;
    }

    void insertbeg(int);
    void insertend(int);
    void insertpos(int, int);
    void delbeg();
    void delend();
    void delpos(int);
    int search(int);
    void display();
    void dispreverse();
    void reverselink();
};

int main() {
    list L1;
    int choice;
    do {
        printf(" Menu\n");
        printf("1. Insert beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert position\n");
        printf("4. Delete beginning\n");
        printf("5. Delete end\n");
        printf("6. Delete position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Display reverse\n");
        printf("10. Reverse link\n");
        printf("11. Exit\n");
        printf("Enter a number from (1-11): ");
        scanf("%d", &choice);

        int value, pos;
        switch (choice) {
            case 1:
                printf("Enter a number you want to insert: ");
                scanf("%d", &value);
                L1.insertbeg(value);
                break;

            case 2:
                printf("Enter a number you want to insert: ");
                scanf("%d", &value);
                L1.insertend(value);
                break;

            case 3:
                printf("Enter a number you want to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                L1.insertpos(value, pos);
                break;

            case 4:
                L1.delbeg();
                break;

            case 5:
                L1.delend();
                break;

            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                L1.delpos(pos);
                break;

            case 7:
                printf("Enter a number to search: ");
                scanf("%d", &value);
                if (L1.search(value) != -1) {
                    printf("Element found at position %d\n", L1.search(value));
                } else {
                    printf("Not found!\n");
                }
                break;

            case 8:
                printf("The elements in the given linked list: ");
                L1.display();
                break;

            case 9:
                printf("The elements in reverse order: ");
                L1.dispreverse();
                break;

            case 10:
                L1.reverselink();
                break;

            case 11:
                break;

            default:
                printf("Enter a number between 1 and 11\n");
        }
    } while (choice != 11);

    return 0;
}

// Inserting at the beginning
void list::insertbeg(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

// Inserting at the end
void list::insertend(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Inserting at a particular position
void list::insertpos(int val, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct node* temp = head;
    int cur = 1;

    // Traverse to the desired position
    while (cur < pos - 1 && temp != NULL) {
        temp = temp->next;
        cur++;
    }

    // If position is out of bounds
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = temp->next;
    temp->next = newnode;
}

// Deleting at the beginning
void list::delbeg() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
}

// Deleting at the end
void list::delend() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Deleting at a particular position
void list::delpos(int pos) {
    if (pos < 1 || head == NULL) {
        printf("Invalid position or list is empty!\n");
        return;
    }

    struct node* temp = head;
    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    int cur = 1;
    while (cur < pos - 1 && temp != NULL) {
        temp = temp->next;
        cur++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

// Searching for a particular element
int list::search(int target) {
    struct node* temp = head;
    int cur = 0;

    while (temp != NULL) {
        if (temp->data == target) {
            return cur;
        }
        cur++;
        temp = temp->next;
    }

    return -1; // Element not found
}

// Displaying the elements
void list::display() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Displaying the elements in reverse order
void list::dispreverse() {
    int length = 0;
    struct node* temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    for (int i = length - 1; i >= 0; i--) {
        temp = head;
        int j = 0;
        while (j < i) {
            temp = temp->next;
            j++;
        }
        printf("%d ", temp->data);
    }
    printf("\n");
}

// Reversing the linked list
void list::reverselink() {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
