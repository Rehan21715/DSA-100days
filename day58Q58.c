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

struct Node* build(int preorder[], int inorder[], int start, int end, int* index) {
    if (start > end) return NULL;

    struct Node* root = newNode(preorder[*index]);
    (*index)++;

    if (start == end) return root;

    int pos = search(inorder, start, end, root->data);

    root->left = build(preorder, inorder, start, pos - 1, index);
    root->right = build(preorder, inorder, pos + 1, end, index);

    return root;
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int* preorder = (int*)malloc(n * sizeof(int));
    int* inorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int index = 0;
    struct Node* root = build(preorder, inorder, 0, n - 1, &index);

    postorder(root);

    return 0;
}