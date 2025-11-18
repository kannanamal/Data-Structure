#include<stdio.h>
#define MAX 5
int arr[MAX];
int top=-1;

void push(int value)
{
    if(top==MAX-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        arr[top]=value;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The poped element is %d\t",arr[top]);
        top--;
    }
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    int val,option;
            do
            {
                /* code */
                printf("MENU\n");
                printf("1: Push\n");
                printf("2: pop\n");
                printf("3: Display\n");
                printf("Enter your choice:-");
                scanf("%d",&option);
                switch(option)
                {
                    case 1:
                        printf("Enter the value to push");
                        scanf("%d",&val);
                        push(val);
                        break;
                    case 2:
                        pop();
                         break;  
                    case 3:
                        display();
                        break;  
                    defaulf:
                        break;        
                }
            }
             while (option==1||option==2||option==3);
        }
