#include <stdio.h>

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
