#include <stdio.h>

/* 
 * Given a list of integers, write a function
 * that returns the largest sum of non-adjacent numbers;
 * Numbers can be 0 or negative.
 */

int largestSum(int arr[], int size);

int main(void) {
    int arr[5] = {2, 4, 5, 2, 5};
}

int largestSum(int arr[], int size) {
    
    int largestSum = 0;

    for (int i = 0; i < size; i++) {
        int tempSum = arr[i] + arr[i + 1];
        if (tempSum > largestSum) 
    }
}

