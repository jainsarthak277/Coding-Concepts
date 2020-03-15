/*

Implement an ring (circular) buffer with array.

- Define a custome type buf_t to hold the data.
- Write some APIs to operate it.
- Write some testings in main()

*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// Define new data structure buf_t here
typedef struct buf_t
{
  int front, rear, size, capacity;
  void* arr;
  size_t type;
} buf_t;


// Create new buffer object and initialize it
buf_t *buf_new(size_t item_size, size_t max_size) {
  buf_t* buf = (buf_t*)malloc(sizeof(buf_t));
  buf->front = 0;
  buf->rear = -1;
  buf->type = item_size;
  buf->size = 0;
  buf->capacity = (int)max_size;
  buf->arr = (void*)malloc(item_size*max_size);
  return buf;
}


// Put data into buffer's tail. Note that the buffer doesn't hold the pointer of data, but has a **copy**.  
// Return 0 if data is put in, -1 on failure.
int buf_put(buf_t *buf, const void *data) {
  if((buf->size != 0) && (buf->front == buf->rear)) {
   return -1;
  }

  buf->rear = (buf->rear + 1)%(buf->size);
  //memcpy(buf->arr[buf->rear], data, buf->type);
  *(float*)(buf->arr + buf->rear) = *(float*)data;
  buf->size++;
  return 0;
}



// Get value from buffer's head (the earliest position). Copy value out to data_out.
// Return 0 if data is got, -1 on failure.
/*int buf_get(buf_t *buf, void *data_out) {
  if(buf->size == 0) {
     return -1;
    }
  memcpy(data_out, buf->arr[buf->front], buf->type);
  buf->front = (buf->front + 1)%buf->size;
  buf->size--;
  return *data_out;
}
*/

// How many items are in the buffer?
size_t buf_size(buf_t *buf) {
    return (size_t)(buf->size);
}
   
   
int main() {
 
  // Write some simple testings here...
  buf_t *buf = buf_new(sizeof(float), 10);

  for (int i = 0; i < 15; i++) {    
     buf_put(buf, &i);
  }

  for(int i=0; i<15; i++) {
     printf("%f, ", *(float*)(buf->arr + i));
  }
   
  __attribute__((unused)) int out;
  for (int i = 0; i < 10; i++) {    
//     buf_get(buf, &out);
//     assert(out == i);
  }
   
  return 0;
}
