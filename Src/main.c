#include "main.h"

static FILE* input;
static FILE* output;

int main( int argc, char *argv[] )
{
    if( argc != 3 )
    {
        printf( "dataSort requires two arguments. 1) The incoming data filename and 2) the filename to print to (with extensions).\n");
        return -1;
    }
    if( initFiles( argv[1], argv[2] ) )
    {
        return -1;
    }
    initSortedValuesList( );
    initLastValuesList( );

    uint16_t nextValue;
    while( getNextValue( &nextValue ) )
    {
        if( nextValue > 0 )
        {
            addCurrentValueToSortedValuesList( nextValue );
            addCurrentValueToLastValuesList( nextValue );
        }
    }   
    printSortedValuesList( output ); 
    printLastValuesList( output );

    deInitSortedValuesList( );
    deInitLastValuesList( );
    deInitFiles( );
    return 0;
}

bool initFiles( char* inputFileName, char* outputFileName )
{
    bool failure = false;
    input = fopen( inputFileName, "r" );
    output = fopen( outputFileName, "w+" );
    if( input == NULL )
    {
        failure = true;
        printf( "Failure opening %s\n", inputFileName );
    }
    if( output == NULL )
    {
        failure = true;
        printf( "Failure opening %s\n", outputFileName );
    }
    return failure;
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

    /* Because I am reading 12-bit values, I read in 3 bytes, then parse those 24-bits 
       into two 12-bit values and save them to a 16-bit buffer that sends a value alternating
       from the first value then the second value in the buffer. */
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
