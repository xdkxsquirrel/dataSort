#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sortedValuesList.h"
#include "minHeap.h"

void setUp(void) 
{

}

void tearDown(void) 
{

}

void test_sortedValuesListInitializations( void )
{
    initSortedValuesList( );
    addCurrentValueToSortedValuesList( 2 );
    TEST_ASSERT_EQUAL_UINT8( 1, getHeapSize( ) );
    deInitSortedValuesList( );
}

void test_addValuesToSortedValuesList( void )
{
    initSortedValuesList( );
    for( uint16_t i = 1; i <= SIZE_OF_HEAP; i++ )
    {
        addCurrentValueToSortedValuesList( i );
        TEST_ASSERT_EQUAL_UINT8( i, getHeapSize( ) );
    }
    for( uint8_t i = 0; i < SIZE_OF_HEAP; i++ )
    {
        TEST_ASSERT_EQUAL_UINT16( (uint16_t)(i+1), getHeapArrValueAtIndex( i ) );
    }
    deInitSortedValuesList( );
}