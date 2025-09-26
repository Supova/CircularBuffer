#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>

#define BUFFER_SIZE 100

typedef struct{
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    int capacity;
    bool full_flag;
}CircularBuffer;

#endif