#include <stdio.h>
#include "linked_list.h"

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