#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* build(int inorder[], int postorder[], int start, int end, int* index) {
    if (start > end) return NULL;

    struct Node* root = newNode(postorder[*index]);
    (*index)--;

    if (start == end) return root;

    int pos = search(inorder, start, end, root->data);

    root->right = build(inorder, postorder, pos + 1, end, index);
    root->left = build(inorder, postorder, start, pos - 1, index);

    return root;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int* inorder = (int*)malloc(n * sizeof(int));
    int* postorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int index = n - 1;
    struct Node* root = build(inorder, postorder, 0, n - 1, &index);

    preorder(root);

    return 0;
}