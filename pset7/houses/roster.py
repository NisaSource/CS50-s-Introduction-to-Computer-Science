import sqlite3
import sys


def main():
    if len(sys.argv) < 2:
        print("I")
        return

    HOUSE = sys.argv[1]
    connection = sqlite3.connect('students.db')
    cursor = connection.cursor()

    cursor.execute("""
        --sql
        SELECT * FROM students WHERE house=:house ORDER BY last, first
        --endsql
    """, {'house': HOUSE})

    results = cursor.fetchall()

    for result in results:
        first = result[0]
        middle = result[1]
        last = result[2]
        birth = result[4]

        print(first + ' ',
              middle + ' ' if middle else '',
              last + ' ',
              birth,
              sep='')


if __name__ == "__main__":
    main()