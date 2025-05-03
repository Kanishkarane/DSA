#include <stdio.h>
//program to sort a given array of numbers using different sort techniques

//printing the menu to print 4 options
void menu(){
    printf("     Menu\n");
    printf("1.Bubble sort\n");
    printf("2.Selection sort\n");
    printf("3.Insertion sort\n");
    printf("4.Exit\n");
}

//function to print the array
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

//function to sort a given array using bubble sort technique
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j]; //swapping with temp 
                arr[j]=arr[j+1];
                arr[j+1]=temp; 
            }
        }
    }
}

//function to sort a given array using selection sort technique
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){ // condition for selection sort
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        int temp=arr[i];// swapping with temp 
        arr[i]=arr[min_index];
        arr[min_index]=temp;
        
    }
}
// function to sort a given array using insertion sort technique
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){ // checking condition for insertion sort
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key; // swapping with key
    }
}

int main() {
    int n;
    int arr[50];
    printf("Enter the size of the array: ");
    scanf("%d", &n); // taking input for the array size
    for (int i = 0; i < n; i++) { // taking input for each array element
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    printf("Given Array: ");
    print_array(arr, n);
    printf("\n");

    int choice;
    do {
        menu();
        printf("Enter the number you want to choose: "); // taking input for the user's choice
        scanf("%d", &choice);
        // printing as per the user's choice
        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                printf("Sorted Array: ");
                print_array(arr, n);
                printf("\n");
                break;
            case 2:
                selectionSort(arr, n);
                printf("Sorted Array: ");
                print_array(arr, n);
                printf("\n");
                break;
            case 3:
                insertionSort(arr, n);
                printf("Sorted Array: ");
                print_array(arr, n);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
