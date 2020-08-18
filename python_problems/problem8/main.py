"""
Given an array and a number k where k is smaller than the size of the array,
we need to find the k'th smallest element in the given array.
"""

array = [7, 10, 4, 3, 20, 15]
k = 3

def find_kth_smallest_element(array, k):
    # uses Timsort -- a combo of merge sort and insertion sort
    #  modifies the array inplace
    array.sort()

    return array[k-1]

print(f"The kth smallest ({k}) element in the array is {find_kth_smallest_element(array, k)}")

