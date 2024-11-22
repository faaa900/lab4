#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
int processFile(const char *sourceFile, const char *destinationFile);

int main() {
    const char *sourceFile = "data.txt";
    const char *destinationFile = "output.txt";

    int invalidCount = processFile(sourceFile, destinationFile);
    if (invalidCount >= 0) {
        printf("Processing completed. Invalid float count: %d\n", invalidCount);
    } else {
        printf("Error occurred during file processing.\n");
    }

    return 0;
}

int processFile(const char *sourceFile, const char *destinationFile) {
    FILE *src = fopen(sourceFile, "r");
    if (!src) {
        perror("Error opening source file");
        return -1;
    }

    FILE *dest = fopen(destinationFile, "w");
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return -1;
    }

    char buffer[50];
    float value;
    int invalidCount = 0;

    while (fscanf(src, "%49s", buffer) == 1) {
        // Try to parse the float
        if (sscanf(buffer, "%f", &value) == 1) {
            fprintf(dest, "%f\n", value);
        } else {
            invalidCount++;
        }
    }

    // Check for hardware failure
    if (ferror(src)) {
        perror("Error reading source file");
        fclose(src);
        fclose(dest);
        return -1;
    }

    fclose(src);
    fclose(dest);
    return invalidCount;
}
