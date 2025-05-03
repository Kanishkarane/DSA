#include <stdio.h>
#include "sorting.h"
// program to search a given number using different techniques


//printing the menu displaying 3 options
void menu(){
    printf("   Menu\n");
    printf("1.Linear Search\n");
    printf("2. Binary Search\n");
    printf("3.Exit\n");
}

int linearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if (arr[i]==target){// linear search logic
            return i;
        }  
    }
    return -1;
}

int binarySearch(int arr[],int n,int target){
    bubbleSort(arr,n);
    int start=0;
    int end=n-1;
    
    
    while(start<=end){// binary search logic
        int middle=(start+end)/2;// finding mid element
        
        if (arr[middle]== target){
            return middle;
        }
        if (arr[middle]<target){
            start=middle+1;
        }
        if (arr[middle]>target){
            end=middle-1;
        }
        
    }
    return -1;
}

int main(){
    int n;
    int arr[50];
    printf("Enter the size of the array: ");// taking input for the array size
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { // taking input for each array element
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    int choice;
    int target;
    printf("Enter the element to be searched:");// taking input for the target element
    scanf("%d",&target);
    
    do {
        menu();
        printf("Enter the number you want to choose: ");// taking input for the user's choice
        scanf("%d", &choice);
        // printing as per the user's choice
        switch (choice) {
            case 1:
                int result;
                result =linearSearch(arr,n,target);
                if (result==-1){
                    printf("Not Found.\n");
                }
                else{
                    printf("Found at %d\n",result);
                }
                break;
            case 2:
                int result1;
                result1=binarySearch(arr,n,target);
                if(result1!=-1){
                    printf("Found at %d\n",result1);
                }
                else{
                    printf("Not found\n");
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;    
        

}