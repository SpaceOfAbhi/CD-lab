#include<stdio.h>
#include<string.h>

void main(){

    char in[10][10];
    char op[10];
    int i=0,k=0;

    printf("enter :");
    do{
        scanf("%s",in[i++]);
        
    }while(strcmp(in[i-1],"exit")!=0);

    i=0;
    do{
        switch(in[i][3]){
            case '+':
             strcpy(op,"ADD");
             break;
            case '-':
             strcpy(op,"SUB");
             break;
            case '*':
             strcpy(op,"MUL");
             break;
            case '/':
             strcpy(op,"DIV");
             break;
        }

        printf("MOV %c,R%d\n",in[i][2],k);
        printf("%s %c,R%d\n",op,in[i][4],k);
        printf("MOV R%d,%c\n",k,in[i][0]);
        i++;
        printf("\n");
    }while(strcmp(in[i],"exit")!=0);

}