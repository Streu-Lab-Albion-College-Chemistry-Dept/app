#include <stdint.h>
#include <stdlib.h>

typedef struct {
  unsigned char* buffer;
  size_t         size;
  size_t         offset;
} AppArena;

AppArena createAppArena(size_t size);

void* allocateFromAppArena(AppArena* arena, size_t size);

void resetAppArena(AppArena* arena);

void destroyAppArena(AppArena* arena);
