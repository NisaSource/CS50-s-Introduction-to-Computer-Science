import csv
import getopt
import sqlite3
import sys
from student import Student


def main():

    if len(sys.argv) < 2:
        print("LOOOOOSER")
        return

    IN_FILE = sys.argv[1]

    connection = sqlite3.connect('students.db')
    cursor = connection.cursor()
    create = """
        --sql
        CREATE TABLE students
        (
            first TEXT,
            middle,
            last TEXT,
            house TEXT,
            birth INTEGER
        )
        --endsql
        """
    # drop table to start with a clean slate
    cursor.execute("""
        --sql
        DROP TABLE IF EXISTS students
        --endsql
    """)

    cursor.execute(create)

    def insert_student(student):
        with connection:
            cursor.execute("""
            --sql
            INSERT INTO students VALUES (:first, :middle, :last, :house, :birth)
            --endsql
        """, {
                'first': student.first,
                'middle': student. middle,
                'last': student.last,
                'house': student.house,
                'birth': student.birth,
            })
    # end insert_student

    with open(IN_FILE, 'r') as file:

        reader = csv.DictReader(file)
        for row in reader:
            name_array = row['name'].split(' ')
            name_length = len(name_array)

            first = ''
            middle = ''
            last = ''

            if name_length > 2:
                first = name_array[0]
                middle = name_array[1]
                last = name_array[2]
            else:
                first = name_array[0]
                middle = None
                last = name_array[1]

            student = Student(
                first,
                middle,
                last,
                row['house'],
                row['birth']
            )

            insert_student(student)

    connection.close()
# end main method


if __name__ == "__main__":
    main()