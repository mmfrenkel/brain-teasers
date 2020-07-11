"""
Given a staircase of N steps, you can climb up either 1 or 2 steps at
a time. Return the number of unique ways you can climb the stairs, 
where the order of the step matters.
"""
def staircase(number_of_stairs):
    if number_of_stairs <= 1:
        return 1
    return staircase(number_of_stairs - 1) + staircase(number_of_stairs - 2)


def test_unique_steps():
    print(f"staircase(1) gives {staircase(1)}")
    print(f"staircase(4) gives {staircase(4)}")

test_unique_steps()

