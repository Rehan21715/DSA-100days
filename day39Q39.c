#include <stdio.h>

int heap[1000];
int size = 0;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x){
    heap[size] = x;
    int i = size;
    size++;

    while(i > 0){
        int parent = (i - 1) / 2;
        if(heap[parent] > heap[i]){
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

int extractMin(){
    if(size <= 0) return -1;

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    int i = 0;

    while(1){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i){
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }

    return root;
}

int peek(){
    if(size <= 0) return -1;
    return heap[0];
}

int main(){
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(op[0] == 'i'){
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'e'){
            printf("%d\n", extractMin());
        }
        else if(op[0] == 'p'){
            printf("%d\n", peek());
        }
    }

    return 0;
}