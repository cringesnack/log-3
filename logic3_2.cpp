#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[256];
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;


void addElement()
{
    struct node* newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation error.\n");
        return;
    }

    printf("Enter element: ");
    scanf("%255s", newNode->data);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    printf("Element added successfully.\n");
}


void deleteElements()
{
    int number;
    int removed = 0;
    struct node* temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("How many elements to delete: ");
    scanf("%d", &number);

    if (number <= 0)
    {
        printf("Invalid number.\n");
        return;
    }

    while (head != NULL && removed < number)
    {
        temp = head;
        head = head->next;

        free(temp);

        removed++;
    }

    if (head == NULL)
    {
        tail = NULL;
    }

    printf("%d element(s) deleted.\n", removed);
}

void moveElementToEnd()
{
    char name[256];
    struct node* current = head;
    struct node* previous = NULL;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter element name: ");
    scanf("%255s", name);

    while (current != NULL &&
        strcmp(current->data, name) != 0)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Element not found.\n");
        return;
    }

    if (current == tail)
    {
        printf("Element is already at the end.\n");
        return;
    }

    if (previous == NULL)
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }


    tail->next = current;
    current->next = NULL;
    tail = current;

    printf("Element moved to the end successfully.\n");
}

void displayList()
{
    struct node* current = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nCurrent list:\n");

    while (current != NULL)
    {
        printf("Element: %s\n", current->data);
        current = current->next;
    }
}


void freeList()
{
    struct node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    tail = NULL;
}


int main()
{
    int choice;

    do
    {
        printf("\n");
        printf("==========================\n");
        printf("1. Add element\n");
        printf("2. Delete elements\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("5. Move element to end\n");
        printf("===========================\n");
        printf("Choose an option: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addElement();
            break;

        case 2:
            deleteElements();
            break;

        case 3:
            displayList();
            break;

        case 4:
            freeList();
            printf("Program finished.\n");
            break;

        case 5:
            moveElementToEnd();
            break;

        default:
            printf("Invalid option.\n");
            return 0;
        }

    } while (choice != 4);

    return 0;
}