"""
A left rotation operation on an array shifts each element 1 unit left. 
For example, 2 left rotations of [1, 2, 3, 4, 5] then the array would
become [3, 4, 5, 1, 2]. 

Given an array of n integers and a number d, perform d rotations.
"""

def rotate_array(array, units):
    new_array = [0] * len(array)
    for index in range(0, len(array)):
        new_index = calculate_position(index, units, len(array));
        new_array[new_index] = array[index]

    return new_array
    
def calculate_position(curr_index, d, arr_len):
    
    diff = curr_index - (d % arr_len)
    if diff < -1:
        diff *= -1
        new_position = arr_len - diff
    else:
        new_position = diff

    return new_position
    
array = [1, 2, 3, 4, 5]
d = 2
print(f"The original array was {array}")
print(f"The left-rotated array is {rotate_array(array, d)}")

