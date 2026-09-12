// Bharath is very good at numbers. 
// As he is piled up with many works, he decides to develop programs for a few concepts to simplify his work.
// As a first step, he tries to arrange even and odd numbers using a linked list. He stores his values in a singly-linked list. 
// Now he has to write a program such that all the even numbers appear before the odd numbers. 
// Finally, the list is printed in such a way that all even numbers come before odd numbers. 
// Additionally, the even numbers should be in reverse order, while the odd numbers should maintain their original order. 

// Explanation:

// Even elements: 0 4 30 12

// Reversed Even elements: 12 30 4 0

// Odd elements: 3 1

// So the final list becomes: 12 30 4 0 3 1

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    int n;
    scanf("%d",&n);
    struct node *head =NULL;
    struct node *p = NULL;
    for(int i=0;i<n;i++){
        struct node *n1 = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&n1->data);
        n1->next=NULL;
        if(head == NULL){
            head = n1;
            p=n1;
        }else{
            p->next = n1;
            p=n1;
        }
    }
    struct node *odd = NULL;
    struct node *oddp = NULL;
    struct node *even = NULL;
    struct node *evenp = NULL;
    p=head;
    while(p!=NULL){
        if(p->data %2 != 0){
            struct node *n2 = (struct node*)malloc(sizeof(struct node));
            n2->data = p->data;
            n2->next = NULL;
            if(odd == NULL){
                odd = n2;
                oddp = n2;
            }else{
                oddp->next = n2;
                oddp=n2;
            }
        }else{
            struct node *n3 = (struct node*)malloc(sizeof(struct node));
            n3->data = p->data;
            n3->next = NULL;
            if(even == NULL){
                even = n3;
            }else{
                n3->next = even;
                even=n3;
            }
        }
        p=p->next;
    }
    if(even == NULL){
        even = odd;
    }else{
        evenp = even;
        while(evenp->next!= NULL){
            evenp=evenp->next;
        }
        evenp->next = odd;
    }
    p=even;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}