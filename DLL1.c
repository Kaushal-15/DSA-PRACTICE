#include <stdlib.h>
#include <stdio.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

int main()
{
    int n;
    scanf("%d",&n);
    
    struct node *head = NULL;
    struct node *p = NULL;
    
    for(int i = 0; i < n; i++){
        struct node *n1 = malloc(sizeof(struct node));
        
        scanf("%d",&n1->data);
        
        n1->prev = NULL;
        n1->next = NULL;
        
        if(head == NULL){
            head = n1;
            p = n1;
        }else{
            p->next = n1;
            n1->prev = p;
            p = n1;
        }
    }
   p =head;
   struct node *p1 = head;
   while(p->next!=NULL){
      p=p->next; 
   }
   
   while(p!=p1 && p->prev != p1){
       if(p->data != p1->data){
           printf("Not Palindrome");
           return 0;
       }
       p=p->prev;
       p1=p1->next;
   }
   printf("Palindrome");
   return 0 ;
}