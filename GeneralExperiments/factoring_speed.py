from sympy import sieve
from sympy import factorint
from math import sqrt
import cProfile

pr = cProfile.Profile()
pr.enable()

max_n = 20000000

print("Solving factorizations up to n = {}".format(max_n))
print("Calculating all necessary primes...")
sieve.extend_to_no(max_n)

print("Factoring")
for x in range(2, max_n+1):
    if x%100000 == 0:
        print("Currently at: {}".format(x))
    factorint(x)


pr.disable()
pr.print_stats(sort='time')
