#include "Inc/lastValuesList.h"

static Queue* lastValuesList;

void initLastValuesList( void )
{
    lastValuesList = createQueue( SIZE_OF_QUEUE );
}

void deInitLastValuesList( void )
{
    destroyQueue( lastValuesList );
}

void addCurrentValueToLastValuesList( uint16_t currentValue )
{  
    enqueue( lastValuesList, currentValue );
}

void printLastValuesList( FILE* output )
{
    fprintf( output, "--Last 32 Values--\n" );
    for( uint16_t i = 0; i < 32; i++ )
    {
        fprintf( output, "%d\n", dequeue( lastValuesList ) );
    }
}