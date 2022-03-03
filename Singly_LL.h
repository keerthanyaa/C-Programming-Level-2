#include <stdio.h>
#include <stdlib.h>

/*
functions in the created header file -

void insertNewnode(struct node * head)
void insertLast(struct node* head)
void insertAtPos(struct node * head, int pos) // 2arguments
void delBeg(struct node *head)
void delLast(struct node* head)
void delAtPos(struct node* head, int pos)
void Traverse(struct node* head)
void Peek(struct node* head)

*/

struct node
{
    int data;
    struct node * next;
};

struct node *head;

//TO INSERT NODES
void insertNewnode(struct node * head)
{
    struct node* newnode;
    struct node* temp;

    newnode=(struct node *)malloc(sizeof (struct node));

    if (newnode!=NULL)
    {
        int data ;
        printf("Enter the data for new node (integer) :"); // Take data input
        scanf("%d",&data);

        if (head == NULL) //No node initially present
        {
            newnode->data=data;
            newnode->next=NULL;
            head=newnode;
        }
            
        else // some node is present
        {
            newnode->data=data; 
            temp=head;
            head=newnode;
            newnode->next=temp;
        }       
    }
    else
        printf("Unable to add new node !");
}

void insertLast(struct node* head)
{
    struct node* newnode;
    struct node* temp;

    newnode=(struct node *)malloc(sizeof(struct node));

    if (newnode!=NULL)
    {
        int data ;
        printf("Enter the data for new node (integer) :"); // Take data input
        scanf("%d",&data);

        if(head==NULL)
        {
            printf("No node present! Inserting node as first node ");
            newnode->data=data;
            newnode->next=NULL;
            head=newnode;
        }

        else if(head->next==NULL) // LL has only one node
        {
            newnode->data=data;
            head->next=newnode;
            newnode->next=NULL;
        }

        else
        {
            struct node* temp;
            temp=head;
            while(temp!=NULL) // Traverse through the Singly LL using while loop
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->data=data;
            newnode->next=NULL;
        }

    }
    else
        printf("Unable to add new node !");

}

void insertAtPos(struct node * head, int pos) // 2arguments
{
    struct node* newnode;
    struct node* temp;

    newnode=(struct node *)malloc(sizeof(struct node ));

    if (newnode!=NULL)
    {
        int i=0,count=0;
        struct node* temp=head;
        int data ;

        

        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }

        if(pos>count)
        {
            printf("\nCannot insert at specified position\n(position entered , greater than number of nodes in SLL)");
        }

        else if (pos>=0 && pos<=count)
        {
            printf("Enter the data for new node (integer) :"); // Take data input
            scanf("%d",&data);
            newnode->data=data;

            temp=head;
            struct node*temp2; // another pointer for the node at the position , already existing

            for(i;i<pos;i++)
            {
                temp=temp->next;
            }
            
            if(temp->next==NULL)// reached last position
            {
                temp->next=newnode;
                newnode->next=NULL;
            }
            else
            {
                temp2=temp->next;
                temp->next=newnode;
                newnode->next=temp2;
            }
        }
        else
        {
            printf("\nUnable to insert at the position. Position , invalid!!");
        }
    }
    else
        printf("Unable to add new node !");
}

//TO DELETE NODES
void delBeg(struct node *head)
{
    if(head==NULL) //Empty List
    {
        printf("\nEmpty LIST !! Cannot delete any Node");
    }

    else if(head->next==NULL) //Only one node in list
    {
        struct node * temp;
        temp=head;
        head=NULL;
        free(temp);
    }

    else
    {
        struct node* temp;
        temp=head;
        head=temp->next;
        free(temp);
    }
}

void delLast(struct node* head)
{
    if(head==NULL) //Empty List
    {
        printf("\nEmpty LIST !! Cannot delete any Node");
    }

    else if(head->next==NULL)
    {
        struct node * temp;
        temp=head;
        head=NULL;
        free(temp);
    }

    else
    {
        struct node* temp ,*temp2;
        temp2=head;
        temp=head->next;

        while(temp->next!=NULL)
        {
            temp2=temp2->next;
            temp=temp->next;
        } // temp points to the last node by the time while loop is done
        //temp2 points, at 1 , but last node

        temp2->next=NULL;
        free(temp);       
    }
    
}

void delAtPos(struct node* head, int pos)
{
    struct node* temp=head;
    int count=0;

        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }

        if(pos>count)
        {
            printf("\nCannot delete at specified position\n(position entered , greater than number of nodes in SLL)");
        }

        else
        {
            
            temp=head;
            struct node*temp2; // another pointer for the node at the position , already existing

            for(int i=0;i<pos;i++)
            {
                temp=temp->next;
            }
            temp2=temp->next->next;
            temp->next=temp2;
            temp=temp->next;
            free(temp);  
        }
}

void Traverse(struct node * head)
{
    if (head==NULL)
    {
        printf("\nEmpty List !!");
    }
    else
    {
        printf("\nTraversing the list ...");
        struct node* temp;
        temp=head;
        while(temp!=NULL)
        {
            printf("\n%d ",&temp->data);
            temp=temp->next;
        }
    }
}

void Peek(struct node * head)
{
    if (head==NULL)
    {
        printf("\nEmpty List !! Cannot Peek");
    }
    else
    {
        printf("\nHead val - %d", &head->data);
    }
}

/*
int main()
{
    printf("\nSINGLY LINKED LIST -");
    return 0;
}
*/
