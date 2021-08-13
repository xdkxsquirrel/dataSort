#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "queue.h"

void test_queueInitialization( void )
{
    uint8_t capacity = 10;
    Queue* queue = createQueue( capacity );
    TEST_ASSERT( queue->capacity == capacity );
    destroyQueue( queue );
}

void test_QueueingAndDequeueing( void )
{
    uint8_t capacity = 10;
    Queue* queue = createQueue( capacity );
    for( uint16_t i = 20; i > capacity; i-- )
    {
        enqueue( queue, i );
    }
    for( uint16_t i = 20; i > capacity; i-- )
    {
        TEST_ASSERT_EQUAL_UINT16( i, dequeue( queue ) );
    }
    TEST_ASSERT_EQUAL_UINT16( QUEUE_ERROR, dequeue( queue ) );
    destroyQueue( queue );
}