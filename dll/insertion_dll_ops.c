// Create a doubly linked list and perform insertion at the beginning, end, and a specific position using functions.

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* insertBeginning(struct node *head, int data)
{
    struct node *newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL){
        head->prev = newNode;
    }

    head = newNode;

    return head;
}

struct node* insertEnd(struct node *head, int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    struct node *p = head;

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL){
        newNode->prev = NULL;
        return newNode;
    }

    while(p->next != NULL){
        p = p->next;
    }

    p->next = newNode;
    newNode->prev = p;

    return head;
}

struct node* insertPosition(struct node *head, int data, int pos)
{
    struct node *newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(pos == 1){
        newNode->next = head;

        if(head != NULL){
            head->prev = newNode;
        }

        return newNode;
    }

    struct node *p = head;

    for(int i = 1; i < pos - 1 && p != NULL; i++){
        p = p->next;
    }

    if(p == NULL){
        free(newNode);
        return head;
    }

    newNode->next = p->next;
    newNode->prev = p;

    if(p->next != NULL){
        p->next->prev = newNode;
    }

    p->next = newNode;

    return head;
}

void display(struct node *head)
{
    struct node *p = head;

    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    struct node *head = NULL;

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int data;
        scanf("%d", &data);

        head = insertEnd(head, data);
    }

    int data, pos;

    scanf("%d", &data);
    head = insertBeginning(head, data);

    scanf("%d", &data);
    head = insertEnd(head, data);

    scanf("%d %d", &pos, &data);
    head = insertPosition(head, data, pos);

    display(head);

    return 0;
}