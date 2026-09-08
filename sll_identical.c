// Check whether two singly linked lists are identical

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

    printf("Next data\n");

    int n1 = n;

    struct node *head1 = NULL;
    struct node *p1 = NULL;

    for (int i = 0; i < n1; i++) {

        struct node *n2 = malloc(sizeof(struct node));

        scanf("%d", &n2->data);

        n2->next = NULL;

        if (head1 == NULL) {

            head1 = n2;
            p1 = n2;

        } else {

            p1->next = n2;
            p1 = n2;
        }
    }

    p = head;
    p1 = head1;

    while (p != NULL && p1 != NULL) {

        if (p->data != p1->data) {

            printf("The list is not identical");
            return 0;
        }

        p = p->next;
        p1 = p1->next;
    }

    if (p == NULL && p1 == NULL)
        printf("The list is identical");
    else
        printf("The list is not identical");

    return 0;
}