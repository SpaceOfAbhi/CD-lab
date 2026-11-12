#include <stdio.h>
#include <string.h>

int main()
{
    char s[20], res[10][10], a[10][10], b[10][10], op[10];
    int n, x, y, r, i, j;

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        scanf("%s", s);

        sscanf(s, "%[^=]=%s", res[i], a[i]);


        char *p = strchr(a[i], '+');
        if(!p) p = strchr(a[i], '-');
        if(!p) p = strchr(a[i], '*');
        if(!p) p = strchr(a[i], '/');

        if(p)
        {
            op[i] = *p;
            *p = '\0';
            strcpy(b[i], p+1);
        }
        else
        {
            op[i] = '=';
            strcpy(b[i], "-");
        }
    }

    for(i=0; i<n; i++)
    {
        if(sscanf(a[i], "%d", &x)==1 &&
           sscanf(b[i], "%d", &y)==1)
        {
            switch(op[i])
            {
                case '+': r=x+y; break;
                case '-': r=x-y; break;
                case '*': r=x*y; break;
                case '/': if(y==0) continue; r=x/y; break;
                default: continue;
            }

            sprintf(a[i], "%d", r);
            op[i] = '=';
        }

        for(j=i+1; j<n; j++)
        {
            if(!strcmp(a[j], res[i])) strcpy(a[j], a[i]);
            if(!strcmp(b[j], res[i])) strcpy(b[j], a[i]);
        }
    }

    printf("\nOptimized Code:\n");

    for(i=0; i<n; i++)
    {
        if(op[i]=='=')
            printf("%s=%s\n", res[i], a[i]);
        else
            printf("%s=%s%c%s\n", res[i], a[i], op[i], b[i]);
    }

    return 0;
}