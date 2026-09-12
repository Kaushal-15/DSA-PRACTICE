#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *top = NULL;

void push(int data) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newnode->data = data;
    newnode->next = top;
    top = newnode;
    printf("%d pushed into stack\n", data);
}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->next;
    free(temp);
}

void count(struct node *top){
    struct node *temp = top;
    int count = 0;
    if(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("%d\n",count);
    printf("\n");
}

void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
            
            case 5:
                count(top);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
