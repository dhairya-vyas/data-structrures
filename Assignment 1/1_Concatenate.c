#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void concatenate(struct Node** h1,struct Node* h2) {
    if (*h1 == NULL){
        *h1=h2;
        return;
    }

    struct Node* curr=*h1;
    while(curr->next!=NULL){
        curr = curr->next;
    }

while(h2!=NULL){
    struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=h2->data;
    newNode->next=NULL;

    curr->next=newNode;
    curr=curr->next;

    h2=h2->next;
}

}

int main() {
 
    struct Node* l1 = (struct Node*) malloc(sizeof(struct Node));
    l1->data = 2;
    l1->next = (struct Node*) malloc(sizeof(struct Node));
    l1->next->data = 3;
    l1->next->next = (struct Node*) malloc(sizeof(struct Node));
    l1->next->next->data = 1;
    l1->next->next->next = NULL;

   
    struct Node* l2 = (struct Node*) malloc(sizeof(struct Node));
    l2->data = 4;
    l2->next = (struct Node*) malloc(sizeof(struct Node));
    l2->next->data = 5;
    l2->next->next = NULL;

    // concatenate l1 and l2
    concatenate(&l1, l2);

    
    struct Node* curr = l1;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");

    return 0;
}
