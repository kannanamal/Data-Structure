#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *last=NULL;
struct node *createNode(int data)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    //return newNode;
}
int len()
{
    int length=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next; 
    }
    printf("%d\n",length);
    return length;

}
struct node *createList(int data)
{
    struct node *newNode=createNode(data);
    if(head==NULL)
    {
        head=last=newNode;
    }
    else
    {
        last->next=newNode;
        newNode->prev=last;
        last=newNode;
    }
    return head;
    return last;
}
void insertAtBeginning(int data)
{
    struct node *newNode=createNode(data);
    if (head==NULL)
    {
       head=newNode;
       return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
void insertAtEnd(int data)
{
    struct node *newNode=createNode(data);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    last->next=newNode;
    newNode->prev=last;
    last=newNode;
    printf("Inserted at end successfully..\n");
}
void insertAtpos(int pos,int data)
{
    struct node *temp=head;
    struct node  *newNode=createNode(data);
    if((pos<1) || pos>len()+1)
    {
        printf("Operation cannot be perform\n");
        return;
    } 
    else if(pos==1)
    {
        insertAtBeginning(data);
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->next->prev=newNode;
        printf("operation done successfully\n");
    }
}   
void insertAfterPos(int pos,int data)
{ 
   struct node *temp=head;
   struct node *newNode=createNode(data);
    if((pos<1) || pos>len())
    {
        printf("Operation cannot be perform\n");
        
    } 
    else
    {
        for(int i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->next->prev=newNode;
        printf("operation done successfully\n");
    }

}
void deleteFromBeg()
{
   struct node *temp=head;
   if(head==NULL)
   {
    printf("List is empty");
    return;
   }
   head=temp->next;
   head->prev=NULL;
   free(temp);
   printf("Deletion is excecuted succesfully....\n");   
}
void deleteEnd()
{   
    if(last==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp=last;
    temp->prev->next=0;
    last=temp;
    free(temp);
    printf("Deleted successfully...\n");
}
void deletefromPos(int pos)
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Operation cannot perform..\n");
    }
    else if(pos<1 || pos>len())
    {
        printf("Invalid position value inserted\n");        
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        printf("Operation done successfully\n");
    }
    
}
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d<-->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}


int main()
{   
    int pos;
    char ch='Y';
    int value;
    int n;
    int option;
    do
    {
        printf("1 create\n");
        printf("2 Display\n");
        printf("3 Inserting data at the beginning\n");
        printf("4 Insert at the end\n");
        printf("5 Insert at position\n");
        printf("6 Lenghh of the list\n");
        printf("7 Insert after the positon\n");
        printf("8 Delete from beginning\n");
        printf("9 Delete at end\n");
        printf("10 Delete at particular position\n");
        printf("enter your choise:");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("Enter The number of node:");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                printf("Enter the node value",i);
                scanf("%d",&value);
                createList(value);
            }
            break;
        case 2:
            printf("the list are.....\n");
            display();
            break;
        case 3:
            printf("Enter the data");
            scanf("%d",&value);
            insertAtBeginning(value);
            printf("Node is inserted at beginning... Successfully\n");
            break;
        case 4:
            printf("Enter the data");
            scanf("%d",&value);
            insertAtEnd(value);
            break;   
        case 5:    
            printf("Enter the postion\n");
            scanf("%d",&pos);
            printf("Enter the data\n");
            scanf("%d",&value);
            insertAtpos(pos,value);
            break;
        case 6:
            len();
            break;   
        case 7:
            printf("Enter the postion for inserting after \n");
            scanf("%d",&pos);
            printf("Enter the data\n");
            scanf("%d",&value);
            insertAfterPos(pos,value);
            break;
        case 8:
            deleteFromBeg();
            break;
        case 9:
            deleteEnd();
            break;
        case 10:
            printf("Enter the position to delete\n");
            scanf("%d",&pos);
            deletefromPos(pos);
            break;
        default:
            break;
        }
        printf("Do you want to continue(Y/N)");
        scanf(" %c",&ch);
    }while ((ch=='Y')||(ch=='y'));
    
}
