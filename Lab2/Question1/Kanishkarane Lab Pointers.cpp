#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(){
    char *menuString = "        MENU\n1. Palindrome checking\n2. Armstrong number checking\n3. Perfect number checking\n4. Exit\n";
    char *menutext = (char*)malloc(strlen(menuString)+1);
    if (menutext == NULL) {  // Always check if malloc succeeds
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(menutext,menuString);
    printf("%s",menutext);
    free(menutext);
}

void palindromeChecking(int *num){
    int *temp=(int*)malloc(sizeof(int));
    int *rn=(int*)malloc(sizeof(int));
    if (temp==NULL || rn==NULL){
        printf("Memory allocation failed!");
    }

    *temp= *num;
    *rn =0;

    while(*temp !=0){
        int *r=(int*)malloc(sizeof(int));
        if (r==NULL){
            printf("Memory allocation failed!");
            free(temp);
            free(rn);
            return;
        }
        *r=*temp % 10;
        *rn=(*rn * 10) + *r;
        *temp=*temp/10;

        free(r);

    }
    if(*rn==*num){
        printf("Given number is a palindrome number\n");
    }
    else{
       printf("Given number is not a palindrome number\n");
    }
    
    free(temp);
    free(rn);

}

void armstrongChecking(int *num){
    int *temp=(int*)malloc(sizeof(int));
    int *an=(int*)malloc(sizeof(int));
    if (temp == NULL || an == NULL){
        printf("Memory allocation failed!");
    }

    *temp = *num;
    *an=0;

    while(*temp !=0){
        int *r=(int *)malloc(sizeof(int));
        if (r==NULL){
            printf("Memory allocation failed!");
            free(an);
            free(temp);
            return;
        }
        *r = *temp % 10;
        *an = *an+ (*r * *r * *r);
        *temp =*temp/10;

        free(r);
    }

    if(*an == *num){
        printf("Given number is an armstrong number\n");
    }
      else{
        printf("Given number is not an armstrong number\n");
    }

    free(temp);
    free(an);
}


void perfectChecking(int *num){
    int *sum=(int*)malloc(sizeof(int));
    int *i=(int*)malloc(sizeof(int));
    if (sum == NULL || i == NULL){
        printf("Memory allocation failed!");
        return;
    }
    *sum =0;
    for(*i=1; *i < *num;(*i)++){
        if(*num % *i == 0){
            *sum = *sum + *i;
        }
    }
    if(*sum == *num){
        printf("Given number is a perfect number.\n");
    }
    else{
        printf("Given number is not a perfect number.\n");
    }

    free(sum);
    free(i);
}

int main(){
    int *choice=(int*)malloc(sizeof(int));
    if (choice == NULL) { // Check if allocation failed
        printf("Memory allocation failed!\n");
        return 1;
    }
    int *numpal = NULL;
    int *numarm = NULL;
    int *numper = NULL;
    do{
        menu();
        printf("Enter the choice you want(1,2,3,4):");
        scanf("%d",choice);

        switch(*choice){
            case 1:
                 printf("Enter a number for palindrome number checking:");
                 numpal=(int*)malloc(sizeof(int));
                 if (numpal == NULL) {
                    printf("Memory allocation failed!\n");
                    break;
                }
                 scanf("%d",numpal);
                 palindromeChecking(numpal);
                 free(numpal);
                 break;
            case 2:
                 printf("Enter a number for armstrong number checking:");
                 numarm=(int*)malloc(sizeof(int));
                 if (numarm == NULL) {
                    printf("Memory allocation failed!\n");
                    break;
                }
                 scanf("%d",numarm);
                 armstrongChecking(numarm);
                 free(numarm);
                 break;

            case 3:
                 printf("Enter a number for perfect number checking:");
                 numper=(int*)malloc(sizeof(int));
                 if (numper == NULL) {
                    printf("Memory allocation failed!\n");
                    break;
                }
                 scanf("%d",numper);
                 perfectChecking(numper);
                 free(numper);
                 break;
            case 4:
                 break;
            default:
                printf("Invalid choice.Enter another number.");  
                      
        }

    }while (*choice != 4);
    free(choice);
    return 0;
}
