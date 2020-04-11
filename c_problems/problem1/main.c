#include <stdio.h>

/* Given an array of integers, return a new array such that
 * each element at index i of the new array is the product of all
 * the numbers in the original array, expect the one at i.
 */

int main(int argc, char **argv) {
	int arr[] = {1, 2, 3, 4, 5};
	int arrLength = 5;
	int sum = 1;

	printf("%p\n", arr);
	printf("%d\n", arr[0]);
	
	for (int i = 0; i < arrLength; i++) {
		sum = sum * arr[i];	
	}

	printf("[ ");
	for (int i = 0; i < arrLength; i++) {
		printf("%d ", sum / arr[i]);
		if (i < arrLength - 1) printf(", ");
	}
	printf("]\n");
}

