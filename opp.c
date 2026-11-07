#include<stdio.h>

char stack[50],s[50];

char op[]={'i','+','*','$'};
char table[4][4] = {
                    {'=','>','>','>'},
                    {'<','>','<','>'},
                    {'<','>','>','>'},
                    {'<','<','<','='},
};

int top=-1,i=0;

int pos(char c){
    for(int j=0;j<4;j++){
        if(op[j]==c){
            return j;
        }
    }
    return -1;
}

void parse(){
    int x,y;
    char a;
  printf("\nenter");
  scanf("%49s",s);
  stack[++top]='$';
  while(1){
    for(int j=0;j<=top;j++){
        printf("%c",stack[j]);
    }
    printf("%s",s+i);
    if(stack[top]=='$' && s[i]=='$'){
        printf("\nValid");
    }

    x=

  }
}


void main(){
    parse();
}