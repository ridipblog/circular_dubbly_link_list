#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node * prev;
    int data;
    struct Node * next;
};
struct Node * create_ll(struct Node * start)
{
    struct Node * new_node,* ptr;
    int data;
    printf("\nEnter _1 to end");
    printf("\nEnter Data");
    scanf("%d",&data);
    while(data!=-1)
    {
        if(start==NULL)
        {
            new_node=(struct Node *)malloc(sizeof(struct Node));
            new_node->prev=NULL;
            new_node->data=data;
            new_node->next=new_node;
            start=new_node;
        }
        else
        {
            ptr=start;
            new_node=(struct Node *)malloc(sizeof(struct Node));
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->data=data;
            new_node->next=start;
            start->prev=new_node;
        }
        printf("\nEnter Data ");
        scanf("%d",&data);
    }
    return start;
}
struct Node * insert_beg(struct Node * start)
{
    struct Node * new_node,*ptr;
    int data;
    if(start==NULL)
    {
        start=create_ll(start);
    }
    else
    {
        printf("\nEnter Data");
        scanf("%d",&data);
        new_node=(struct Node *)malloc(sizeof(struct Node));
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->prev=ptr;
        new_node->next=start;
        start->prev=new_node;
        new_node->data=data;
        start=new_node;
    }
    return start;
};
struct Node * insert_end(struct Node * start)
{
    struct Node * new_node,*ptr;
    int data;
    if(start==NULL)
    {
        start=create_ll(start);
    }
    else
    {
        printf("\nEnter Data");
        scanf("%d",&data);
        new_node=(struct Node *)malloc(sizeof(struct Node));
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->prev=ptr;
        new_node->next=start;
        start->prev=new_node;
        new_node->data=data;
    }
    return start;
};
struct Node * insert_at_index(struct Node * start)
{
    struct Node * new_node,*ptr,*p;
    int index,data;
    if(start==NULL)
    {
        start=create_ll(start);
    }
    else
    {
        printf("\n Enter Index Number ");
        scanf("%d",&index);
        printf("\nEnter Data ");
        scanf("%d",&data);
        new_node=(struct Node *)malloc(sizeof(struct Node));
        int i=0;
        ptr=start;
        while(i!=index-1)
        {
            ptr=ptr->next;
            i++;
        }
        p=ptr->prev;
        ptr->prev=new_node;
        new_node->next=ptr;
        new_node->prev=p;
        p->next=new_node;
        new_node->data=data;
        if(index==1)
            start=new_node;
    }
    return start;
};
struct Node * delete_beg(struct Node * start)
{
    struct Node * ptr;
    if(start==NULL)
    {
        start=create_ll(start);
    }
    else
    {
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        if(ptr==start)
        {
            free(start);
            start=NULL;
        }
        else
        {
            start->next->prev=ptr;
            ptr->next=start->next;
            free(start);
            start=ptr->next;
        }
    }
    return start;
};
struct Node * delete_end(struct Node * start)
{
    struct Node * ptr;
    if(start==NULL)
    {
        start=create_ll(start);
    }
    else
    {
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        if(ptr==start)
        {
            free(start);
            start=NULL;
        }
        else
        {
            ptr->prev->next=start;
            start->prev=ptr->prev;
            free(ptr);
        }
    }
    return start;
};
struct Node * delete_at_index(struct Node * start)
{
    struct Node * ptr;
    int index;
    printf("\nEnter Index Number ");
    scanf("%d",&index);
    if(start==NULL)
    {
        start=create_ll(start);
    }
    else
    {
        if(start->next==start)
        {
            free(start);
            start=NULL;
        }
        else
        {
            int i=0;
            ptr=start;
            while(i!=index-1)
            {
                ptr=ptr->next;
                i++;
            }
            ptr->next->prev=ptr->prev;
            ptr->prev->next=ptr->next;
            if(index==1)
                start=ptr->next;
            free(ptr);
        }
    }
    return start;
};
struct Node * delete_list(struct Node *start)
{
    struct Node * ptr;
    if(start==NULL)
    {
        start=create_ll(start);
    }
    else
    {
        do
        {
            start=delete_end(start);
        }while(start!=NULL);
    }
    return start;
};
void display(struct Node * start)
{
    struct Node * ptr;
    if(start==NULL)
    {
        printf("\nFirst Create List");
    }
    else
    {
        ptr=start;
        do
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }while(ptr!=start);
    }
}
int main()
{
    struct Node *start=NULL;
    int option;

    while(1)
    {
        printf("\nChoose Option ");
        printf("\n1 for display ");
        printf("\n2 for create List ");
        printf("\n3 for insert first");
        printf("\n4 for insert end");
        printf("\n5 for insert at index");
        printf("\n6 for delete begen");
        printf("\n7 for delete end");
        printf("\n8 for delete at index");
        printf("\n9 for delete list");
        printf("\n12 for exit ");
        scanf("%d",&option);
        if(option==1)
        {
            display(start);
        }
        else if(option==2)
        {
            start=create_ll(start);
        }
        else if(option==3)
        {
            start=insert_beg(start);
        }
        else if(option==4)
        {
            start=insert_end(start);
        }
        else if(option==5)
        {
            start=insert_at_index(start);
        }
        else if(option==6)
        {
            start=delete_beg(start);
        }
        else if(option==7)
        {
            start=delete_end(start);
        }
        else if(option==8)
        {
            start=delete_at_index(start);
        }
        else if(option==9)
        {
            start=delete_list(start);
        }
        else if(option==12)
        {
            break;
        }
        else
        {
            printf("\nWrong Choose");
        }
    }
    return 0;
}
