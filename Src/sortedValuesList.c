#include "sortedValuesList.h"

static Heap* sortedValuesList;

void initSortedValuesList( void )
{
    sortedValuesList = createHeap( SIZE_OF_HEAP );
}

void deInitSortedValuesList( void )
{
    destroyHeap( sortedValuesList );
}

void addCurrentValueToSortedValuesList( uint16_t currentValue )
{  
    insert( sortedValuesList, currentValue );
}

void printSortedValuesList( FILE* output )
{
    fprintf( output, "--Sorted Max 32 Values--\n" );
    printHeap( output, sortedValuesList );
}