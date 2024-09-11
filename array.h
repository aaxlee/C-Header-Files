#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Array Array;

struct Array {
  int *array;
  int index; // index to last element + 1
  int capacity;
  
  int (*size)(Array *self); // returns the array's  size in bytes
  void (*print_array)(Array *self);
  void (*resize_array)(Array *self);
  void (*push_back)(Array *self, int num);

};

Array *create_array();
void free_array(Array *arr); // free memory

static int size(Array *self) {
  return sizeof(int) * self->capacity;
}

static void print_array(Array *self) {
    printf("[");
    for (int i = 0; i < self->index; i++) {
        if (i == self->index - 1) printf("%d", self->array[i]);
        else printf("%d, ", self->array[i]);
    }
    printf("]\n");
}

static void resize_array(Array *self) {
  self->capacity *= 2;
  self->array = realloc(self->array, self->capacity * sizeof(int));
}

static void push_back(Array *self, int num) {
  if (self->index >= self->capacity) {
    self->resize_array(self);
  }
  self->array[self->index] = num;
  self->index++;
}

Array *create_array() {
  Array *arr = malloc(sizeof(Array));
  arr->capacity = 1;
  arr->index = 0;
  arr->array = malloc(arr->capacity * sizeof(int));

  arr->size = size;
  arr->print_array = print_array;
  arr->push_back = push_back;
  arr->resize_array = resize_array;
  return arr;
}

void free_array(Array *arr) {
  free(arr->array);
  free(arr);
}

#endif //ARRAY_H