#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stdint.h>

#define BUFFER_SIZE 128

typedef struct{
    uint8_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
    bool full;
}CircularBuffer;

#endif