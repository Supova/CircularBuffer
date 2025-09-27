#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>

#define BUFFER_SIZE 128

// typedef to be changed with specific use case
typedef uint8_t cb_element_t;

// Return codes
#define CB_SUCCESS 0
#define CB_ERROR_FULL -1
#define CB_ERROR_NULL -2

typedef struct{
    cb_element_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t count;
}CircularBuffer;

void CircularBuffer_Init(CircularBuffer *cb);
int CircularBuffer_Enqueue(CircularBuffer *cb, cb_element_t data);

#endif