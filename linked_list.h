#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Linked_list Linked_list;

struct Linked_list {
  char *data;
  Linked_list *prev;
  Linked_list *next;

  void (*add_node)(Linked_list *self, Linked_list *node);
  void (*remove_last_node)(Linked_list *self);
  void (*print_linked_list)(Linked_list *self);
};

static void add_node(Linked_list *self, Linked_list *node);
static void remove_last_node(Linked_list *self);
static void print_linked_list(Linked_list *self);
Linked_list *remove_head(Linked_list *head);
Linked_list *init_linked_list(char *data);

static void add_node(Linked_list *self, Linked_list *node) {
  Linked_list *current = self;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = node;
  node->prev = current;
}

static void remove_last_node(Linked_list *self) {
  Linked_list *current = self;
  while (current->next != NULL) {
    current = current->next;
  }
  current->prev->next = NULL;
  free(current);
}

static void print_linked_list(Linked_list *self) {
  printf("[");
  while (self != NULL) {
    if (self->next == NULL) {
      printf("%s", self->data);
      break;
    }
    printf("%s, ", self->data);
    self = self->next;
  }
  printf("]\n");
}

Linked_list *remove_head(Linked_list *head) {
  Linked_list *new_head = head->next;
  free(head);
  new_head->prev = NULL;
  return new_head;
}

Linked_list *init_linked_list(char *data) {
  Linked_list *head = malloc(sizeof(Linked_list));

  head->add_node = add_node;
  head->remove_last_node = remove_last_node;
  head->print_linked_list = print_linked_list;

  head->data = data;
  head->prev = NULL;
  head->next = NULL;

  return head;
}

#endif //LINKED_LIST_H