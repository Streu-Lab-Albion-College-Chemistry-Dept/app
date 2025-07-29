#include "./queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue new_queue() {
  return (Queue) {
    .head = NULL,
    .tail = NULL,
  };
}

void enqueue(Queue* queue, void* arg) {
  QueueNode* node = malloc(sizeof(QueueNode));
  if (!node) {
    perror("Failed to create new node");
    exit(EXIT_FAILURE);
  }
  node->value = arg;
  node->next  = NULL;
  if (queue->tail == NULL) {
    queue->head = queue->tail = node;
  } else {
    queue->tail->next = node;
    queue->tail = node;
  }
}

void* dequeue(Queue* queue) {
  if(queue->head == NULL) { return NULL; } 
  QueueNode* temp = queue->head;
  void* value = temp->value;
  queue->head = queue->head->value;
  if (queue->head == NULL) { return NULL; }
  free(temp);
  return value;
}
