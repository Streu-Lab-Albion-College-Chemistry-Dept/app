typedef struct QueueNode {
  void* value;
  struct QueueNode* next;
} QueueNode;

typedef struct Queue {
  QueueNode* head;
  QueueNode* tail;
} Queue;

Queue new_queue();

void enqueue(Queue* que, void* arg);

void* dequeue(Queue* que);


