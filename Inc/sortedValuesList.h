#ifndef __SORTEDVALUESLIST_H__
#define __SORTEDVALUESLIST_H__

#include <stdint.h>
#include <stdio.h>
#include "Inc/maxHeap.h"

#define SIZE_OF_HEAP                        32

void initSortedValuesList( void );
void deInitSortedValuesList( void );
void addCurrentValueToSortedValuesList( uint16_t currentValue );
void printSortedValuesList( FILE* output );

#endif /* __SORTEDVALUESLIST_H__ */