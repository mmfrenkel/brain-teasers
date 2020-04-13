#include <stdio.h>

int findPeak(int *, int);

int main(void) {
    int numElements = 6;
    int arr[] = {1, 3, 7, 4, 8, 2};
    int peak = findPeak(arr, numElements);
    printf("The peak function should return 7. Result is: %d\n", peak);
}

/*
 * Given unsorted array, in which all elements are distinct,
 * find a "peak" element in O(log N) time. An element is considered
 * a peak if it is greater than both its left and right neightbors. 
 * It is guaranteed that the first and last elements are lower than
 * all others.
 */
int findPeak(int *arrPtr, int numElem) {
    int start = 0;
    int end = numElem - 1;

    while (start + 1 < end) {
        int middle = (start + end) / 2;
        int valueMiddle = *(arrPtr + middle);
        int valueLeft = *(arrPtr + middle - 1);
        int valueRight = *(arrPtr + middle + 1);

        printf("Middle: %d, Left: %d, Right: %d\n", valueMiddle, valueLeft, valueRight);
        if (valueMiddle > valueLeft && valueMiddle > valueRight) {
            return valueMiddle;
        }
        else if (valueMiddle < valueLeft) {
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }
    return *(arrPtr);
}

