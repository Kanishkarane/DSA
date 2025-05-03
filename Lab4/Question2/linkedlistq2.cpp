
#include <stdio.h>
#include <stdlib.h>


#include "listadt.h"

int main() {
    list L1, L2, L3;
    int choice, value;

    while (1) {
        printf("\nMENU\n");
        printf("1. Insert List1\n");
        printf("2. Insert List2\n");
        printf("3. Merge into List3\n");
        printf("4. Display Lists\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into List1: ");
                scanf("%d", &value);
                L1.insertascending(value);
                break;

            case 2:
                printf("Enter value to insert into List2: ");
                scanf("%d", &value);
                L2.insertascending(value);
                break;

            case 3:
                printf("Merging List1 and List2 into List3...\n");
                L3 = L1.merge(L2);
                break;

            case 4:
                printf("List1: ");
                L1.display();
                printf("List2: ");
                L2.display();
                printf("List3 (Merged List): ");
                L3.display();
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
