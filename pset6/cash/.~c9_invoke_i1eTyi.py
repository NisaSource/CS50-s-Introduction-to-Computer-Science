from cs50 import get_float
from math import floor

while True:
    dollarsOwed = get_float("Change owed: ")
    centsOwed = floor(dollarsOwed * 100)
    
    if centsOwed > 0:
        break
    
quart