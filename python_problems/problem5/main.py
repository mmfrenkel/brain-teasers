"""
Find the number of classrooms required, given an array of time
intervals in which classes will be occuring
"""
def find_required_classrooms(arr_intervals): 
    occupied_times = []
    num_rooms = 0
    
    for interval in arr_intervals:
        print(f"Investigating {interval}")
        if not occupied_times or is_overlapping_interval(interval, occupied_times):
            num_rooms += 1
            occupied_times = occupied_times + [interval] if occupied_times else [interval]
        print(f"List occupied_times = {occupied_times}")

    return num_rooms

def is_overlapping_interval(interval, list_taken_intervals):
    for taken_interval in list_taken_intervals:
        if (taken_interval[1] < interval[0] or interval[1] < interval[0]):
            print(f"{interval} and {taken_interval} do not overlap")
            return False
    print(f"{interval} and {taken_interval} do overlap")
    return True

arr_intervals = [(30, 75), (0, 50), (60, 150)]
print(find_required_classrooms(arr_intervals))

