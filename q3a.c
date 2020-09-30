#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void state0(char*,int,int);
void state1(char*,int,int);
void state2(char*,int,int);
void state3(char*,int,int);
void state4(char*,int,int);
void dead(char*,int,int);
int inLimit(int pos,int n,bool flag){
    if(pos >= n){
        if(flag)
            return 1;
        else
            return -1;
    }
    return 0;
}
void state0(char* str,int n,int pos){
    bool flag = false;
    printf("In state 0\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        printf("Not accepted");
        return;
    }

    if(str[pos++] == 'a'){
        state1(str,n,pos);
    }
    else{
        state2(str,n,pos);
    }
}

void state1(char* str,int n,int pos){
    bool flag = true;
    printf("In state 1\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        printf("Accepted");
        return;
    }

    if(str[pos++] == 'a'){
        state3(str,n,pos);
    }
    else{
        state2(str,n,pos);
    }
}

void state2(char* str,int n,int pos){
    bool flag = true;
    printf("In state 2\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        printf("Accepted");
        return;
    }

    if(str[pos++] == 'a'){
        state1(str,n,pos);
    }
    else{
        state2(str,n,pos);
    }
}

void state3(char* str,int n,int pos){
    bool flag = true;
    printf("In state 3\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        printf("Accepted");
        return;
    }

    if(str[pos++] == 'a'){
        state4(str,n,pos);
    }
    else{
        state2(str,n,pos);
    }
}

void state4(char* str,int n,int pos){
    bool flag = true;
    printf("In state 4\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        printf("Accepted");
        return;
    }

    if(str[pos++] == 'a'){
        dead(str,n,pos);
    }
    else{
        state2(str,n,pos);
    }
}

void dead(char* str,int n,int pos){
    bool flag = false;
    printf("In dead\t%d\t%d\n",pos,n);
    if(inLimit(pos,n,flag) != 0){
        printf("Not accepted");
        return;
    }

    pos++;
    dead(str,n,pos);
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
    scanf("%s",str);
    int n = strlen(str);
    bool valid = isValid(str,n);
    if(valid){
        state0(str,n,0);
    }
    else{
        printf("Invalid string");
    }
    return 0;
}