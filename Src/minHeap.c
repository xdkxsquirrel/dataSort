#include "minHeap.h"

static bool isFull( Heap* heap );
static uint8_t getParentIdx( uint8_t childIdx );
static void swap( uint16_t *x, uint16_t *y );
static void buildMinHeap( Heap* heap );
static int getSmallestIdx( Heap* heap );
static void heapify( Heap* heap, int idx );

static bool firstTimeFull = true;

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
    if( isFull( heap ) )
    {
        if( firstTimeFull )
        {
            buildMinHeap( heap );
            firstTimeFull = false;
        }
        if( heap->arr[0] < item )
        {
            heap->arr[0] = item;
            heapify( heap, 0 );
        }
    }
    else
    {
        heap->arr[heap->size] = item;
        heap->size++;
    }
}

void printHeap( FILE* output, Heap* heap )
{
    if( firstTimeFull )
    {
        buildMinHeap( heap );
        firstTimeFull = false;
    }
    heap->capacity = heap->size;
    for( int i = 0; i < heap->size; i++ ) 
    {
        fprintf( output, "%d\n", heap->arr[0] );
        insert( heap, 0xFFFF );
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

static void buildMinHeap( Heap* heap )
{
    for( int i = heap->size - 1; i >= 0; i-- )
    {
        heapify( heap, i );
    }
}

static void heapify( Heap* heap, int idx )
{
    int leftIdx = 2 * idx + 1;
    int rightIdx = 2 * idx + 2;
    int smallestIdx = idx;
    if( leftIdx < heap->size && heap->arr[leftIdx] < heap->arr[smallestIdx] )
    {
        smallestIdx = leftIdx;
    }
    if( rightIdx < heap->size && heap->arr[rightIdx] < heap->arr[smallestIdx] )
    {
        smallestIdx = rightIdx;
    }
    if( smallestIdx != idx )
    {
        swap( &heap->arr[idx], &heap->arr[smallestIdx] );
        heapify( heap, smallestIdx );
    }
}




