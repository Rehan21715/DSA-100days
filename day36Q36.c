#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n,m,i,x;
    struct node *front=NULL,*rear=NULL,*temp,*newnode;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;

        if(front==NULL)
        {
            front=rear=newnode;
            newnode->next=front;
        }
        else
        {
            newnode->next=front;
            rear->next=newnode;
            rear=newnode;
        }
    }

    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        if(front!=NULL)
        {
            temp=front;
            front=front->next;
            rear->next=front;
            free(temp);
        }
    }

    temp=front;
    if(temp!=NULL)
    {
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=front);
    }

    return 0;
}