#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "list_read.h"
#include "list_write.h"

int main(int argc, char **argv) {
    FILE  *fp1 = NULL, *fp2 = NULL;
    LIST  *List = NULL;
    NODE  *pNODE;
    double key, max, min, sum;
    int    returnV, flag;
    char   Word[100];

    // Check command-line arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <flag>\n", argv[0]);
        exit(0);
    }

    flag = atoi(argv[3]);

    // Allocate memory for the list
    List = (LIST *) calloc(1, sizeof(LIST));
    if (!List) {
        fprintf(stderr, "Error: Memory allocation for List failed.\n");
        exit(0);
    }

    List->head = NULL;
    List->tail = NULL;
    List->length = 0;

    // Open the output file
    fp2 = fopen(argv[2], "w");
    if (!fp2) {
        fprintf(stderr, "Error: Cannot open file %s for writing.\n", argv[2]);
        exit(0);
    }

    // Process instructions
    while (1) {
        returnV = nextInstruction(Word, &key);

        if (returnV == 0) {
            fprintf(stderr, "Warning: Invalid instruction: %s\n", Word);
            continue;
        }

        if (strcmp(Word, "Stop") == 0) {
            if (fp2) fclose(fp2);
            return 0;
        }

        if (strcmp(Word, "Release") == 0) {
            listRelease(List);
            continue;
        }

        if (strcmp(Word, "Read") == 0) {
            listRelease(List);
            fp1 = fopen(argv[1], "r");
            if (!fp1) {
                fprintf(stderr, "Error: Cannot open file %s for reading.\n", argv[1]);
                exit(0);
            }

            while (fscanf(fp1, "%lf", &key) == 1) {
                if (flag > 0) listAppend(List, key);  // Copying list
                if (flag < 0) listInsert(List, key);  // Reversing list
            }
            fclose(fp1);
            continue;
        }

        if (strcmp(Word, "Print") == 0) {
            listPrint(stdout, List);
            if (abs(flag) == 2) listPrint(fp2, List);
            continue;
        }

        if (strcmp(Word, "Max") == 0) {
            max = listMax(List);
            fprintf(stdout, "Max=%lf\n", max);
            if (abs(flag) == 2) fprintf(fp2, "Max=%lf\n", max);
            continue;
        }

        if (strcmp(Word, "Min") == 0) {
            min = listMin(List);
            fprintf(stdout, "Min=%lf\n", min);
            if (abs(flag) == 2) fprintf(fp2, "Min=%lf\n", min);
            continue;
        }

        if (strcmp(Word, "Sum") == 0) {
            sum = listSum(List);
            fprintf(stdout, "Sum=%lf\n", sum);
            if (abs(flag) == 2) fprintf(fp2, "Sum=%lf\n", sum);
            continue;
        }

        if (strcmp(Word, "Length") == 0) {
            fprintf(stdout, "Length=%d\n", List->length);
            if (abs(flag) == 2) fprintf(fp2, "Length=%d\n", List->length);
            continue;
        }

        if (strcmp(Word, "Write") == 0) {
            listPrint(fp2, List);
            continue;
        }

        if (strcmp(Word, "Search") == 0) {
            if (!List) {
                fprintf(stderr, "Error: listSearch called on a NULL list.\n");
                exit(0);
            }

            pNODE = listSearch(List, key);
            if (pNODE) {
                fprintf(stdout, "Query %lf FOUND in list.\n", pNODE->key);
                if (abs(flag) == 2) fprintf(fp2, "Query %lf FOUND in list.\n", pNODE->key);
            } else {
                fprintf(stdout, "Query %lf NOT FOUND in list.\n", key);
                if (abs(flag) == 2) fprintf(fp2, "Query %lf NOT FOUND in list.\n", key);
            }
            continue;
        }

        if (strcmp(Word, "Insert") == 0) {
            pNODE = listInsert(List, key);
            if (pNODE) {
                fprintf(stdout, "Node with key %lf inserted.\n", pNODE->key);
                if (abs(flag) == 2) fprintf(fp2, "Node with key %lf inserted.\n", pNODE->key);
            } else {
                fprintf(stdout, "No node inserted.\n");
                if (abs(flag) == 2) fprintf(fp2, "No node inserted.\n");
            }
            continue;
        }

        if (strcmp(Word, "Append") == 0) {
            pNODE = listAppend(List, key);
            if (pNODE) {
                fprintf(stdout, "Node with key %lf appended.\n", pNODE->key);
                if (abs(flag) == 2) fprintf(fp2, "Node with key %lf appended.\n", pNODE->key);
            } else {
                fprintf(stdout, "No node appended.\n");
                if (abs(flag) == 2) fprintf(fp2, "No node appended.\n");
            }
            continue;
        }

        if (strcmp(Word, "Delete") == 0) {
            pNODE = listDelete(List, key);
            if (pNODE) {
                fprintf(stdout, "Node with key %lf deleted.\n", pNODE->key);
                if (abs(flag) == 2) fprintf(fp2, "Node with key %lf deleted.\n", pNODE->key);
                free(pNODE);
            } else {
                fprintf(stdout, "No node deleted.\n");
                if (abs(flag) == 2) fprintf(fp2, "No node deleted.\n");
            }
            continue;
        }
    }

    return 1;
}
