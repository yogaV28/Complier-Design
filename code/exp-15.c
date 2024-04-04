#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Heap
{
    int data;
    struct Heap *next;
} node;

node *create();
void display(node *);
node *search(node *,int);
node *insert(node *);
void dele(node **);

int main()
{
    int choice,val;
    char ans;
    node *head = NULL;

    do
    {
        printf("\nprogram to perform various operations on heap using dynamic memory management");
        printf("\n1.create");
        printf("\n2.display");
        printf("\n3.insert an element in a list");
        printf("\n4.delete an element from list");
        printf("\n5.quit");
        printf("\nenter your choice(1-5): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                head = create();
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = insert(head);
                break;
            case 4:
                dele(&head);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("invalid choice, try again\n");
                break;
        }
    }
    while(choice != 5);

    return 0;
}

node* create()
{
    node *temp, *New, *head;
    int val;
    char ans='y';

    temp = NULL;
    head = NULL;
    do
    {
        printf("\n enter the element: ");
        scanf("%d", &val);
        New = (node*)malloc(sizeof(node));
        if(New == NULL)
        {
            printf("\nMemory is not allocated\n");
            return NULL;
        }
        New->data = val;
        New->next = NULL;

        if(head == NULL)
        {
            head = New;
            temp = head;
        }
        else
        {
            temp->next = New;
            temp = New;
        }

        printf("\nDo you want to enter more elements? (y/n): ");
        scanf(" %c", &ans);
    }
    while(ans == 'y' || ans == 'Y');

    printf("\nThe list is created\n");
    return head;
}

void display(node *head)
{
    node *temp;
    temp = head;

    if(temp == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node *search(node *head, int key)
{
    node *temp;
    temp = head;

    if(temp == NULL)
    {
        printf("The linked list is empty\n");
        return NULL;
    }

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("\nThe element is present in the list\n");
            return temp;
        }
        temp = temp->next;
    }

    printf("The element is not present in the list\n");
    return NULL;
}

node *insert(node *head)
{
    int choice;
    node *insert_head(node *);
    void insert_last(node *);
    void insert_after(node *);

    printf("\n1. Insert a node as a head node");
    printf("\n2. Insert a node as the last node");
    printf("\n3. Insert a node at an intermediate position in the list");
    printf("\nEnter your choice for insertion of node: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            head = insert_head(head);
            break;
        case 2:
            insert_last(head);
            break;
        case 3:
            insert_after(head);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return head;
}

node *insert_head(node *head)
{
    node *New, *temp;
    int val;

    New = (node*)malloc(sizeof(node));
    if(New == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    printf("\nEnter the element which you want to insert: ");
    scanf("%d", &val);

    New->data = val;
    New->next = head;
    head = New;

    return head;
}

void insert_last(node *head)
{
    node *New, *temp;
    int val;

    New = (node*)malloc(sizeof(node));
    if(New == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter the element which you want to insert: ");
    scanf("%d", &val);

    New->data = val;
    New->next = NULL;

    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = New;
}

void insert_after(node *head)
{
    int key;
    node *New, *temp;
    New = (node*)malloc(sizeof(node));

    if(New == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter the element which you want to insert: ");
    scanf("%d", &New->data);

    printf("\nEnter the element after which you want to insert the node: ");
    scanf("%d", &key);

    temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            New->next = temp->next;
            temp->next = New;
            return;
        }
        temp = temp->next;
    }

    printf("Element %d not found in the list\n", key);
}

void dele(node **head)
{
    node *temp, *prev;
    int key;

    temp = *head;

    if(temp == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }

    printf("\nEnter the element you want to delete: ");
    scanf("%d", &key);

    temp = search(*head, key);

    if(temp != NULL)
    {
        prev = *head;
        if(prev == temp)
        {
            *head = temp->next;
            free(temp);
            printf("\nThe element is deleted\n");
            return;
        }

        while(prev->next != temp)
        {
            prev = prev->next;
        }

        prev->next = temp->next;
        free(temp);
        printf("\nThe element is deleted\n");
    }
}
