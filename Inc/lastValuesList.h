#ifndef __LASTVALUESLIST_H__
#define __LASTVALUESLIST_H__

#include <stdint.h>
#include <stdio.h>
#include "queue.h"

#define SIZE_OF_QUEUE                        32

void initLastValuesList( void );
void deInitLastValuesList( void );
void addCurrentValueToLastValuesList( uint16_t currentValue );
void printLastValuesList( FILE* output );

#endif /* __LASTVALUESLIST_H__ */