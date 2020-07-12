/* 
 * Program takes an integer and displays the english name of 
 * that value. Supports both positive and negative numbers,
 * in the range supported by a 32-bit integer (-2 billion to 2 billion, approx).
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE_STRING 100

/* provide prototypes */
void say_number(int value_passed, bool negative_number);
char* say_positive_number(int positive_value);

char *numbers[] = {
    "",
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

char *tens[] = {
    "", "",
    "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

char *powers[] = {
    "", "thousand", "million", "billion"
};

int main(int argc, char *argv[]) {
    
    /* get value passed by user */
    int value_passed = (int) *argv[1];
    bool negative_value = false;

    /* handle negative case */
    if (value_passed < 0) {
        negative_value = true;
        value_passed *= -1;
    }
    /* handle 0 case */
    else if (value_passed == 0){
        printf("zero");
        return 0;
    }
    
    say_number(value_passed, negative_value);
    return 0;
}

void say_number(int value_passed, bool negative_number) {
    
    char* modifier = negative_number ? "negative " : "";
    printf("%s%s", modifier, say_positive_number(value_passed));
}

char* say_positive_number(int positive_value) {    
    char str[MAX_SIZE_STRING];

    if (positive_value < 20) {
        strcpy(str, numbers[positive_value]);
    }
    else if (positive_value < 100) {
        sprintf(str, "%s %s", tens[positive_value / 10], say_positive_number(positive_value % 10));
    }
    else if (positive_value < 1000) {
        sprintf(str,"%s %s %s", numbers[positive_value / 100], "hundred", say_positive_number(positive_value % 100));
    }
    else if (positive_value < (1000**4)) {
        /* need to handle special illions case */
        for (int i = 1; i < 4; i++) {
            if (positive_value < 1000**(i + 1)) {
                sprintf(str, "%s %s %s", say_postive_number(positive_value / (1000*i)),powers[i], 
                        say_positive_number(positive_value % (1000*i)));
            }
        }
    } /* otherwise, the value is too large for this program */
    else { 
        return "value is too large to be supported by this program";
    }
    return str;
}

