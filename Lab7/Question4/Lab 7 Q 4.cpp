#include <stdio.h>
#include "stack.h"
#include <string.h>

void stringstack(char *str){
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='+'){
            if(!isEmpty()){
                pop();
            }   
        }
        else{
            push(str[i]);
        }

    }

    char output[100];
    int index=0;
    while(!isEmpty()){
        output[index++]=pop();
    }
    output[index]='\0';
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", output[i]);
    }

}

int main(){
    char str[100];
    printf("Enter the string:");
    scanf("%s",str);

    stringstack(str);

    return 0;
}