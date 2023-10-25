import csv
import sys

STRS_H = []

def main(db_file: str, sequence_file: str) -> None:

    try:
        with open(db_file, 'r') as f:
            reader = csv.reader(f)
            global STRS_H
            STRS_H = next(reader)[1:]

            database = {}
            for row in reader:
                database[row[0]] = [int(x) for x in row[1:]]

        with open(sequence_file) as f:
            sequence = f.read().strip()

        STR_count = [longest_match(sequence, sub_str) for sub_str in STRS_H]

        result = search_database(STR_count, database)

        print(result)
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)


def search_database(target, database):
    for name, profile in database.items():
        if target == profile:
            return name
    return "No match"


def longest_match(sequence, subsequence):
    """
    Returns the length of the longest run of `subsequence` within `sequence`.
    """
    max_count = 0
    i = 0

    while i < len(sequence):
        count = 0

        # Counts consecutively repeated `subsequence` patterns at i until no match
        while sequence[i:i + len(subsequence)] == subsequence:
            count += 1
            i += len(subsequence)

        max_count = max(max_count, count)
        i += 1

    return max_count

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    main(sys.argv[1], sys.argv[2])
