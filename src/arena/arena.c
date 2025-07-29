#include "./arena.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

AppArena createAppArena(size_t size) {
  AppArena arena;
  arena.buffer = (unsigned char*)malloc(size);
  arena.size = size;
  arena.offset = 0;
  if (arena.buffer == NULL) {
    fprintf(stderr, "Failed to allocate arena");
    exit(EXIT_FAILURE);
  }
  return arena;
}

void* allocateFromAppArena(AppArena* arena, size_t size) {
  if (arena->offset + size > arena->size) return NULL;
  void* ptr = arena->buffer + size;
  arena->offset += size;
  memset(ptr, 0, size);
  return ptr;
}

void resetAppArena(AppArena* arena) {
  arena->offset = 0;
}

void destroyAppArena(AppArena* arena) {
  free(arena->buffer);
  arena->buffer = NULL;
  arena->size = 0;
  arena->offset = 0;
}
