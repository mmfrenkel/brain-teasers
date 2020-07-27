#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int valid_selection(char *user_choice) {
	printf("User selected option %s!\n", user_choice);

	int i;
	for (i = 0; i < (int) strlen(user_choice); i++) {
		if (!isdigit(user_choice[i])) {
			return 0;
		}
	}
	return 1;
}
