#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int countNodes(struct Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

int sumKeys(struct Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return sumKeys(root->left) + sumKeys(root->right) + root->data;
    }
}

int maxKey(struct Node* root){
    if(root == NULL){
        return -1;
    }
    else{
        int leftMax = maxKey(root->left);
        int rightMax = maxKey(root->right);
        int currentMax = root->data;
        if(leftMax > currentMax){
            currentMax = leftMax;
        }
        if(rightMax > currentMax){
            currentMax = rightMax;
        }
        return currentMax;
    }
}

int main(){
    // Create a binary tree
    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node*) malloc(sizeof(struct Node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct Node*) malloc(sizeof(struct Node));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    // Test the functions
    printf("Number of nodes: %d\n", countNodes(root));
    printf("Sum of keys: %d\n", sumKeys(root));
    printf("Maximum key: %d\n", maxKey(root));

    return 0;
}
