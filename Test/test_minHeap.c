#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "minHeap.h"

void test_heapInitialization( void )
{
    uint8_t capacity = 10;
    Heap* heap = createHeap( capacity );
    TEST_ASSERT( heap->capacity == capacity );
    destroyHeap( heap );
}

void test_heapSorting( void )
{
    uint8_t capacity = 10;
    Heap* heap = createHeap( capacity );
    for( uint16_t i = 20; i > capacity; i-- )
    {
        insert( heap, i );
    }
    for( uint16_t i = capacity; i < capacity; i++ )
    {
        TEST_ASSERT_EQUAL_UINT16( i, heap->arr[0] );
        insert( heap, 0xFFFF );
    }
    destroyHeap( heap );
}