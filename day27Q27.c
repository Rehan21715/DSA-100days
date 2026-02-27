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
    int n, m, i, val;
    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL, *tail1 = NULL, *tail2 = NULL;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if(head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if(head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    struct Node* ptr1 = head1;
    struct Node* intersection = NULL;

    while(ptr1 != NULL) {
        struct Node* ptr2 = head2;
        while(ptr2 != NULL) {
            if(ptr1->data == ptr2->data) {
                intersection = ptr1;
                break;
            }
            ptr2 = ptr2->next;
        }
        if(intersection != NULL)
            break;
        ptr1 = ptr1->next;
    }

    if(intersection != NULL)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}