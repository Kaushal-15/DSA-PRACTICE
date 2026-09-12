// Ashwin is tasked with developing a simple application to manage a list of items in a shop inventory using a doubly linked list. Each item in the inventory has a unique identification number. The application should allow users to perform the following operations:

// Create a List of Items: Initialize the inventory with a given number of items. Each item will be assigned a unique number provided by the user and insert the elements at end of the list.

// Delete an Item: Remove an item from the inventory at a specific position.

// Display the Inventory: Show the list of items before and after deletion.

// If the position provided for deletion is invalid (e.g., out of range), it should display an error message.

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
    printf("Data entered in the list:\n");
    for(int i=0;i<n;i++){
        struct node *n1 = malloc(sizeof(struct node));
        scanf("%d",&n1->data);
        printf("node %d : %d\n",i+1,n1->data);
        n1->prev=NULL;
        n1->next=NULL;
        if(head == NULL){
            head=n1;
            p=n1;
        }else{
            p->next = n1;
            n1->prev = p;
            p=n1;
        }
    }
    int pos;
    scanf("%d",&pos);
    if(pos > n){
        printf("Invalid position. Try again.\n");
        return 0;
    }
    struct node *temp =head;
    struct node *old = head;
    struct node *s = NULL;
    if(pos == 1 ){
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }else if(pos == n){
        p=head;
        old=head;
        while(p->next!=NULL){
            old->next = NULL;
            free(p);
        }
        
    }else{
    old = head;
    s = NULL;
    p=head;
    for(int i=1;i<pos;i++){
        old=p;
        p=p->next;
    }
    s=p->next;
    old->next=s;
    s->prev=old;
    free(p);
    
    }
    p=head;
    printf("After deletion the new list:\n");
    int idx=1;
    while(p!=NULL){
        printf("node %d : %d\n",idx,p->data);
        p=p->next;
        idx++;
    }
    return 0;
}