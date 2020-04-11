/*
 * Implement date feature in C
 */
#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

struct date advanceDay(struct date d) {
    if (d.month == 9 || d.month == 4 || d.month == 6 || d.month == 11) {
        if (d.day == 30) {
            d.day = 1;
            d.month++;
        } 
    } else if (d.month == 2 && d.day == 28 ) {
        d.day = 1;
        d.month++;
    } else if (d.day == 31) {
        d.day = 1;
        if (d.month == 12) {
            d.month = 1;
            d.year++;
        }
    } else {
        d.day++;
    }
    return d;
}

void readDate(struct date * d) {
    scanf("%d", &(*d).year);
    scanf("%d", &(*d).month);
    scanf("%d", &(*d).day);
}

void printDate(struct date d) {
    
    if (d.month < 10) {
        printf("0");
    } 
    printf("%d/", d.month);
    if (d.day < 10){
        printf("0");
    }
    printf("%d/%d\n", d.day, d.year);
}

