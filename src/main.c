#include <stdio.h>

#include "circular_buffer.h"

int main() {
  CircularBuffer cb;
  CircularBuffer_Init(&cb);
  CircularBuffer_Enqueue(&cb, 25);

  printf("%d\n", cb.buffer[cb.tail]);
}