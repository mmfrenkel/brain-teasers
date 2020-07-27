
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list {
	node *head;
	node *tail;
} Linked_List;

void add_node_end(Linked_List list, int key, int value);

void add_node_start(Linked_List list, int key, int value);

void add_node_position(Linked_List list, int key, int value, int position);

void delete_node_position(Linked_List list, int position);

void delete_node_end(Linked_List list);

void delete_node_start(Linked_List list);

int find_value_for_key(Linked_List list, int key);

void print_linked_list(Linked_List list);

#endif
