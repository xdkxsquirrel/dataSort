#include "Inc/maxHeap.h"

static bool isFull( Heap* heap );
static uint8_t getParentIdx( uint8_t childIdx );
static void swap( uint16_t *x, uint16_t *y );

Heap* createHeap( uint8_t capacity )
{
    Heap* heap = (Heap*) malloc( sizeof( Heap ) );
    heap->capacity = capacity;
    heap->size = 0;
    heap->arr = (uint16_t*) malloc( heap->capacity * sizeof( uint16_t ) );
    return heap;
}

void destroyHeap( Heap* heap )
{
    free( heap->arr );
    free( heap );
}

void insert( Heap* heap, uint16_t item )
{
    if( !isFull( heap ) )
    {
        heap->size++;
    }
    uint8_t heapSortIdx = heap->size - 1;
    heap->arr[heapSortIdx] = item;

    while( heapSortIdx != 0 && heap->arr[getParentIdx(heapSortIdx)] < heap->arr[heapSortIdx] )
    {
        swap( &heap->arr[getParentIdx(heapSortIdx)], &heap->arr[heapSortIdx] );
        heapSortIdx = getParentIdx( heapSortIdx );
    }
}

void printHeap( FILE* output, Heap* heap )
{
    for( int i = heap->size - 1; i >= 0; i-- ) 
    {
        fprintf( output, "%d\n", heap->arr[i]);
    }
}

static bool isFull( Heap* heap )
{
    return( heap->size == heap->capacity );
}

static uint8_t getParentIdx( uint8_t childIdx )
{
    return ( childIdx - 1) / 2;
}

static void swap( uint16_t *x, uint16_t *y ) 
{
    uint16_t temp = *x;
    *x = *y;
    *y = temp;
}




