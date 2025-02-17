#include "game_memory.h"

#include "db.h"
#include "dictionary.h"
#include "memory.h"
#include "memory_manager.h"

// 0x44B250
int gameMemoryInit()
{
    dictionarySetMemoryProcs(internal_malloc, internal_realloc, internal_free);
    sub_4C68B8(internal_malloc, internal_strdup, internal_free);
    memoryManagerSetProcs(gameMemoryMalloc, gameMemoryRealloc, gameMemoryFree);

    return 0;
}

// 0x44B294
void* gameMemoryMalloc(size_t size)
{
    return internal_malloc(size);
}

// 0x44B29C
void* gameMemoryRealloc(void* ptr, size_t newSize)
{
    return internal_realloc(ptr, newSize);
}

// 0x44B2A4
void gameMemoryFree(void* ptr)
{
    internal_free(ptr);
}
