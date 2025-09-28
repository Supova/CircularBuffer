#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>

#define BUFFER_SIZE 128

// Return codes
#define CB_SUCCESS 0
#define CB_ERROR_FULL -1
#define CB_ERROR_NULL -2
#define CB_ERROR_EMPTY -3

typedef struct{
    uint8_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t count;
}CircularBuffer;

void CircularBuffer_Init(CircularBuffer *cb);
int CircularBuffer_Enqueue(CircularBuffer *cb, uint8_t data);
int CircularBuffer_Dequeue(CircularBuffer *cb, uint8_t *data);
#endif