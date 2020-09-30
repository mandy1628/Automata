#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // char **list = (char**)malloc(sizeof(char*)*55);
    char list[][10] = {"auto" ,"break" ,"case","char" ,"const" ,"continue" ,"default", "do" ,"double" ,"else" ,"enum", "extern" ,"float" ,"for" ,"goto" ,"if" ,"int" ,"long" ,"register" ,"return", "short" ,"signed" ,"sizeof" ,"static" ,"struct" ,"switch" ,"typedef" ,"union" ,"unsigned" ,"void" ,"volatile" ,"while" ,"+" ,"-","*" ,"/" ,"%", "++", "--", "=" ,"==", "<", ">", "<=", ">=", "!=", "&&" ,"||" ,"!" ,"&" ,"|" ,"^" ,"<<" ,">>","//"};
    int n = sizeof(list)/sizeof(list[0]);
    for(int i=0;i<n;i++){
        if(strcmp("//",list[i]) == 0){
            printf("%s",list[i]);
            break;
        }
    }
    return 0;
}