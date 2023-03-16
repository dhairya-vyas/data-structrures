#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void reverseList(struct Node** head_ptr){
    struct Node *prev = NULL,*current=*head_ptr, *next_node =NULL;

    while (current !=NULL){
        next_node=current->next;
        current->next=prev;
        prev=current;
        current = next_node;
    }
    *head_ptr=prev;
}

void printlist(struct Node* head_ptr){
    while (head_ptr !=NULL){
        printf("%d",head_ptr->data);
        head_ptr=head_ptr->next;
    }
    printf("\n");
}





int main(){
    struct Node* l1=(struct Node*) malloc(sizeof(struct Node));
    l1->data=1;
    l1->next=(struct Node*) malloc(sizeof(struct Node));
    l1->next->data=2;
    l1->next->next=(struct Node*) malloc(sizeof(struct Node));
    l1->next->next->data=2;
    l1->next->next->next=(struct Node*) malloc(sizeof(struct Node));
    l1->next->next->next->data=5;
    l1->next->next->next->next=(struct Node*) malloc(sizeof(struct Node));
    l1->next->next->next->next->data=7;
    l1->next->next->next->next->next=(struct Node*) malloc(sizeof(struct Node));
    l1->next->next->next->next->next->data=9;
    l1->next->next->next->next->next->next=(struct Node*) malloc(sizeof(struct Node));
    l1->next->next->next->next->next->next->data=11;
    l1->next->next->next->next->next->next->next=NULL;

printf("Original List: ");
printlist(l1);

reverseList(&l1);

printf("Reversed List: ");
printlist(l1);
    return 0;
}
