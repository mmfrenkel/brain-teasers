"""
Given two strings, a and b, determine the minimum number of
character deletions required to make a and b anagrams.
"""

def determine_deletions(str1, str2):
    
    char_dict = _find_dictionary_of_chars(str1, str2)
    count_changes = 0
    
    for key, value in char_dict.items():
        if len(value) == 1:
            key = list(value.keys())[0]
            count_changes += value[key]
        else:
            count_str1 = value["str1"]
            count_str2 = value["str2"]
            count_changes += abs(count_str1 - count_str2)

    return count_changes

# Creates a dict of chars to their frequencies, by string
def _find_dictionary_of_chars(str1, str2):
    char_dict = {}

    for letter in str1:
        if letter in char_dict.keys() and "str1" in char_dict[letter].keys():
            char_dict[letter]["str1"] += 1
        else:
            new_dict = {"str1": 1}
            char_dict[letter] = new_dict
    
    for letter in str2:
        if letter in char_dict.keys() and "str2" in char_dict[letter].keys():
            char_dict[letter]["str2"] += 1
        elif letter in char_dict.keys():
            char_dict[letter].update({"str2": 1})
        else:
            new_dict = {"str2": 1}
            char_dict[letter] = new_dict

    return char_dict


def test_determine_deletions():

    string_1 = "cde"
    string_2 = "abc"

    result = determine_deletions(string_1, string_2)
    expected = 4

    assert result == expected


test_determine_deletions()
