/*
 * This program takes a file as an argument and 
 * counts the total number of lines in the file. 
 * Lines are defined as ending with a newline character.
 */
#include <stdio.h>

int main(int argc, char* argv[]) {
    
    FILE *fileptr;
    int count_lines = 0;      // to hold count of lines in file
    char chr;                 // character
    
    if (argc >= 2) {
        fileptr = fopen(argv[1], "r");
        
        /* Get chars individually */
        chr = getc(fileptr);

        while (chr != EOF) {
            if (chr == '\n') {
                count_lines += 1;
            }
            chr = getc(fileptr);
        }
        
        fclose(fileptr); // close file.
        printf("Number of lines in file = %d\n", count_lines);
    }
    else {
        printf("No filename provided; please try again.");
    }
    
    return 0;
}

