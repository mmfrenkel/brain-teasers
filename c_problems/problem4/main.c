#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};


// Add a prototype for countRedun() here
struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void); 
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);
int digitInList(struct digit * start, int digit);
int countRedun(struct digit * start);

// Do not modify this main() function
int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum % 3 == 0) return 1;
    else return 0;
}

int changeThrees(struct digit * start) {
/*
 * Takes as input a pointer that holds the address of the start
 * of a linked list of digits, changing all 3's to 9's in the list
 * and counting the number of replacements name.
 */
	struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        if (ptr->num == 3) {
            ptr->num = 9;
            sum++;
        }
        ptr = ptr->next;
    }
    return(sum);
}

int digitInList(struct digit * start, int digit) {
    struct digit * ptr = start;
    
    while (ptr != NULL) {
        if (ptr->num == digit) {
            return 1;
        }
        else {
            ptr = ptr->next;
        }
    }
    return 0;
}

int countRedun(struct digit * start) {
/*
 * As task input a pointer that holds the address of the start of a 
 * linked list of digits. Function counts how many redundancies can be observed
 * in the number stored in this list and return this count of redundancies.
 */
  	struct digit * ptr = start;
    struct digit * uniqueStart, * uniqueEnd;
    struct digit * newDig;
    int foundInList;
    int countRedun = 0;
    
    if (start != NULL) {
        uniqueStart = uniqueEnd = createDigit(start->num);
        ptr = ptr->next;
    }
    
    while (ptr != NULL) {
        foundInList = digitInList(uniqueStart, ptr->num);
        countRedun += foundInList;
        
        if (!foundInList) {
            newDig = createDigit(ptr->num);
            uniqueEnd = append(uniqueEnd, newDig);
        }
        ptr = ptr->next;
    }
    return countRedun;
}
