#include "stdlib.h"

#ifdef WINDOWS

void* mymalloc(size_t size) {
	HANDLE hHeap = GetProcessHeap();
	LPVOID allocated_heap = HeapAlloc(hHeap, HEAP_ZERO_MEMORY, size);
	return allocated_heap;
}

void myfree(void* addr) {
	HeapFree(addr, 0, NULL);
}

void myexit(int status) {
	ExitProcess(status);
}

int mysystem(const char* cmd) {
	STARTUPINFOA startupInfo = { 0 };
	PROCESS_INFORMATION procInfo = { 0 };
	int ret = CreateProcessA(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &procInfo);
	CloseHandle(procInfo.hProcess); CloseHandle(procInfo.hThread);
	return ret;
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
	munmap(a, size + sizeof(size));
}

void myexit(int status) {
	//strace results show exit calls exit_group()
	syscall(SYS_exit_group, status);
}

int mysystem(char* cmd) {
	char* argv[] = { "/bin/bash","-c",cmd,NULL };
	return execve("/bin/bash", argv, NULL);
}

#endif