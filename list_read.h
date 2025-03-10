#ifndef LIST_READ_H
#define LIST_READ_H

#include "structs.h"
#include <stdio.h>

// Function prototypes for linked list operations.
void   listPrint(FILE *stream, LIST *pLIST);
NODE  *listSearch(LIST *pLIST, double query);
double listMax(LIST *pLIST);
double listMin(LIST *pLIST);
double listSum(LIST *pLIST);

#endif // LIST_READ_H
