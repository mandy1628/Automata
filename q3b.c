#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

char* state0(char*,int,int);
char* state1(char*,int,int);
char* state2(char*,int,int);
char* state3(char*,int,int);
char* state4(char*,int,int);
char* dead(char*,int,int);
int inLimit(int pos,int n,bool flag){
    if(pos >= n){
        if(flag)
            return 1;
        else
            return -1;
    }
    return 0;
}
char* state0(char* str,int n,int pos){
    bool flag = false;
    char* tmp;
    // printf("In state 0\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        return "Not accepted";
    }

    if(str[pos++] == 'a'){
        tmp = state1(str,n,pos);
    }
    else{
        tmp = state2(str,n,pos);
    }
}

char* state1(char* str,int n,int pos){
    bool flag = true;
    char *tmp;
    // printf("In state 1\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        return "Accepted";
    }

    if(str[pos++] == 'a'){
        tmp = state3(str,n,pos);
    }
    else{
        tmp = state2(str,n,pos);
    }
}

char* state2(char* str,int n,int pos){
    bool flag = true;
    char *tmp;
    // printf("In state 2\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        return "Accepted";
    }

    if(str[pos++] == 'a'){
        tmp = state1(str,n,pos);
    }
    else{
        tmp = state2(str,n,pos);
    }
}

char* state3(char* str,int n,int pos){
    bool flag = true;
    char *tmp;
    // printf("In state 3\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        return "Accepted";
    }

    if(str[pos++] == 'a'){
        tmp = state4(str,n,pos);
    }
    else{
        tmp = state2(str,n,pos);
    }
}

char* state4(char* str,int n,int pos){
    bool flag = true;
    char *tmp;
    // printf("In state 4\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        return "Accepted";
    }

    if(str[pos++] == 'a'){
        tmp = dead(str,n,pos);
    }
    else{
        tmp = state2(str,n,pos);
    }
}

char* dead(char* str,int n,int pos){
    bool flag = false;
    char *tmp;
    // printf("In dead\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        return "Not accepted";
    }

    pos++;
    tmp = dead(str,n,pos);
}

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
    char *str = (char*)malloc(sizeof(char)*100);
    char *ans;
    scanf("%s",str);
    int n = strlen(str);
    bool valid = isValid(str,n);
    if(valid){
        ans = state0(str,n,0);
        if(strcmp(ans,"Accepted") == 0){
            if(strstr(str,"a")!=NULL){
                if(strstr(str,"b")!=NULL)
                    printf("The string is generated.The smallest acceptable strings are a and b.\n");
                else
                    printf("The string is generated.The smallest acceptable string is a.\n");
            }
            else
                printf("The string is generated.The smallest acceptable string is b.\n");
        }
        else{
            if(strstr(str,"a")!=NULL ){
                if(strstr(str,"b")!=NULL)
                    printf("The string cannot be generated. The smallest acceptable strings are a and b.\n");
                else
                    printf("The string cannot be generated. The smallest acceptable string is a.\n");
            }
            else
                printf("The string cannot be generated. The smallest acceptable string is b.\n");        
            }
    }
    else{
        printf("Invalid string");
    }
    return 0;
}

