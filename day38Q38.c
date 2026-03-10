#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void push_front(int x){
    if(front == 0){
        printf("Overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    }else{
        front--;
    }
    deque[front] = x;
}

void push_back(int x){
    if(rear == MAX-1){
        printf("Overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    }else{
        rear++;
    }
    deque[rear] = x;
}

void pop_front(){
    if(front == -1){
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);
    if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
}

void pop_back(){
    if(front == -1){
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);
    if(front == rear){
        front = rear = -1;
    }else{
        rear--;
    }
}

void show_front(){
    if(front == -1) printf("-1\n");
    else printf("%d\n", deque[front]);
}

void show_back(){
    if(front == -1) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

void size(){
    if(front == -1) printf("0\n");
    else printf("%d\n", rear-front+1);
}

void empty(){
    if(front == -1) printf("True\n");
    else printf("False\n");
}

int main(){
    int n,x;
    char op[20];
    scanf("%d",&n);
    while(n--){
        scanf("%s",op);
        if(strcmp(op,"push_front")==0){
            scanf("%d",&x);
            push_front(x);
        }else if(strcmp(op,"push_back")==0){
            scanf("%d",&x);
            push_back(x);
        }else if(strcmp(op,"pop_front")==0){
            pop_front();
        }else if(strcmp(op,"pop_back")==0){
            pop_back();
        }else if(strcmp(op,"front")==0){
            show_front();
        }else if(strcmp(op,"back")==0){
            show_back();
        }else if(strcmp(op,"size")==0){
            size();
        }else if(strcmp(op,"empty")==0){
            empty();
        }
    }
}