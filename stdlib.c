#include "stdlib.h"

#ifdef WINDOWS

void* mymalloc(size_t size) {
	HANDLE hHeap = GetProcessHeap();
	LPVOID allocated_heap = HeapAlloc(hHeap, HEAP_ZERO_MEMORY, size);
	return allocated_heap;
}

void myfree(void* addr){
	HeapFree(addr,0,NULL);
}

void myexit(int status) {
	ExitProcess(status);
}

#endif

#ifdef LINUX

void* mymalloc(size_t size) {
	void* addr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (addr == ((void*)-1)) {
		return NULL;
	}
	return addr;
}

void myfree(void* addr) {
	size_t size;
	size_t* a = (size_t*)addr;
	a--;
	size = *a;
	munmap(a,size + sizeof(size));
}

void myexit(int status) {
	//strace returns exit_group(11)
	exit_group(11);
}

#endif