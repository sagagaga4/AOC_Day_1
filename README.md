### Advent of Code - Day 1 Solution 🎄

## Overview 📜
Welcome to the solution for Advent of Code Day 1! 🎅 This repository contains AOC_DAY_1.c, a C program that solves the challenge by reading pairs of 5-digit numbers from lists.txt, sorting each column (left and right), and calculating the sum of absolute differences between sorted pairs. It outputs the line count and the total distance, which is the answer to the puzzle! ✅
# Challenge Description ❓

* Input: A text file (lists.txt) with up to 1000 lines, each containing two 5-digit numbers separated by spaces (e.g., 80784 47731). 📥
* Task: Sort the numbers in the left and right columns in ascending order, pair them by position (smallest with smallest, etc.), and sum the absolute differences of each pair. 🔍
* Output: The total distance is the AoC answer. The program also prints the line count and each pair’s distance for verification. 📤

## Program Details 💻

File: AOC_DAY_1.c
* Language: C
* Functions:
* countLines: Counts lines in lists.txt by reading characters and counting newlines. 📏
* returnDist: Reads lists.txt character-by-character, stores numbers in arrays, sorts columns with qsort, and sums absolute differences of sorted pairs. Prints each distance and the total. 🧮
* main: Runs countLines for the line count, then returnDist for the total distance. 🚀


# Features:
* Parses 5-digit numbers digit-by-digit, matching the original AoC style. ✍️
* Uses qsort for efficient column sorting. 📈
* Supports up to 1000 lines, sufficient for the 614-line input. ✅
* Prints intermediate distances for debugging. 🖨️



## Input 📥

File: lists.txt

* Format: Each line has two 5-digit integers (10000–99999) separated by spaces, ending with a newline. Example:
80784 47731
81682 36089
22289 41038
...


## Assumptions:

File is in the same directory as the program. 📂
Lines contain exactly two 5-digit numbers with consistent spacing.
Maximum 1000 lines.



## Output 📤

Line Count: The number of lines in the file is <count> 🎯

Pair Distances: For each sorted pair, prints distance is <dist> and Dist is 0 if the difference is zero. 📊

Total Distance: Printed as an unsigned long long, the sum of absolute differences (AoC answer). Example:
The number of lines in the file is 614
distance is 4808
distance is 26067
...
### 1530215

### 🎉 The final number is the solution!


### How to Run 🚀

# Prerequisites:

A C compiler (e.g., gcc). 🛠️
lists.txt in the same directory. 📂


# Compile:
gcc AOC_DAY_1.c -o AOC_DAY_1


# Run:
./AOC_DAY_1


# Output:

See the line count, sorted pair distances, and total distance (the AoC answer). 🖥️



# Notes 📝

Robustness: Assumes valid input (5-digit numbers, correct format). Checks for NULL filename but not file open errors, per the original design. ⚠️
Limitations:
Caps at 1000 lines; larger inputs are truncated. 📏
Malformed input may cause parsing issues. 🚫


Performance: Character-by-character parsing is AoC-style but less efficient. Sorting is O(n log n), fast for 614 lines. ⚡
AoC Context: The total distance solves Day 1, using sorted pairing to minimize differences. 🏆

License 📚
Provided as-is for educational purposes, part of an Advent of Code solution.
