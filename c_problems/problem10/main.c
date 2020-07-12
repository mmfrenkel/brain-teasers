/*
 * Program to display all possible permutations
 * of a given input string; if the string contains
 * duplicate characters, you may have multiple 
 * repeated results.
 */

#include <stdio.h>
#include <string.h>

void permutate(char *value_string, int starting_index, int ending_index);
void swap(char *x, char *y);

int main(int argc, char* argv[]){
    
    if (argc !=2 ) {
        printf("Please provide a tring to permutate and try again!");
        return 1;
    }
    
    char *input_string = argv[1];
    permutate(input_string, 0, strlen(input_string)-1);
    return 0;
}

/* Prints out all possible permutations of a String (value_string) */
void permutate(char *value_string, int starting_index, int ending_index) {
    
    if (starting_index == ending_index) {
        printf("%s\n", value_string);
    }
    else {
        for (int i = starting_index; i <= ending_index; i++) {
            swap((value_string + starting_index), (value_string + i));
            permutate(value_string, starting_index + 1, ending_index);

            // backtrack, swap to original position
            swap((value_string + starting_index), (value_string + i));
        }
    }
}

/* Swap the values at two pointers */
void swap(char *x, char *y) {
    
    char temp = *x;  // hold onto value at x
    *x = *y;         // value at x is now value at y
    *y = temp;       // value at y is now old value at x
}

