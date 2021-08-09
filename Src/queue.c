#include "Inc/queue.h"

static bool isFull( Queue* queue );
static bool isEmpty( Queue* queue );

Queue* createQueue( uint8_t capacity )
{
    Queue* queue = (Queue*) malloc( sizeof( Queue ) );
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (uint16_t*) malloc( queue->capacity * sizeof( uint16_t ) );
    return queue;
}

void destroyQueue( Queue* queue )
{
    free( queue->arr );
    free( queue );
}

void enqueue( Queue* queue, uint16_t item )
{
    if( isFull( queue ) )
    {
        dequeue( queue );
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
}

uint16_t dequeue( Queue* queue )
{
    if( isEmpty( queue ) )
        return QUEUE_ERROR;
    uint16_t item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

static bool isFull( Queue* queue )
{
    return( queue->size == queue->capacity );
}

static bool isEmpty( Queue* queue )
{
    return( queue->size == 0 );
}