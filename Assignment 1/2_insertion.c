#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertInOrder(struct Node** head_ptr,int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data= value;
    newNode->next=NULL;

    if(*head_ptr == NULL) {
        *head_ptr = newNode;
        return;
    }

    if (value<(*head_ptr)->data){
        newNode->next=*head_ptr;
        *head_ptr=newNode;
        return;
    }

    struct Node* curr=*head_ptr;
    while(curr->next != NULL && curr->next->data<value){
        curr=curr->next;
    }
    
    newNode->next=curr->next;
    curr->next=newNode;
}

int main(){
    struct Node* l1=(struct Node*) malloc(sizeof(struct Node));
    l1->data=3;
    l1->next=(struct Node*) malloc(sizeof(struct Node));
    l1->next->data=17;
    l1->next->next=(struct Node*) malloc(sizeof(struct Node));
    l1->next->next->data=18;
    l1->next->next->next=(struct Node*) malloc(sizeof(struct Node));
    l1->next->next->next->data=27;
    l1->next->next->next->next=NULL;

    insertInOrder(&l1,20);

    struct Node* curr=l1;
    while (curr !=NULL){
        printf("%d ->",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");

    return 0;
}
