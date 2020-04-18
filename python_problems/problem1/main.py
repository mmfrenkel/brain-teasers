
"""
cons(a,b) constructs a pair, and car(pair) and cdr(pair)
returns the first and last element of that pair. 

ex. car(cons(3, 4)) returns 3
ex. cdr(cons(3, 4)) returns 4
"""

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(pair_function):
    return pair_function(lambda a, b: a)

def cdr(pair_function):
    return pair_function(lambda a, b: b)

print(car(cons(3, 4)))
print(cdr(cons(3, 4)))

