#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

int main(){
    int n;
    scanf("%d",&n);

    struct node *head = NULL;
    struct node *p = NULL;
    for(int i=0;i<n;i++){
        struct node *n1 = malloc(sizeof(struct node));
        scanf("%d",&n1->data);
        n1->prev=NULL;
        n1->next=NULL;
        if(head == NULL){
            head =n1;
            p=n1;
        }else{
            p->next = n1;
            n1->prev = p;
            p=n1;
        }
    }

    p=head;
    int max = p->data;
    int currmax = p->data;
    while(p->next!=NULL){
        if(p->data > currmax){
            currmax = p->data;
        }
        p=p->next;
    }
    printf("%d",currmax);
}

