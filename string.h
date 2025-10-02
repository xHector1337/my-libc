#include "os_decide.h"
#include "stdlib.h"

size_t mystrlen(char* str);

void mymemcpy(void* destination, void* source, size_t size);

void mymemset(void* destination, char src, size_t size);

void mymemmove(void* destination, void* source, size_t size);

int mymemcmp(void* addr1, void* addr2, size_t size);

void* mymemchr(void* addr, int chr, size_t size);

char* mystrstr(char* addr1, char* addr2);

int mystrcmp(char* string1, char* string2);