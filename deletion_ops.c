// Create a doubly linked list and perform deletion at the beginning, end, and a specific position using functions.

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* insertEnd(struct node *head, int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    struct node *p = head;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL){
        return newNode;
    }

    while(p->next != NULL){
        p = p->next;
    }

    p->next = newNode;
    newNode->prev = p;

    return head;
}

struct node* deleteBeginning(struct node *head)
{
    if(head == NULL){
        return NULL;
    }

    struct node *p = head;

    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    }

    free(p);

    return head;
}

struct node* deleteEnd(struct node *head)
{
    if(head == NULL){
        return NULL;
    }

    struct node *p = head;

    while(p->next != NULL){
        p = p->next;
    }

    if(p->prev == NULL){
        free(p);
        return NULL;
    }

    p->prev->next = NULL;

    free(p);

    return head;
}

struct node* deletePosition(struct node *head, int pos)
{
    if(head == NULL){
        return NULL;
    }

    if(pos == 1){
        struct node *p = head;

        head = head->next;

        if(head != NULL){
            head->prev = NULL;
        }

        free(p);

        return head;
    }

    struct node *p = head;

    for(int i = 1; i < pos && p != NULL; i++){
        p = p->next;
    }

    if(p == NULL){
        return head;
    }

    p->prev->next = p->next;

    if(p->next != NULL){
        p->next->prev = p->prev;
    }

    free(p);

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

    int pos;

    head = deleteBeginning(head);

    head = deleteEnd(head);

    scanf("%d", &pos);
    head = deletePosition(head, pos);

    display(head);

    return 0;
}