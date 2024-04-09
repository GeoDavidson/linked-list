#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void printList(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("data = %d\n", current->data);
        current = current->next;
    }
}

void newNode(node_t **head, int data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;

    if (*head == NULL) {
        *head = node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

void pop(node_t **head) {
    if (*head == NULL) {
        fprintf(stderr, "ERROR: underflow, can't pop from empty list\n");
        exit(1);
    }
    node_t *nextNode = (*head)->next;
    free(*head);
    *head = nextNode;
}

void popLast(node_t **head) {
    if (*head == NULL) {
        fprintf(stderr, "ERROR: underflow, can't pop from empty list\n");
        exit(1);
    } else if ((*head)->next == NULL) {
        node_t *nextNode = (*head)->next;
        free(*head);
        *head = nextNode;
    } else {
        node_t *current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

void popIndex(node_t **head, int index) {
    if (index == 0) {
        pop(head);
    } else {
        node_t *current = *head;
        for (int i = 0; i < index - 1; i++) {
            if (current->next == NULL) {
                fprintf(stderr, "ERROR: index out of range\n");
                exit(1);
            }
            current = current->next;
        }
        if (current->next == NULL) {
            fprintf(stderr, "ERROR: index out of range\n");
            exit(1);
        }
        node_t *tempNode = current->next;
        current->next = tempNode->next;
        free(tempNode);
    }
}

int main() {
    node_t *head = NULL;

    for (int i = 0; i < 5; i++) {
        newNode(&head, i);
    }

    printList(head);

    popIndex(&head, 3);
    pop(&head);
    popLast(&head);

    printf("Done1\n");

    printList(head);

    printf("Done2\n");

    return 0;
}
