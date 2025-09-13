#include "os_decide.h"
#include "stdlib.h"

size_t mystrlen(char* str);

void mymemcpy(void* destination, const void* source, size_t size);

void mymemset(void* destination, char src, size_t size);

void mymemmove(void* destination, const void* source, size_t size);

int mymemcmp(const void* addr1, const void* addr2, size_t size);

void* mymemchr(const void* addr, int chr, size_t size);

char* mystrstr(const char* addr1, const char* addr2);