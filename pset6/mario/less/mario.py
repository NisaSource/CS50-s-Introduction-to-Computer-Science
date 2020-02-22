from cs50 import get_int


while True:
    # Get the input from the user
    height = get_int("Height : ")
    # check the condition between 1 and 8
    if height >= 1 and height <= 8:
        break

# Loop over the rows
for rows in range(0, height):
    # To print the spaces
    for spaces in range(1, height - rows):
        print(" ", end="")

    # To print the hashes
    for rightHashes in range(height - rows, height + 1):
        print("#", end="")

    print()