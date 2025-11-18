#include <stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int value)
{
    if(rear==N-1)
    {
        printf("Queue OverFlow");
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=value;
    }
    else
    {
        rear++;
        queue[rear]=value;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Underflow");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf("The dequeued element is %d\n",queue[front]);
        front++;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        for(int i=front;i<rear+1;i++)
        {
            printf("%d\t",queue[i]\n);
        }
    }
}

int main()
{
    int option;
    int value;
    char ch;
    do
    {
        printf("-------Queue Implementation---------\n");
        printf("Insert a value(enqueue)\n");
        printf("Delete a value(dequeue)\n");
        printf("display\n");
        printf("Choose The option\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("Enter a value");
                    scanf("%d",&value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    printf("dequeue is Successfull\n");
                    break;
            case 3: display();
                    break; 

            default: printf("Invalid input!!!!");
                     break;                              
        }
        printf("Do you want to continue(Y/N)");
        scanf(" %c",&ch);
    }while((ch=='Y')||(ch=='y'));
}