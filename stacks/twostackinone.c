//  the main aim of the program is to implement two stacks in a single array 

#include <stdio.h>
#include <string.h>

#define MAX 100

char stackA[MAX][50];
char stackB[MAX][50];

int topA = -1;
int topB = MAX - 1;

void pushA(char value[])
{
    if (topA + 1 == topB)
    {
        printf("Stack Overflow\n");
        return;
    }

    topA++;
    strcpy(stackA[topA], value);
}

void pushB(char value[])
{
    if (topA + 1 == topB)
    {
        printf("Stack Overflow\n");
        return;
    }

    topB--;
    strcpy(stackB[topB], value);
}

void popA()
{
    if (topA == -1)
    {
        printf("Stack A Underflow\n");
        return;
    }

    topA--;
}

void popB()
{
    if (topB == MAX - 1)
    {
        printf("Stack B Underflow\n");
        return;
    }

    topB++;
}
void displayA(){
    printf("Stack A:");
    for (int i = 0; i <= topA; i++)
    {
        printf(" %s", stackA[i]);
    }
    printf("\n");
}
void displayB(){
    printf("Stack A:");
    for (int i = MAX - 1; i >= topB; i--)
    {
        printf(" %s", stackB[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    char value[50];
    while (scanf("%d", &choice) != EOF)
    {
        switch (choice)
        {
            case 1:
                scanf("%s", value);
                pushA(value);
                break;

            case 2:
                scanf("%s", value);
                pushB(value);
                break;

            case 3:
                popA();
                break;

            case 4:
                popB();
                break;

            case 5:
                displayA();
                break;

            case 6:
                displayB();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
