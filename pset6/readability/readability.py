from cs50 import get_string


def main():

    # get input from the user
    inputs = get_string("Text: ")

    # counting only alphabet
    letters = 0
    for a in inputs:
        if (a.isalpha()):
            letters += 1

    words = len(inputs.split())  # counting the words
    sentences = (inputs.count(".") + inputs.count("?") + inputs.count("!"))  # counting the sentences

    letter_per_100_words = (letters / words) * 100
    sentence_per_100_words = (sentences / words) * 100

    # Coleman-Liau index' formula CLI = 0.0588*L - 0.296*S - 15.8
    cli = (0.0588 * letter_per_100_words) - (0.296 * sentence_per_100_words) - 15.8

    result = int(round(cli))

    # the output
    if (result >= 16):
        print("Grade 16+\n")
    elif (result < 1):
        print("Before Grade 1\n")
    else:
        print("Grade " + str(result))


if __name__ == "__main__":
    main()