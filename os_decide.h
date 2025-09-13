#if defined(_WIN32) || defined(__MINGW32__)
#ifndef WINDOWS
#define WINDOWS
#endif
#elif defined(__linux__) && !(defined(WINDOWS))
#ifndef LINUX
#define LINUX
#endif
#endif

#if defined(LINUX) && defined(WINDOWS)
#error Both LINUX and WINDOWS are defined!
#endif

#ifdef WINDOWS
#include <Windows.h>
#endif 

#ifdef LINUX
#include <stddef.h> //for type definitions
#ifdef STDLIB
#include <sys/mman.h> //for mmap syscall
#include <unistd.h> //for exit_group syscall
#endif
#endif