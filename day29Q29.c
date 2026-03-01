#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, k, i, val;
    scanf("%d", &n);

    if (n == 0) return 0;

    struct Node *head = NULL, *temp = NULL, *tail = NULL;

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);
    k = k % n;

    if (k == 0) {
        temp = head;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    tail->next = head;

    int steps = n - k;
    temp = head;
    for (i = 1; i < steps; i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}