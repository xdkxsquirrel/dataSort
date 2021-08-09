#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define QUEUE_ERROR                          0xFFFF  

typedef struct
{
    uint8_t front, rear, size;
    uint8_t capacity;
    uint16_t* arr;
}Queue;

Queue* createQueue( uint8_t capacity );
void destroyQueue( Queue* queue );
void enqueue( Queue* queue, uint16_t item );
uint16_t dequeue( Queue* queue );

#endif /* __QUEUE_H__ */