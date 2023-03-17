#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
}

int isBalanced(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int main() {
    // create a binary tree
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 3;
    root->right->left = (struct Node*)malloc(sizeof(struct Node));
    root->right->left->data = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = NULL;

    // check if the binary tree is balanced
    if (isBalanced(root)) {
        printf("The binary tree is balanced.\n");
    }
    else {
        printf("The binary tree is not balanced.\n");
    }

    return 0;
}
