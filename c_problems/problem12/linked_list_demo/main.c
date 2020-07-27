#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_list.h"

int MAX_SUBMISSION_SIZE = 1;

bool valid_selection(char *user_choice) {
	printf("User selected option %s!\n", user_choice);

	int i;
	if (i = 0; i < strlen(user_choice); i++) {
		if (!isdigit(user_choice[i])) {
			return false;
		}
	}
	return true;
}

int main(void) {

    char *user_choice_submitted[MAX_SUBMISSION_SIZE];
    int user_choice;
    int key;
    int value;
    int position;
    Linked_List llist = {NULL, NULL};

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

        if (!valid_selection(user_choice_submitted)) {
        	printf("Please provide a number 1-9");
        	continue;
        }

        user_choice = atoi(user_choice_submitted);
        if (user_choice == 1 || user_choice == 2 || user_choice == 3 || user_choice == 7) {
            printf("Submit a key: ");
            scanf("%d", &key);

            if (user_choice == 1 || user_choice == 2 || user_choice == 3) {
                printf("Submit a value: ");
                scanf("%d", &value);

                if (user_choice == 3 || user_choice == 7) {
                    printf("Submit a position: ");
                    scanf("%d", &position);
                }
            }
        }

        switch(user_choice) {
            case 1:
                add_node_start(&llist, key, value);
                print_linked_list(&llist);
                break;
            case 2:
                add_node_end(&llist, key, value);
                print_linked_list(&llist);
                break;
            case 3:
                add_node_position(&llist, key, value, position);
                print_linked_list(&llist);
                break;
            case 4:
                delete_node_start(&llist);
                print_linked_list(&llist);
                break;
            case 5:
                delete_node_end(&llist);
                print_linked_list(&llist);
                break;
            case 6:
                delete_node_position(&llist, position);
                print_linked_list(&llist);
                break;
            case 7:
                find_value_for_key(&llist, key);
                break;
            case 8:
                print_linked_list(&llist);
                break;
            case 9:
                printf("Exiting Now!\n");
                exit(0);
        }
    }
}

