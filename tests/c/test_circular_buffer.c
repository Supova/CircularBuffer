#include "circular_buffer.h"
#include <assert.h>

void test_CircularBuffer_Init(){
    CircularBuffer cb;
    CircularBuffer_Init(&cb);
    assert(cb.head == 0);
    assert(cb.tail == 0);
    assert(cb.full == false);
}
