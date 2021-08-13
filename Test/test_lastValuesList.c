#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lastValuesList.h"
#include "queue.h"

void test_lastValuesListInitializations( void )
{
    initLastValuesList( );
    addCurrentValueToLastValuesList( 2 );
    TEST_ASSERT_EQUAL_UINT8( 1, getQueueSize( ) );
    deInitLastValuesList( );
}

void test_addAndRemoveFromValuesList( void )
{
    initLastValuesList( );
    for( uint16_t i = 1; i <= SIZE_OF_QUEUE; i++ )
    {
        addCurrentValueToLastValuesList( i );
        TEST_ASSERT_EQUAL_UINT8( i, getQueueSize( ) );
    }
    for( uint16_t i = 1; i <= SIZE_OF_QUEUE; i++ )
    {
        TEST_ASSERT_EQUAL_UINT16( i, getValueFromLastValuesList( ) );
    }
    deInitLastValuesList( );
}