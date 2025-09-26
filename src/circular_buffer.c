#include "circular_buffer.h"

void CircularBuffer_Init(CircularBuffer *cb){
    cb->head = 0;
    cb->tail = 0;
    cb->full = false;
}