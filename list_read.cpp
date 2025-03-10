#include "list_read.h"
#include <stdio.h>
#include <stdlib.h>

// Prints the contents of the linked list.
void listPrint(FILE *stream, LIST *pLIST) {
    if (!pLIST) {
        fprintf(stderr, "Error: listPrint received a NULL list.\n");
        exit(0);
    }

    fprintf(stream, "Length=%d\n", pLIST->length);
    NODE *pNODE = pLIST->head;
    
    while (pNODE) {
        fprintf(stream, "%lf\n", pNODE->key);
        pNODE = pNODE->next;
    }
}

// Searches for a node containing a specific value in the list.
NODE *listSearch(LIST *pLIST, double query) {
    if (!pLIST) {
        fprintf(stderr, "Error: listSearch received a NULL list.\n");
        exit(0);
    }

    NODE *pNODE = pLIST->head;
    while (pNODE) {
        if (pNODE->key == query) {
            return pNODE;
        }
        pNODE = pNODE->next;
    }

    return NULL;
}

// Finds the maximum value in the list.
double listMax(LIST *pLIST) {
    if (!pLIST) {
        fprintf(stderr, "Error: listMax received a NULL list.\n");
        exit(0);
    }
    if (!pLIST->head) {
        fprintf(stderr, "Error: listMax received an empty list.\n");
        exit(0);
    }

    double max = pLIST->head->key;
    NODE *pNODE = pLIST->head->next;
    
    while (pNODE) {
        if (pNODE->key > max) {
            max = pNODE->key;
        }
        pNODE = pNODE->next;
    }

    return max;
}

// Finds the minimum value in the list.
double listMin(LIST *pLIST) {
    if (!pLIST) {
        fprintf(stderr, "Error: listMin received a NULL list.\n");
        exit(0);
    }
    if (!pLIST->head) {
        fprintf(stderr, "Error: listMin received an empty list.\n");
        exit(0);
    }

    double min = pLIST->head->key;
    NODE *pNODE = pLIST->head->next;
    
    while (pNODE) {
        if (pNODE->key < min) {
            min = pNODE->key;
        }
        pNODE = pNODE->next;
    }

    return min;
}

// Computes the sum of all values in the list.
double listSum(LIST *pLIST) {
    if (!pLIST) {
        fprintf(stderr, "Error: listSum received a NULL list.\n");
        exit(0);
    }
    if (!pLIST->head) {
        fprintf(stderr, "Error: listSum received an empty list.\n");
        exit(0);
    }

    double sum = 0;
    NODE *pNODE = pLIST->head;
    
    while (pNODE) {
        sum += pNODE->key;
        pNODE = pNODE->next;
    }

    return sum;
}
