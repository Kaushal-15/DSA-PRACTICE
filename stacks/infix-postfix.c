#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char c);
char pop();
int isempty();
int precedence(char c);
void print();
int space(char c);
void intopos();

int main()
{
    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin);

    intopos();
    print();

    return 0;
}

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = c;
}

char pop()
{
    char c;

    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }

    c = stack[top];
    top--;

    return c;
}

int precedence(char c)
{
    switch (c)
    {
        case '^':
            return 3;

        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

int isempty()
{
    return top == -1;
}

int space(char c)
{
    return (c == ' ' || c == '\t');
}

void print()
{
    int i = 0;

    printf("Postfix Expression: ");

    while (postfix[i] != '\0')
    {
        printf("%c", postfix[i]);
        i++;
    }

    printf("\n");
}

void intopos()
{
    int i, j = 0;
    char symbol;

    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        if (space(symbol) || symbol == '\n')
            continue;

        switch (symbol)
        {
            case '(':
                push(symbol);
                break;

            case ')':
                while (!isempty() && stack[top] != '(')
                {
                    postfix[j++] = pop();
                }

                if (!isempty() && stack[top] == '(')
                    pop();

                break;

            case '^':
            case '*':
            case '/':
            case '+':
            case '-':

                while (!isempty() &&
                       stack[top] != '(' &&
                       precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[j++] = pop();
                }

                push(symbol);
                break;

            default:
                postfix[j++] = symbol;
        }
    }

    while (!isempty())
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}