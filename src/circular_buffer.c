#include "circular_buffer.h"
#include <stddef.h>

#define CB_SUCCESS 0
#define CB_ERROR_FULL -1
#define CB_ERROR_NULL -2


void CircularBuffer_Init(CircularBuffer *cb){
    if (cb == NULL){
        return;
    }

    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}


int CircularBuffer_Enqueue(CircularBuffer *cb, cb_element_t data){
    if (cb == NULL){
        return CB_ERROR_NULL;
    }
    
    // reject data overwrite
    if (cb->count == BUFFER_SIZE){
        return CB_ERROR_FULL;
    }

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;

    return CB_SUCCESS;
}