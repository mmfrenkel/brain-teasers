#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}

struct node *headptr = NULL;
struct node *tailptr = NULL;

void add_node_end(int x) {
    
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    
    new_node->next = NULL;
    new_node->data = x; 

    if (tailptr == NULL) {
        /* If there no is tailptr, then there can't be a head */
        headptr = new_node;
        tailptr = new_node;
    }   
    else {
        tail->next = new_node;
    }
}

void add_node_start(int x) {
    
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = x;

    if (headptr == NULL) {
        /* If there is no headptr, then there can't be a tail */
        headptr = new_node;
        tailptr = new_node;
    }
    else {
        new_node->next = headptr;
        head_ptr = new_node;
    }

void delete_node_end() {
    
    if (tailptr == NULL) {
        printf("Linked List is empty! Can't delete from end");
    }
    else if (headptr->next == NULL) {
        /* In this case, there is only one node in the LL and after deletion
         * it will be empty */
        struct node *to_delete = headptr;
        headptr = NULL;
        printf("Deleted element %d from Linked List", to_delete->data);
        free(to_delete);
    }
    else {
        /* Find the second to last node; the node whose next node doesn't 
         * have a next node */
        struct node *trav = headptr;
        while (trav->next->next != NULL) {
            trav = trav->next;
        }
        struc node *to_delete = trav->next;
        trav->next = NULL;
        printf("Deleted element %d from Linked List", to_delete->data);
        free(to_delete);
    }
}

void delete_node_start() {
    
    if (headptr == NULL) {
        printf("Linked List is empty! Can't delete from start");
    }
    else if (headptr->next == NULL) {
        /* In this case, there is only one node in the LL and after deletion
         * it will be empty */
        struct node *to_delete = headptr;
        headptr = NULL;
        printf("Deleted element %d from Linked List, to_delete->data);
        free(to_delete);
    }
    else {
        struct node *to_delete = headptr;
        headptr=to_delete->next;
        printf("Deleted element %d from Linked List", to_delete->data);
        free(to_delete);
    }
}

void print_list() {
    
    if (headptr == NULL) {
        printf("Linked List is empty!");
    }
    else {
        struct node *trav = headptr;
        
        do {
            printf("[ %d ]", trav->data);
        } (while trav->next != NULL);
    }
}

