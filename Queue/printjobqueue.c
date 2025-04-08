#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  PrintJob {
    int jobID;
    char documentName[100];
    int pages;
    struct PrintJob* next;
} ;

struct PrintJob * front = NULL;
struct PrintJob * rear = NULL;
int jobCounter = 1;

void enqueue(char docName[10], int pages) {
    struct PrintJob * newJob = (struct PrintJob *)malloc(sizeof(struct PrintJob));
    newJob->jobID = jobCounter++;
    strcpy(newJob->documentName, docName);
    newJob->pages = pages;
    newJob->next = NULL;
    if (rear == NULL) {
        front = rear = newJob;
    } else {
        rear->next = newJob;
        rear = newJob;
    }

    printf("Job %d added: %s (%d pages)\n", newJob->jobID, newJob->documentName, newJob->pages);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct PrintJob * temp = front;
    printf("Printing job %d: %s (%d pages)\n", temp->jobID, temp->documentName, temp->pages);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct PrintJob * temp = front;
    printf("Current Print Queue:\n");
    while (temp != NULL) {
        printf("Job %d: %s (%d pages)\n", temp->jobID, temp->documentName, temp->pages);
        temp = temp->next;
    }
}

int main() {
    int choice, pages;
    char docName[100];

    while (1) {
        printf("\nPrinter Queue Menu:\n");
        printf("1. Add Print Job\n");
        printf("2. Process Next Job\n");
        printf("3. Show Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                //fgets(docName, 100, stdin);
                //docName[strcspn(docName, "\n")] = 0;
                scanf("%s",docName);
                printf("Enter number of pages: ");
                scanf("%d", &pages);
                enqueue(docName, pages);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}