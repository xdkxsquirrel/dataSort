#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    uint8_t size;
    uint8_t capacity;
    uint16_t* arr;
}Heap;

Heap* createHeap( uint8_t capacity );
void destroyHeap( Heap* heap );
void insert( Heap* heap, uint16_t item );
void printHeap( FILE* output, Heap* heap );

#endif /* __MAXHEAP_H__ */