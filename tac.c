#include <stdio.h>

void main(){
    char in[29];
    int k=1;

    printf("enter : ");
    scanf("%s",in);

    char op[]={'/','*','+','-'};

    for(int p=0;p<4;p++){
        for(int i=0;in[i]!='\0';i++){
            if(in[i]==op[p]){
                printf("t%d=%c%c%c\n",k,in[i-1],in[i],in[i+1]);
                in[i-1]='0'+k;

                for(int j=i;in[j]!='\0';j++){
                    in[j]=in[j+1];

                }
                i--;
                k++;
            }
        }
    }

    printf("%c=t%d\n",in[0],k-1);

}