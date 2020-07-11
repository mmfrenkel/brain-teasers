#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the hourglassSum function below.
def hourglassSum(arr):
    largest_sum = 0

    if not arr or len(arr) < 3 or len(arr[0]) < 3:
        return largest_sum 

    rows_of_hour_glasses = len(arr) - 2
    for row in range(0, rows_of_hour_glasses):
        top_arr = arr[row] 
        middle_arr = arr[row + 1]
        lower_arr = arr[row + 2]
        hour_glasses_in_row = len(top_arr) - 2 

        indicies_top_bottom = [0, 1, 2]
        index_middle = 1
        count = 0

        while count < hour_glasses_in_row:
            top = sum([top_arr[index + count] for index in indicies_top_bottom])
            bottom = sum([lower_arr[index + count] for index in indicies_top_bottom])
            middle = middle_arr[index_middle + count]
            curr_sum = top + bottom + middle

            print(curr_sum)
            largest_sum = curr_sum if curr_sum > largest_sum else largest_sum 
            count += 1
    
    return largest_sum

if __name__ == '__main__':
    arr = [[-1, -1, 0, -9, -2, -2], [-2, -1, -6, -8], [], [], [], []]
    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)
    print(result)
