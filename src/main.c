#include <stdio.h>

#include "circular_buffer.h"

int main() {
  CircularBuffer cb;
  CircularBuffer_Init(&cb);
  CircularBuffer_Enqueue(&cb, 25);

  printf("%d\n", cb.buffer[cb.tail]);

  uint8_t value;
  int ret = CircularBuffer_Dequeue(&cb, &value);
  if (ret == CB_SUCCESS) {
    printf("Dequeued: %d\n", value);
  } 
  else {
    printf("Error: %d\n", ret);
}

}