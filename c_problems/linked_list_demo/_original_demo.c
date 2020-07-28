#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int data;
    struct node *next;
};

struct node *headptr = NULL;
struct node *tailptr = NULL;

void add_node_end(int key, int value);
void add_node_start(int key, int value);
void add_node_position(int key, int value, int position);
void delete_node_position(int position);
void delete_node_end();
void delete_node_start();
int find_value_for_key(int key);
void print_linked_list();

void add_node_end(int key, int value) {

    struct node *new_node = (struct node*) malloc(sizeof(struct node));

    if (key < 0) {
        printf("Cannot create a new node with key < 0\n");
        return;
    }

    new_node->next = NULL;
    new_node->key = key;
    new_node->data = value;

    if (tailptr == NULL) {
        /* If there no is tailptr, then there can't be a head */
        headptr = new_node;
        tailptr = new_node;
    }
    else {
        tailptr->next = new_node;
    }
}

void add_node_start(int key, int value) {

    struct node *new_node = (struct node*) malloc(sizeof(struct node));

    if (key < 0) {
        printf("Cannot create a new node with key < 0\n");
        return;
    }

    new_node->next = NULL;
    new_node->key = key;
    new_node->data = value;

    if (headptr == NULL) {
        /* If there is no headptr, then there can't be a tail */
        headptr = new_node;
        tailptr = new_node;
    }
    else {
        new_node->next = headptr;
        headptr = new_node;
    }
}

void add_node_position(int key, int value, int position) {

    if (position == 0) {
        add_node_start(key, value);
    }

    /* Find where to insert new node */
    int count = 0;
    struct node *trav = headptr;
    struct node *trail = headptr;
    while (trav != NULL && count < position) {
        trail = trav;
        trav = trav->next;
        count += 1;
    }

    if (trav == NULL) {
        add_node_end(key, value);
    }
    else {
        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        new_node->key= key;
        new_node->data = value;
        new_node->next = trav;
        trail->next = new_node;
    }
}

void delete_node_position(int position) {

    if (position == 0) {
        delete_node_start();
    }

    /* Find which node to delete (trav) */
    int count = 0;
    struct node *trav = headptr;
    struct node *trail = headptr;
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

void delete_node_end() {

    if (tailptr == NULL) {
        printf("Linked List is empty! Can't delete from end\n");
    }
    else if (headptr->next == NULL) {
        /* In this case, there is only one node in the LL and after deletion
         * it will be empty */
        struct node *to_delete = headptr;
        headptr = NULL;
        printf("Deleted element %d from Linked List\n", to_delete->data);
        free(to_delete);
    }
    else {
        /* Find the second to last node; the node whose next node doesn't
         * have a next node */
        struct node *trav = headptr;
        while (trav->next->next != NULL) {
            trav = trav->next;
        }
        struct node *to_delete = trav->next;
        trav->next = NULL;
        printf("Deleted element %d from Linked List\n", to_delete->data);
        free(to_delete);
    }
}

void delete_node_start() {

    if (headptr == NULL) {
        printf("Linked List is empty! Can't delete from start\n");
    }
    else if (headptr->next == NULL) {
        /* In this case, there is only one node in the LL and after deletion
         * it will be empty */
        struct node *to_delete = headptr;
        headptr = NULL;
        printf("Deleted element %d from Linked List\n", to_delete->data);
        free(to_delete);
    }
    else {
        struct node *to_delete = headptr;
        headptr=to_delete->next;
        printf("Deleted element %d from Linked List\n", to_delete->data);
        free(to_delete);
    }
}

void print_linked_list() {

    if (headptr == NULL) {
        printf("Linked List is empty!\n");
    }
    else {
        printf("\n---- current linked list (in order front to back) ----\n");

        struct node *trav = headptr;
        do {
            printf(" [ %d:  %d ] ", trav->key, trav->data);
        } while ((trav = trav->next) != NULL);
        printf("\n\n");
    }
}

int find_value_for_key(int key) {

    if (headptr == NULL) {
        printf("Linked list is currently empty; No node with key %d\n", key);
        return -1;
    }

    struct node *trav = headptr;
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

int main(void) {

    char *user_choice_submitted;
    char *key_submitted;
    char *value_submitted;
    char *position_submitted;

    int user_choice;
    int key;
    int value;
    int position;
    printf("Ready to demo a linked list?!\n");

    while (1) {
        printf("Select (1-9) from the following options: \n");
        printf("----------------------------------------\n");
        printf("  1 - Add Node to Start\n");
        printf("  2 - Add Node to End\n");
        printf("  3 - Add Node at Specific Position\n");
        printf("  4 - Delete Node at Start\n");
        printf("  5 - Delete Node at End\n");
        printf("  6 - Delete Node at Specific Position\n");
        printf("  7 - Find Value for Key\n");
        printf("  8 - Print Linked List\n");
        printf("  9 - Stop Playing\n");
        printf("----------------------------------------\n");
        printf("Provide your selection: ");
        scanf("%s", &user_choice_submitted);

        if (user_choice == 1 || user_choice == 2 || user_choice == 3 || user_choice == 7) {
            printf("Submit a key: ");
            scanf("%s", &key_submitted);

            if (user_choice == 1 || user_choice == 2 || user_choice == 3) {
                printf("Submit a value: ");
                scanf("%s", &value_submitted);

                if (user_choice == 3 || user_choice == 7) {
                    printf("Submit a position: ");
                    scanf("%s", &position_submitted);
                }
            }
        }

        printf("User selected option %d!\n", user_choice);
        switch(user_choice) {
            case 1:
                add_node_start(key, value);
                print_linked_list();
                break;
            case 2:
                add_node_end(key, value);
                print_linked_list();
                break;
            case 3:
                add_node_position(key, value, position);
                print_linked_list();
                break;
            case 4:
                delete_node_start();
                print_linked_list();
                break;
            case 5:
                delete_node_end();
                print_linked_list();
                break;
            case 6:
                delete_node_position(position);
                print_linked_list();
                break;
            case 7:
                find_value_for_key(key);
                break;
            case 8:
                print_linked_list();
                break;
            case 9:
                printf("Exiting Now!\n");
                exit(0);
        }
    }
}

