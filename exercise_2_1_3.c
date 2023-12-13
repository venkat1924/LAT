#include <stdio.h>
#include <string.h>

int check(char* expression);

int top;

int main()
{
    char expression[100];
    printf("Enter string: \n");
    scanf("%s", expression);
    if ((strlen(expression))%2==0)
    {
        if(check(expression))
            printf("Expression IS of the form \' x C y \'.\n");
        else
            printf("Expression is NOT of the form \' x C y \'.\n");
    }
    else
    {
        printf("Expression is NOT of the form \' x C y \' because we have odd number of characters.\n");
    }
    return 0;
}

int push(int item, int* x)
{
    ++top;
    x[top]=item;
}

int pop(int* x)
{
    int item=x[top];
    --top;
    return item;
}

int check (char* expression)
{
    int item;
    int len = strlen(expression);
    int x[len/2], y[len/2];
    
    for (int i=0; i< (len/2); i++)
        push(expression[i], x);
    
    for(int i=len/2; i<len;i++)
    {
        item = pop(x);
        if (expression[i]!=item)
            return 0;
    }
    
    return 1;
    
}
