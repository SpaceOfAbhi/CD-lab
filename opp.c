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
  printf("\nenter : ");
  scanf("%49s",s);
  stack[++top]='$';
  while(1){
    for(int j=0;j<=top;j++){
        printf("%c",stack[j]);
    }
    printf("\t%s\t",s+i);
    if(stack[top]=='$' && s[i]=='$'){
        printf("\nValid");
        return;
    }

    x=pos(stack[top]);
    y=pos(s[i]);

    if(x==-1 || y==-1){
        printf("\ninvalid");
        return;
    }
    if(table[x][y]=='<' || table[x][y]=='='){
        stack[++top]=s[i++];
        printf("Shift\n");
    }
    else if(table[x][y]=='>'){
        a=stack[top--];
        printf("Reduce %c\n",a);
    }
    else{
        printf("\nInvalid");
    }

  }
}


void main(){
    parse();
}