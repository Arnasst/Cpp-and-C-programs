//Arnas Stonkus
//2020-12-14
//Version 1.0
#ifndef NODES_H_INCLUDED
#define NODES_H_INCLUDED

#include "nodes.c"

void createNodes(node **first, int size);

void printAll(node *first);

void printNode(node *first, int number); //skaiciuoja nuo 0

void deleteNode(node **first, int number);

void clearAll(node **first);


#endif // NODES_H_INCLUDED
