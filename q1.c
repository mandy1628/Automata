#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int countK = 0,countOp = 0,countCom = 0;
    char *buff;
    buff = (char*)malloc(sizeof(char)*100);
    char list[][10] = {"auto" ,"break" ,"case","char" ,"const" ,"continue" ,"default", "do" ,"double" ,"else" ,"enum", "extern" ,"float" ,"for" ,"goto" ,"if" ,"int" ,"long" ,"register" ,"return", "short" ,"signed" ,"sizeof" ,"static" ,"struct" ,"switch" ,"typedef" ,"union" ,"unsigned" ,"void" ,"volatile" ,"while" ,"+" ,"-","*" ,"/" ,"%", "++", "--", "=" ,"==", "<", ">", "<=", ">=", "!=", "&&" ,"||" ,"!" ,"&" ,"|" ,"^" ,"<<" ,">>","//"};
    // In above list elements upto 31 are keywords, elements in range [32,53] are operators, and last element is for single line comment
    
    FILE *fptr2;
    fptr2 = fopen("input.txt","r");
    while(fscanf(fptr2,"%s",buff) != EOF){
        for(int j=0;j<55;j++){
            if(strcmp(buff,"//") == 0){
                countCom++;
                break;
            }
            if(strstr(buff,list[j]) != NULL){
                if(j < 32 && strstr(buff,"print") == NULL && strstr(buff,"Print") == NULL){
                    countK++;
                    // printf("%s\t%d\n",list[j],countK);
                    break;
                }
                else if(j >= 32 && j <= 53){
                    countOp++;
                    // printf("%s\t%d\n",list[j],countOp);
                    break;
                }
            }
            // free(buff);
        }
    }
    countK--;   // Line no.1 is a commnet and it has 'for' in it.
    countOp--;  //Line no.2 is a preprocessing command but it has '<>' in it.
    printf("Keywords=%d, Single line comments=%d, Operators=%d",countK,countOp,countCom);
    fclose(fptr2);
    return 0;
}