#ifndef __SORTEDVALUESLIST_H__
#define __SORTEDVALUESLIST_H__

#include <stdint.h>
#include <stdio.h>
#include "minHeap.h"

#define SIZE_OF_HEAP                        32

void initSortedValuesList( void );
void deInitSortedValuesList( void );
void addCurrentValueToSortedValuesList( uint16_t currentValue );
void printSortedValuesList( FILE* output );
uint8_t getHeapSize( void );
uint16_t getHeapArrValueAtIndex( uint8_t idx );

#endif /* __SORTEDVALUESLIST_H__ */