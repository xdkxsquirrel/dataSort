#include "Inc/main.h"

static FILE* input;
static FILE* output;

int main()
{
    initFiles( );
    initLastValuesList( );
    initSortedValuesList( );

    uint16_t nextValue;
    while( getNextValue( &nextValue ) )
    {
        addCurrentValueToSortedValuesList( nextValue );
        addCurrentValueToLastValuesList( nextValue );
    }   
    printSortedValuesList( output ); 
    printLastValuesList( output );

    deInitSortedValuesList( );
    deInitLastValuesList( );
    deInitFiles( );
    return 0;
}

void initFiles( void )
{
    input = fopen( "test1.bin", "r" );
    output = fopen( "test1.out", "w+" );
}

void deInitFiles( void )
{
    fclose( input );
    fclose( output );
}

bool getNextValue( uint16_t *nextValue )
{
    static uint8_t whichTwelveBitValueInBuffer;
    static uint8_t buffer[BUFFER_SIZE];

    if( whichTwelveBitValueInBuffer == 0 )
    {
        whichTwelveBitValueInBuffer = 1;
        if( fgets( buffer, BUFFER_SIZE + 1, input ) != NULL )
        {
            *nextValue = ((uint16_t)buffer[0] << EIGHT_BIT_TO_TWELVE_BIT) + (buffer[1] >> EIGHT_BIT_TO_FOUR_BIT);
        }
        else
        {
            return false;
        }
    }
    else
    {
        whichTwelveBitValueInBuffer = 0;
        *nextValue = ((uint16_t)( buffer[1] & STRIP_FIRST_FOUR_BITS) << FOUR_BIT_TO_TWELVE_BIT) + buffer[2];
    }

    return true;
}