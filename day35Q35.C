#include <stdio.h>
#define MAX 100

int main()
{
    int queue[MAX];
    int front = -1, rear = -1;
    int n, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if(rear == MAX - 1)
            break;
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
    }

    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}