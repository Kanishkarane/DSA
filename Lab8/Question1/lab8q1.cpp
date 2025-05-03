#include <stdio.h>
#include "sorting.h"


void tower(){
    int arrsize;
    scanf("%d",&arrsize);
    int arr[arrsize];
    for(int i=0;i<=arrsize-1;i++){
        scanf("%d",&arr[i]);
    }

    int beg=arr[0];
    bubbleSort(arr,arrsize);
    for(int i=1;i<arrsize;i++){
        if (arr[i]>beg){
            int excess=arr[i]- beg;
            beg+=(excess+1)/2;
        }

    }
    printf("%d",beg);
}

int main(){
    int times;
    scanf("%d",&times);
    while(times!=0){
        tower();
        times--;
    }
    return 0;
}