//includes and defines
#include <stdio.h>
#include <stdlib.h>
#define N 5

// Function declarations
int countLines(char *filename);
int returnDist(char *filename);

// Comparison function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Main
int main() {
    int numLines;
    int ColsDists;
    int counts[26] = {0};
    numLines = countLines("lists.txt");
    printf("The number of lines in the file is %d\n", numLines);
    ColsDists = returnDist("lists.txt");
    return 0;
}

// Functionality
// Counting all lines in the file to get file lines number
int countLines(char *filename) {
    if (filename == NULL) {
        printf("Input Error\n");
        return 1;
    }
    FILE *fptr;
    fptr = fopen(filename, "r");
    char c = 0;
    int count = 0;
    for (c = getc(fptr); c != EOF; c = getc(fptr)) {
        if (c == '\n') {
            count = count + 1;
        }
    }
    fclose(fptr);
    return count;
}

int returnDist(char *filename) {
    if (filename == NULL) {
        printf("Input Error\n");
        return -1;
    }

    FILE *fptr;
    fptr = fopen(filename, "r");
    char c = getc(fptr);
    unsigned int firstCol[1000][N] = {0};
    unsigned int secondCol[1000][N] = {0};
    unsigned int line = 0, i = 0, j = 0, count = 0;
    unsigned int firstNum[1000] = {0}, secondNum[1000] = {0};

    // Read all lines into arrays
    while (c != EOF) {
        if (c != ' ' && c != '\n') {
            if (count < N) {
                firstCol[line][i] = c - '0';
                i++;
            } else if (count >= N) {
                secondCol[line][j] = c - '0';
                j++;
            }
            count++;
        }

        if (c == '\n') {
            for (int k = 0; k < N; k++) {
                firstNum[line] = firstNum[line] * 10 + firstCol[line][k];
                secondNum[line] = secondNum[line] * 10 + secondCol[line][k];
            }
            line++;
            line++;
            i = j = count = 0;
            if (line >= 1000) break;
        }
        c = getc(fptr);
    }
    fclose(fptr);

    // Sort the arrays
    qsort(firstNum, line, sizeof(unsigned int), cmpfunc);
    qsort(secondNum, line, sizeof(unsigned int), cmpfunc);

    // Compute total distance
    unsigned long long total = 0;
    unsigned int dist;
    for (int k = 0; k < line; k++) {
        dist = (firstNum[k] > secondNum[k]) ? (firstNum[k] - secondNum[k]) : (secondNum[k] - firstNum[k]);
        total += dist;
        if (dist == 0) {
            printf("Dist is 0\n");
        }
        printf("distance is %d\n", dist);
    }
    printf("%llu\n", total);
    return 0;
}
