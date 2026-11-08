#include <stdio.h>

void main(){
    char in[29];
    int k=0;
    char val='A';

    printf("enter : ");
    scanf("%s",in);

    char op[]={'/','*','+','-'};
    printf("Index\tOP\tArg1\tArg2\tResult\n");
    for(int p=0;p<4;p++){
        for(int i=0;in[i]!='\0';i++){
            if(in[i]==op[p]){
                printf("%d\t%c\t%c\t%c\t%c\n",k,in[i],in[i-1],in[i+1],val);
                in[i-1]=val;

                for(int j=i;in[j]!='\0';j++){
                    in[j]=in[j+2];

                }
                i--;
                k++;
                val++;
            }
        }
    }
    printf("%d\t=\t%c\t%c\n", k, val-1,in[0]);

}