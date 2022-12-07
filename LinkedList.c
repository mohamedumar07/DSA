#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *head = NULL;
int size = 0;

void insertingAtBeg();
void insertingAtEnd();
void insertingBeforeAnElement();
void insertingAfterAnElement();
void insertingAtSpecifiedPosition();
void deletingAtBeg();
void deletingAtEnd();
void deletingBeforeAnElement();
void deletingAfterAnElement();
void deletingAtSpecifiedPosition();
void serachingByPosition();
void searchingByValue();
void display();


void main()
{
  int ch;
    while (1)
    {
        printf("1.insertingAtBeg\n");
        printf("2.insertingAtEnd\n");
        printf("3.insertingBeforeAnElement\n");
        printf("4.insertingAfterAnElement\n");
        printf("5.insertingAtSpecifiedPosition\n");
        printf("6.deletingAtBeg\n");
        printf("7.deletingAtEnd\n");
        printf("8.deletingBeforeAnElement\n");
        printf("9.deletingAfterAnElement\n");
        printf("10.deletingAtSpecifiedPosition\n");
        printf("11.serachingByPosition\n");
        printf("12.searchingByValue\n");
        printf("13.display\n");
        printf("0.To quit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            insertingAtBeg();
            break;
            case 2:
            insertingAtEnd();
            break;
            case 3:
            insertingBeforeAnElement();
            break;
            case 4:
            insertingAfterAnElement();
            break;
            case 5:
            insertingAtSpecifiedPosition();
            break;
            case 6:
            deletingAtBeg();
            break;
            case 7:
            deletingAtEnd();
            break;
            case 8:
            deletingBeforeAnElement();
            break;
            case 9:
            deletingAfterAnElement();
            break;
            case 10:
            deletingAtSpecifiedPosition();
            break;
            case 11:
            serachingByPosition();
            break;
            case 12:
            searchingByValue();
            break;
            case 13:
            display();
            break;
            case 0:
            exit(0);
            default:
            printf("Incorrect choice \n");
        }
    }
}

void insertingAtBeg()
{
    int value;
    Node *newNode;
    newNode = malloc(sizeof(Node));
    printf("Enter a value: ");
    scanf("%d", &value);
    newNode->data = value;
    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    size++;
}


void insertingAtEnd()
{
    int value;
    Node *newNode;
    Node *temp = head;
    newNode = malloc(sizeof(Node));
    printf("Enter a value: ");
    scanf("%d", &value);
    newNode->data = value;
    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    size++;
}

void insertingBeforeAnElement()
{
    int before;
    printf("Enter the number before a new number is to be inserted: ");
    scanf("%d", &before);
    Node *temp = head;
    Node *temp2;
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Error in allocating memory.\n");
    }
    else{
        printf("Enter the value: ");
        scanf("%d", &newNode->data);
        //newNode->data = 36;
        while(temp->data != before)
        {
            temp2 = temp;
            temp = temp->next;
        }
        newNode->next = temp;
        temp2->next = newNode;
    }
    size++;
}

void deletingAtSpecifiedPosition()
{
  Node *temp = head;
  Node *temp2;
  int pos;
  printf("Enter the position of an element to be deleted: ");
  scanf("%d", &pos);
  for(int i = 0; i < (pos-2); pos++)
  {
    temp = temp->next;
  }
  temp2 = temp->next;
  temp->next = temp->next->next;
  free(temp2);
}

void insertingAtSpecifiedPosition()
{
    Node *temp = head;
    Node *temp2;
    Node *newNode = malloc(sizeof(Node));
    int pos;
    printf("Enter the position of an element where data to be added: ");
    scanf("%d", &pos);
    printf("Enter the number: ");
    scanf("%d", &newNode->data);
    for(int i = 1; i < (pos-1); i++)
    {
      temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = newNode;
    newNode->next = temp2;
}

void serachingByPosition()
{
  Node *temp = head;
  int pos;
  printf("Enter a position to see it's value: ");
  scanf("%d", &pos);
  for(int i = 0; i < (pos-1); pos++)
  {
    temp = temp->next;
  }
  printf("The element at %d position is %d\n", pos, temp->data);
}

void searchingByValue()
{
  Node *temp = head;
  int value;
  printf("Enter a value to see it's position value in the list: ");
  scanf("%d", &value);
  int pos = 1;
  while(temp->data != value)
  {
    temp = temp->next;
    pos++;
  }
  printf("The value %d is present at %d position.\n", value, pos);
}

void insertingAfterAnElement()
{
    int after;
    printf("Enter the number after a new number is to be inserted: ");
    scanf("%d", &after);
    Node *temp = head;
    Node *temp2;
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Error in allocating memory space\n");
    }
    else{
        if(head == NULL){
            printf("No element stored in the list.\n");
        }
        else{
            printf("Enter the value: ");
            scanf("%d", &newNode->data);
            while(temp->data != after)
            {
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next = newNode;
            newNode->next = temp2;
            }
    }
    //size++;
}

void deletingAfterAnElement()
{
    int after;
    printf("Enter the number after a number is to be deleted: ");
    scanf("%d", &after);
    Node *temp = head;
    Node *temp2;
     if(head == NULL){
        printf("No element stored in the list.\n");
    }
    else{
        while(temp->data != after)
        {
            temp = temp->next;
        }
        temp2 = temp->next->next;
        free(temp->next);
        temp->next = temp2;
    }
}

void deletingBeforeAnElement()
{
  int before;
  printf("Enter the number after a number is to be deleted: ");
  scanf("%d", &before);
  Node *temp = head;
  Node *temp2, *temp3;
  while(temp -> data != before)
  {
    temp3 = temp;
    temp2 = temp3 -> next;
    temp = temp2 -> next;
  }
  temp3->next = temp2->next;
  free(temp2);
}


void display()
{
    Node* temp = head;
    if(head==NULL){
        printf("\nStack is empty\n");
    }
    else{
        while(temp -> next != NULL){
            printf("%d --> ",temp->data);
            temp = temp -> next;
        }
        printf("%d -> NULL\n",temp -> data);
    }
}


void deletingAtBeg()
{
    Node *temp = head;
    if(temp == NULL)
    {
        printf("There is no element in the list.");
    }
    else
    {
        head = temp->next;
        free(temp);
    }
}

void deletingAtEnd()
{
    Node *temp = head;
    Node *ptr;
    if(temp == NULL)
    {
        printf("There is no element in the list.");
    }
    else{
    while(temp->next != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = temp->next;
    free(temp);
}
}
