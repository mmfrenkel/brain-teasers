#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void add_node_end(Linked_List *list, int key, int value) {

    Node *new_node = (Node *) malloc(sizeof(Node));

    if (key < 0) {
        printf("Cannot create a new node with key < 0\n");
        return;
    }

    new_node->next = NULL;
    new_node->key = key;
    new_node->data = value;

    if (list->tailptr == NULL) {
        /* If there no is tailptr, then there can't be a head */
        list->headptr = new_node;
        list->tailptr = new_node;
    }
    else {
        list->tailptr->next = new_node;
    }
}

void add_node_start(Linked_List *list, int key, int value) {

    Node *new_node = (Node *) malloc(sizeof(Node));

    if (key < 0) {
        printf("Cannot create a new node with key < 0\n");
        return;
    }

    new_node->next = NULL;
    new_node->key = key;
    new_node->data = value;

    if (list->headptr == NULL) {
        /* If there is no headptr, then there can't be a tail */
        list->headptr = new_node;
        list->tailptr = new_node;
    }
    else {
        new_node->next = list->headptr;
        list->headptr = new_node;
    }
}

void add_node_position(Linked_List *list, int key, int value, int position) {

    if (position == 0) {
        add_node_start(list, key, value);
    }

    /* Find where to insert new node */
    int count = 0;
    Node *trav = list->headptr;
    Node *trail = list->headptr;
    while (trav != NULL && count < position) {
        trail = trav;
        trav = trav->next;
        count += 1;
    }

    if (trav == NULL) {
        add_node_end(list, key, value);
    }
    else {
        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->key= key;
        new_node->data = value;
        new_node->next = trav;
        trail->next = new_node;
    }
}

void delete_node_position(Linked_List *list, int position) {

    if (position == 0) {
        delete_node_start(list);
    }

    /* Find which node to delete (trav) */
    int count = 0;
    Node *trav = list->headptr;
    Node *trail = list->headptr;
    while (trav != NULL && count < position) {
        trav = trav->next;
        count += 1;
    }

    if (trav == NULL) {
        printf("No node to delete at position %d\n", position);
    }
    else {
        trail->next = trav->next;
        free(trav);
    }
}

void delete_node_end(Linked_List *list) {

    if (list->tailptr == NULL) {
        printf("Linked List is empty! Can't delete from end\n");
    }
    else if (list->headptr->next == NULL) {
        /* In this case, there is only one node in the LL and after deletion
         * it will be empty */
        Node *to_delete = list->headptr;
        list->headptr = NULL;
        printf("Deleted element %d from Linked List\n", to_delete->data);
        free(to_delete);
    }
    else {
        /* Find the second to last node; the node whose next node doesn't
         * have a next node */
        Node *trav = list->headptr;
        while (trav->next->next != NULL) {
            trav = trav->next;
        }
        Node *to_delete = trav->next;
        trav->next = NULL;
        printf("Deleted element %d from Linked List\n", to_delete->data);
        free(to_delete);
    }
}

void delete_node_start(Linked_List *list) {

    if (list->headptr == NULL) {
        printf("Linked List is empty! Can't delete from start\n");
    }
    else if (list->headptr->next == NULL) {
        /* In this case, there is only one node in the LL and after deletion
         * it will be empty */
        Node *to_delete = list->headptr;
        list->headptr = NULL;
        printf("Deleted element %d from Linked List\n", to_delete->data);
        free(to_delete);
    }
    else {
        Node *to_delete = list->headptr;
        list->headptr = to_delete->next;
        printf("Deleted element %d from Linked List\n", to_delete->data);
        free(to_delete);
    }
}

void print_linked_list(Linked_List *list) {

    if (list->headptr == NULL) {
        printf("Linked List is empty!\n");
    }
    else {
        printf("\n---- current linked list (in order front to back) ----\n");

        Node *trav = list->headptr;
        do {
            printf(" [ %d:  %d ] ", trav->key, trav->data);
        } while ((trav = trav->next) != NULL);
        printf("\n\n");
    }
}

int find_value_for_key(Linked_List *list, int key) {

    if (list->headptr == NULL) {
        printf("Linked list is currently empty; No node with key %d\n", key);
        return -1;
    }

    Node *trav = list->headptr;
    while (trav->key != key) {
        trav = trav->next;

        if (trav == NULL) {
            printf("No node found with key %d\n", key);
            return -1;
        }
    }
    printf("Value for (first) node with key = %d is %d\n", key, trav->data);
    return trav->data;
}
