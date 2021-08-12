#include "main.h"

static FILE* input;
static FILE* output;

int main( int argc, char *argv[] )
{
    if( argc != 3 )
    {
        printf( "dataSort requires two arguments. 1) The incoming data filename and 2) the filename to print to.\n");
        return 1;
    }
    initFiles( argv[1], argv[2] );
    initSortedValuesList( );
    initLastValuesList( );

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

void initFiles( char* inputFileName, char* outputFileName )
{
    input = fopen( inputFileName, "r" );
    output = fopen( outputFileName, "w+" );
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