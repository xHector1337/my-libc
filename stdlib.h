#define STDLIB
#include "os_decide.h"


void* mymalloc(size_t size);
void myfree(void* addr);

void myexit(int status);

int mysystem(char* cmd);