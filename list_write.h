#ifndef LIST_WRITE_H
#define LIST_WRITE_H

#include "structs.h"

// Function prototypes for list modification operations.
NODE  *listInsert(LIST *pLIST, double key);
NODE  *listAppend(LIST *pLIST, double key);
NODE  *listDelete(LIST *pLIST, double key);
void   listRelease(LIST *pLIST);

#endif // LIST_WRITE_H
