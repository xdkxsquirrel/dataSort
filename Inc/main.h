#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "Inc/lastValuesList.h"
#include "Inc/sortedValuesList.h"

#define BUFFER_SIZE                        3
#define EIGHT_BIT_TO_TWELVE_BIT            4
#define EIGHT_BIT_TO_FOUR_BIT              4
#define FOUR_BIT_TO_TWELVE_BIT             8
#define STRIP_FIRST_FOUR_BITS              15

void initFiles( void );
void deInitFiles( void );
bool getNextValue( uint16_t *nextValue );


#endif /* __MAIN_H__ */