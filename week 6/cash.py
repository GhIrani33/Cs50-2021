# TODO
from cs50 import get_float

# Get change
while True:
    dollar = get_float("Amount of Change: ")
    if dollar > 0:
        break

dollar = round(dollar * 100)

# Declare variables
count = 0

# while dollar greater than 0
while dollar > 0:
    if dollar >= 25:
        dollar -= 25
        count += 1
    elif dollar >= 10:
        dollar -= 10
        count += 1
    elif dollar >= 5:
        dollar -= 5
        count += 1
    elif dollar >= 1:
        dollar -= 1
        count += 1

# print total number of coins
print(count)
