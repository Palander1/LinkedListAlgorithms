#ifndef STRUCTS_H
#define STRUCTS_H

// Node structure representing a single element in the linked list.
typedef struct TAG_NODE {
    double key;        // Value stored in the node.
    struct TAG_NODE *next;  // Pointer to the next node.
} NODE;

// List structure representing the linked list.
typedef struct TAG_LIST {
    NODE *head;  // Pointer to the first node.
    NODE *tail;  // Pointer to the last node.
    int   length; // Number of nodes in the list.
} LIST;

#endif // STRUCTS_H
