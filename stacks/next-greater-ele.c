#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;
void push(char c);
char pop();

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

int main()
{
    int n;
    int arr[MAX], result[MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        while(top != -1 && arr[stack[top]] < arr[i]){
            result[stack[top]] = arr[i];
            pop();
        }
       push(i);
    }

    printf("The result array is\n");
    for (int i = 0; i < n; i++){
        printf("%d ", result[i]);
    }
    return 0;
}