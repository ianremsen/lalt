#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "mpc.h"
#include "repl.h"
#include "lval.h"

char* concat(char* s1, char* s2) {
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

void copyFile(char* filename) {
    FILE* ifp;
    FILE* ofp;
    char outputFilename[255];
    char inputFilename[255];
    char buffer;

    strcpy(inputFilename, filename);

    ifp = fopen(inputFilename, "r");
    if (ifp == NULL) {
        fprintf(stderr, "Can't open input file %s.\n", inputFilename);
        exit(1);
    }

    strcpy(outputFilename, concat((char*) inputFilename, ".ahk"));
    ofp = fopen(outputFilename, "w+");
    if (ofp == NULL) {
        fprintf(stderr, "Can't open output file %s.\n", outputFilename);
        exit(1);
    }

    do {
        buffer = fgetc(ifp);
        if (buffer != 0xffffffff) {
            fputc(buffer, ofp);
        }
    } while (buffer != EOF);

    fclose(ifp);
    fclose(ofp);
    printf("Input file %s copied to output file %s successfully.\n", inputFilename, outputFilename);
    exit(0);
}

int main(int argc, char** argv) {
    if (argv[1] == NULL) {
        fprintf(stderr, "Error, no parameter specified.\n");
        exit(1);
    }

    if (strcmp(argv[1], "repl") == 0) {
        lalt_repl();
    } else if (strcmp(argv[1], "compile") == 0) {
        // Just copies input to output, for now.
        if (argv[2] == NULL) {
            fprintf(stderr, "Error, no file to compile specified.\n");
            exit(1);
        }

        copyFile(argv[2]);
    } else {
        fprintf(stderr, "Error, invalid parameter %s.\n", argv[1]);
        exit(1);
    }

    return 0;
}
