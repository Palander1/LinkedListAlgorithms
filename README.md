# Linked List Algorithms

## Overview

PJ1 is a **C++ program** that performs various operations on linked lists, such as insertion, deletion, searching, and computing statistics like max, min, and sum. The program reads commands from standard input and manipulates a linked list accordingly.

## Features

- Read a linked list from a file
- Insert, append, and delete nodes
- Find the maximum, minimum, and sum of all node values
- Print the current list
- Save the list to an output file

## File Structure

- **main.cpp** - Main program handling user input and operations
- **util.cpp** - Utility functions for reading commands
- **list_read.cpp** - Functions for reading and searching the linked list
- **list_write.cpp** - Functions for modifying the linked list
- **structs.h** - Data structures (NODE and LIST)
- **util.h** - Header for utility functions
- **list_read.h** - Header for list reading functions
- **list_write.h** - Header for list modification functions
- **Makefile** - Compilation instructions
- **README.md** - Project documentation

## Compilation

To compile the project, use the provided Makefile:

make

This generates an executable named `PJ1`.

## Usage

Run the program with the following syntax:

./PJ1 <input_file> <output_file> <flag>

- `<input_file>`: File containing numbers to create the linked list
- `<output_file>`: Destination for writing output
- `<flag>`: Determines list insertion order
  - `1`  : Insert elements at the tail (copying the list)
  - `-1` : Insert elements at the head (reversing the list)
  - `2`  : Save all output operations to the file as well

## Commands

The program processes the following commands:

- **Read** - Reads numbers from `<input_file>` into the list
- **Print** - Prints the list to stdout (or file if `flag == 2`)
- **Max** - Displays the maximum value in the list
- **Min** - Displays the minimum value in the list
- **Sum** - Displays the sum of all values in the list
- **Length** - Displays the number of nodes in the list
- **Write** - Saves the current list to `<output_file>`
- **Search <key>** - Searches for a key in the list and prints the result
- **Insert <key>** - Inserts a node with `<key>` at the head
- **Append <key>** - Appends a node with `<key>` at the tail
- **Delete <key>** - Deletes a node with `<key>`
- **Release** - Clears the linked list from memory
- **Stop** - Terminates the program

## Cleaning Up

To remove compiled files:

make clean
