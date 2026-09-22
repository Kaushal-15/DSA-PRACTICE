#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value)
{
    if (top == MAX - 1)
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
        return '\0';
    }

    return stack[top--];
}

int main()
{
    char result[MAX];
    int flag = 1;

    printf("Enter the string: ");
    fgets(result, MAX, stdin);

    for (int i = 0; result[i] != '\0' && result[i] != '\n'; i++)
    {
        push(result[i]);
    }

    for (int i = 0; result[i] != '\0' && result[i] != '\n'; i++)
    {
        char val = pop();

        if (result[i] != val)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }

    return 0;
}