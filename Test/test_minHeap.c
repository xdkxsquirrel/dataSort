#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "minHeap.h"

void test_createHeap( void )
{
    uint8_t capacity = 10;
    Heap* heap = createHeap( capacity );
    TEST_ASSERT( heap->capacity == capacity );
}