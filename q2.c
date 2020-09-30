#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* str,int n){
    for(int i=0;i<n;i++){
        if(str[i] == 'a')
            continue;
        else if(str[i] == 'b')
            continue;
        else
            return false;
    }
    return true;
}

int main(){
    char *str;
    str = (char*)malloc(sizeof(char)*100);
    printf("Enter string(<100 char): ");
    scanf("%s",str);
    int n = strlen(str);
    if(!isValid(str,n)){
        printf("String is invalid\n");
    }
    else if(n >= 5){
        if(str[0] != str[3]){
            printf("Accepted\n");
        }
        else{
            printf("Not Accepted\n");
        }
    }
    else{
        printf("Not Accepted\n");
    }
    return 0;
}