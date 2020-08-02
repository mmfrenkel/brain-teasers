#include <stdio.h>

int main(int argc, char *argv[]) {
    
    printf("-------- CREATE YOUR OWN PERIODIC TABLE -------\n");
    int keep_going = 1;
    int user_selection;
    char *filename = argv[1]; 

    while(keep_going) {
        
        printf("Please select an option from below:\n");
        printf("  1. See All Saved Elements\n");
        printf("  2. Edit Content of Element\n");
        printf("  3. Add A New Element, by Atomic Number"\n);
        printf("  4. Save Edits to File\n");
        printf("  5. Exit Program\n");

        scanf("%d", &user_selection);

        /* read in the existing periodic table from file; changes
         *  will be in memory until user quits */ 
        Periodic_Table *periodic_table = read_in_periodic_table(filename);

        switch(user_selection) {
            case 1:
                print_periodic_table(periodic_table);
                break;
            case 2:
                edit_periodic_table(periodic_table);
                print_periodic_table(periodic_table);
                break;
            case 3:
                add_new_element_to_periodic_table(periodic_table);
                break;
            case 4:
                save_periodic_table_to_file(periodic_table, filename);
                break;
            case 5:
                save_periodic_table_to_file(periodic_table, filename);
                keep_going = 0;
                break;
        }
    }
    printf("Exiting Program...");
    free_periodic_table(periodic_table);
    return 0;
}

