#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node * prev;
    int data;
    struct Node * next;
};
int check=0;
struct Node * insertAtFrist(struct Node * head,int data)
{
    struct Node * new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr=head;
    if(head==NULL)
    {
        printf("\nNo Data ");
    }
    else
    {
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        new_node->data=data;
        new_node->next=head;
        ptr->next=new_node;
        new_node->prev=ptr;
        head->prev=new_node;
        head=new_node;
    }
    return head;
};
struct Node * insertAtIndexLast(struct Node * head,int data,int index)
{
    struct Node * new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr=head;
    int i=0;
    index=index-1;
    if(head==NULL)
    {
        printf("\nNO Data ");
    }
    else
    {
        while(i!=index)
        {
            i++;
            ptr=ptr->next;
        }
        new_node->data=data;
        new_node->next=ptr->next;
        ptr->next->prev=new_node;
        ptr->next=new_node;
        new_node->prev=ptr;
    }
    return head;
};
struct Node * insertAtIndexFrist(struct Node * head,int data,int index)
{
    struct Node * new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr=head;
    struct Node * temp_node;
    int i=0;
    index=index-1;
    if(head==NULL)
    {
        printf("\nNO Data");
    }
    else
    {
        if(index==0)
        {
            head=insertAtFrist(head,data);
        }
        else
        {
            while(i!=index)
            {
                i++;
                temp_node=ptr;
                ptr=ptr->next;
            }
            new_node->data=data;
            temp_node->next=new_node;
            new_node->prev=temp_node;
            new_node->next=ptr;
            ptr->prev=new_node;
        }
    }
    return head;
};
struct Node * insertAtEnd(struct Node * head,int data)
{
    struct Node * new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr=head;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        new_node->data=data;
        new_node->next=ptr->next;
        ptr->next->prev=new_node;
        ptr->next=new_node;
        new_node->prev=ptr;
    }
    return head;
};
struct Node * deleteAtFrist(struct Node * head)
{
    struct Node * ptr=head;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        printf("\nDeleted Data %d ",head->data);
        if(head->next==head)
        {
            free(head);
            head=NULL;
            check=0;
        }
        else
        {
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            head->next->prev=ptr;
            ptr->next=head->next;
            free(head);
            head=ptr->next;
        }
    }
    return head;
};
struct Node * deleteAtValue(struct Node * head,int value)
{
    struct Node * ptr=head;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        if(head->data==value)
        {
            head=deleteAtFrist(head);
        }
        else
        {
            while(ptr->data!=value)
            {
                ptr=ptr->next;
            }
            printf("\nDeleted Data %d ",ptr->data);
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(ptr);
        }
    }
    return head;
};
struct Node * deleteAtEnd(struct Node * head)
{
    struct Node * ptr=head;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        if(head->next==head)
        {
            head=deleteAtFrist(head);
        }
        else
        {
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            printf("\nDeleted Data %d ",ptr->data);
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(ptr);
        }
    }
    return head;
};
void display(struct Node * head)
{
    struct Node * ptr=head;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        do
        {
            printf("\nData %d ",ptr->data);
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void main()
{
    int choice;
    struct Node * head=NULL;
    while(1)
    {
        printf("\n1 For Insert At Frist ");
        printf("\n2 For Display Data ");
        printf("\n3 For Insert At Index Last ");
        printf("\n4 For Insert At Index Frist ");
        printf("\n5 For Insert At End ");
        printf("\n6 For Delete At Frist ");
        printf("\n7 For Delete At Value ");
        printf("\n8 For Delete At End ");
        printf("\n10 For Exit ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nEnter Data ");
            int data;
            scanf("%d",&data);
            if(check==0)
            {
                head=(struct Node *)malloc(sizeof(struct Node));
                head->prev=NULL;
                head->data=data;
                head->next=head;
                check=1;
            }
            else
            {
                head=insertAtFrist(head,data);
            }
        }
        else if(choice==2)
        {
            display(head);
        }
        else if(choice==10)
        {
            break;
        }
        else if(choice==3)
        {
            printf("\nEnter Data And Index ");
            int data,index;
            scanf("%d%d",&data,&index);
            head=insertAtIndexLast(head,data,index);
        }
        else if(choice==4)
        {
            printf("\nEnter Data And Index ");
            int data,index;
            scanf("%d%d",&data,&index);
            head=insertAtIndexFrist(head,data,index);
        }
        else if(choice==5)
        {
            printf("\nEnter Data ");
            int data;
            scanf("%d",&data);
            head=insertAtEnd(head,data);
        }
        else if(choice==6)
        {
            head=deleteAtFrist(head);
        }
        else if(choice==7)
        {
            printf("\nEnter Value For Delete ");
            int value;
            scanf("%d",&value);
            head=deleteAtValue(head,value);
        }
        else if(choice==8)
        {
            head=deleteAtEnd(head);
        }
    }
}
