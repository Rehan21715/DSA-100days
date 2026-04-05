#include <stdio.h>
#include <stdlib.h>

int visited[100];

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[100];

int queue[100], front = 0, rear = 0;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int s) {
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                enqueue(temp->data);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, u, v, s;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    scanf("%d", &s);
    bfs(s);

    return 0;
}