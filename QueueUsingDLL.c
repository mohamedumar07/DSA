#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Node
{
    struct Node *before;
    int data;
    struct Node *after;
}Node;
Node *front = NULL;
Node *rear = NULL;
int count = 0;

int isFull()
{
    if(count == SIZE)
    {
        printf("Queue is full\n");
        return 1;
    }
    else{
        printf("Queue is not full\n");
        return 0;
    }
}

int isEmpty()
{
    if(front == NULL)
    {
        printf("\nQueue is empty\n");
        return 1;
    }
    else
    {
        printf("Queue is not empty\n");
        return 0;
    }
}

void enqueue()
{
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Error in allocating memory for insertion\n");
    }
    else{
        if(isFull())
        {
        }
        else
        {
            printf("Inserting element in the queue\n");
            int data;
            printf("Enter the data to insert in the queue: ");
            scanf("%d", &data);
            newNode->data = data;
            if(front == NULL)
            {
                newNode->before = NULL;
                newNode->after = NULL;
                front = newNode;
                rear = newNode;
            }
            else{
                rear -> after = newNode;
                newNode -> before = rear;
                newNode -> after = NULL;
                rear = newNode;
            }
            count++;
        }
    }

}

void dequeue()
{
    if(isEmpty())
    {
    }
    else
    {
        printf("%d is deleted from the queue\n", front->data);
        if(front->before == NULL && front -> after == NULL)
        {
            free(front);
            front = NULL;
        }
        else{
            Node *temp = front;
            front = temp->after;
            front->before = NULL;
            free(temp);
        }
    }
}

void search()
{
    if(isEmpty())
    {
    }
    else{
        Node *temp = front;
        int value, flag = 0, count = 0;
        printf("Enter a value to be searched in the queue: ");
        scanf("%d", &value);
        while(count != SIZE)
        {
            if(temp->data == value)
            {
                flag = 1;
                break;
            }
            temp = temp -> after;
            count++;
        }
        if(flag == 1)
        {
            printf("Element is found at position %d\n", (count+1));
        }
        else{
            printf("Element is not in the queue.\n");
        }
    }
}

void display()
{
    if(isEmpty())
    {
    }
    else{
        Node *frontTemp = front;
        while(frontTemp -> after != NULL)
        {
            printf("Before: %p\n", frontTemp->before);
            printf("Data: %d\n", frontTemp -> data);
            printf("After: %p\n", frontTemp->after);
            frontTemp = frontTemp -> after;
        }
        printf("Before: %p\n", frontTemp->before);
        printf("Data: %d\n", frontTemp -> data);
        printf("After: %p\n", frontTemp->after);
    }
}

void main()
{
    printf("Implementing queue using linked list.\n");
    int choice;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Search\n5.IsEmpty?\n6.IsFull?\n0.Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
                exit(0);
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
            default:
                printf("\nEnter correct choice.\n");
        }
    }
}
