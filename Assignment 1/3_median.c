#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


double getMedian(struct Node* head_ptr){
    if(head_ptr == NULL){
        return 0;
    }

    int length = 0;
   struct Node* current = head_ptr;
    while(current !=NULL){
        length++;
        current = current->next;
    }

    int middle = length/2;
    current =head_ptr;
    struct Node* prev = NULL;
    for(int i=0; i<middle;i++){
        prev=current;
        current = current ->next;
    }
    if(length%2==0){
        return (double)(prev->data + current ->data)/2;
    }else {
        return current ->data;
    }
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


double median = getMedian(l1);
printf("Median: %.2f\n", median);

    return 0;
}
