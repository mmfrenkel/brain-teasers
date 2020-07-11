"""
Given an integer k and a string s, find the length of the longest substring
that contains at most k distinct characters. For example, given s = "abcba"
and k = 2, find the longest substring with k distinct characters.
"""
def find_longest_substring(string, num_distinct_characters):
    if num_distinct_characters == 0:
        return 0

    index_bounds = (0, 0)
    char_indices = {}
    max_length_substring = 0

    for i, char in enumerate(string):
        char_indices[char] = i  # save latest position of char

        if len(char_indices) <= num_distinct_characters:
            new_lower_bound = index_bounds[0]
        else:
            key_to_pop = min(char_indices, key=char_indices.get)
            new_lower_bound = char_indices.pop(key_to_pop) + 1 

        index_bounds = (new_lower_bound, index_bounds[1] + 1)
        max_length_substring = max(max_length_substring, index_bounds[1] - index_bounds[0])

    return max_length_substring


def test_find_longest_substring():
    string = "abcba"
    num_char = 2
    longest_substring = find_longest_substring(string, num_char)
    print(f"The longest substring where string = {string} and "
          f"number characters = {num_char} would be: {longest_substring}. ")



test_find_longest_substring()

