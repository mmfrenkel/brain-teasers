#include <stdio.h>
#include <stdlib.h>

/*
 * Implement an XOR linked list. Instead of  each node holding 
 * next and prev fields, it holds a field named both, which is 
 * an XOR of the next node and the previous node. 
 *
 * add(element) method:  adds elements to the end
 * get(index) which returns the node at index.
 */

struct node {
    int data;
    struct node* npx; /* XOR of next and prev node */
};

/*
 * Returns the XORed value of two node addresses.
 * Recall: if  a = 5 = 0101, b = 3 = 0011
 * a ^ b = 0101 ^ 0011 = 0110 = 6
 */
struct node* XOR(struct node *a, struct node *b) {
    return (struct node*) ((unsigned int) (a) ^ (unsigned int) (b));
}

/* 
 * Add a node at the beginning of a linked list and makes
 * the newly inserted node as head.
 */
void insert(struct node **head_ref, int data) {
    // allocate memory for new node
    printf("Creating new node: %d\n", data);
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;

    // new node always inserted at beginning, so npx of new node
    // will be XOR of current head and null
    new_node->npx = XOR(*head_ref, NULL);

   // if linked list is not empty, then npx of current head node
   //  will have to be the XOR of new node and node next to the current head
   if (*head_ref != NULL) {
       printf("Reassigning it as new head node...\n");
       struct node* next = XOR((*head_ref)->npx, NULL);
       (*head_ref)->npx = XOR(new_node, next);
   }

   // reassign start of list to location of new node
   *head_ref = new_node;
} 

void printList(struct node *head){
    struct node *curr = head;
    struct node *prev = NULL; // start at beginning of list
    struct node *next;

    printf("These are the nodes in the Linked List: \n");

    while(curr != NULL) {
        printf("%d ", curr->data);

        // retreive address of next node; if curr->npx is equal
        // to next^prev, then curr->npx^prev = next^prev^prev = next
        next = XOR(prev, curr->npx);

        // update prev/curr for next ieration
        prev = curr;
        curr = next;
    }
}

int main(void) {
    printf("Creating the following:\n");    
    printf("head-->50<-->20<-->30<-->10\n");
   
    struct node *head = NULL;
    insert(&head, 50);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 10);
    
    printList(head);
    return(0);
}






















