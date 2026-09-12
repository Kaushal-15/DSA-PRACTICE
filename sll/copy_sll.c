#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    int n;

    scanf("%d", &n);

    struct node *head = NULL;
    struct node *p = NULL;

    struct node *head1 = NULL;
    struct node *temp = NULL;

    for (int i = 0; i < n; i++) {

        struct node *n1 = malloc(sizeof(struct node));

        scanf("%d", &n1->data);

        n1->next = NULL;

        if (head == NULL) {
            head = n1;
            p = n1;
        } else {
            p->next = n1;
            p = n1;
        }
    }

    p = head;

    while (p != NULL) {

        struct node *n2 = malloc(sizeof(struct node));

        n2->data = p->data;
        n2->next = NULL;

        if (head1 == NULL) {
            head1 = n2;
            temp = n2;
        } else {
            temp->next = n2;
            temp = n2;
        }

        p = p->next;
    }

    printf("\n");

    printf("First list\n");

    p = head;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");

    printf("Copy of the list\n");

    temp = head1;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}