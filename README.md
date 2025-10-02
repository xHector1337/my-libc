# my-libc
My implementation of libc.

# [WIP] Currently supported functions:

## stdlib

- (my)malloc (achieved through HeapAlloc & mmap syscalls)
- (my)free (achieved through HeapFree & munmap syscalls)
- (my)exit (achieved through ExitProcess & exit_group syscalls)
- (my)system (achieved through CreateProcessA & execve syscalls)

## string

- (my)strlen (my own implementation)
- (my)memcpy (my own implementation)
- (my)memset (my own implementation)
- (my)memmove (my own implementation)
- (my)memcmp (my own implementation)
- (my)memchr (my own implementation)
- (my)strstr (my own implementation)
- (my)strcmp (my own implementation)
### Notes

This is a fun little side project I've just started working on. Contributors are welcome and I hope you like it :D!
