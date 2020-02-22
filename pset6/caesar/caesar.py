from cs50 import get_string
import sys


def main():
    # checking the proper usage
    if len(sys.argv) != 2:
        # error alert
        print("Usage: ./caesar k")
        sys.exit(1)

    k = int(sys.argv[1])
    # get the input from the user
    plaintext = get_string("plaintext: ")

    # the output
    print("ciphertext: ", end="")
    for ch in plaintext:
        if(ch.islower()):
            print(chr((ord(ch) - ord("a") + k) % 26 + ord("a")), end="")
        elif (ch.isupper()):
            print(chr((ord(ch) - ord("A") + k) % 26 + ord("A")), end="")
        else:
            print(ch, end="")
    print()


if __name__ == "__main__":
    main()