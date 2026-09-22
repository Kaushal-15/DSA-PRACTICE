#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value)
{
    if (top  == MAX -1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = value;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    return stack[top--];
}

void display()
{
    for(int i = top; i<0; i--)
    {
        printf("%c ",stack[top]);
    }
}

int main()
{
    char result[MAX];

    printf("Enter the string: ");
    fgets(result,MAX,stdin);

    for(int i = 0; result[i] != '\0' && result[i] != '\n'; i++)
    {
        push(result[i]);
    }

    printf("Reversed string: ");

    while (top != -1)
    {
        char val = pop();
        printf("%c",val);
    }

    return 0;
}