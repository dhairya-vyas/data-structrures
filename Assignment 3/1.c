#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Construct the tree from its preorder traversal.
TreeNode* constructTree(char pre[], int* index, int size) {
    if (*index >= size || pre[*index] == '-') {
        (*index)++;
        return NULL;
    }
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->val = pre[(*index)++];
    node->left = constructTree(pre, index, size);
    node->right = constructTree(pre, index, size);
    return node;
}

// Traverse the tree in inorder.
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%c ", root->val);
    inorderTraversal(root->right);
}

// Traverse the tree in postorder.
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->val);
}

int main() {
    char pre[] = {'A', 'B', 'C', '-', '-', 'D', '-', '-', 'E', '-', 'F', '-', '-'};
    int size = sizeof(pre) / sizeof(pre[0]);
    int index = 0;
    TreeNode* root = NULL;
    root = constructTree(pre, &index, size);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
