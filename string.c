#include "string.h"

size_t mystrlen(char* str) {
	size_t size = 0;
	while (*str != 0x00) {
		str++;
		size++;
	}
	return size;
}


void mymemcpy(void* destination, void* source, size_t size) {
	char* dst_first = ((char*)destination);
	char* src_first = ((char*)source);
	for (unsigned int i = 0; i < size; i++) {
		*dst_first = *src_first;
		dst_first++;
		src_first++;
	}
}


void mymemset(void* destination, char src, size_t size) {
	char* dst_byte = (char*)destination;
	for (unsigned int i = 0; i < size; i++) {
		*dst_byte = src;
		dst_byte++;
	}
}


void mymemmove(void* destination, void* source, size_t size) {

	char* temp = (char*)mymalloc(size);
	if (temp == NULL) {
		return;
	}
	mymemcpy(temp, source, size);
	mymemcpy(destination, temp, size);
	myfree(temp);
}


int mymemcmp(void* addr1, void* addr2, size_t size) {
	int r = 0;
	unsigned char* byte1 = (unsigned char*)addr1;
	unsigned char* byte2 = (unsigned char*)addr2;
	for (size_t i = 0; i < size; i++) {
		if ((*byte1 - *byte2) > 0) {
			r++;
		}
		else if ((*byte1 - *byte2) < 0) {
			r--;
		}
		byte1++;
		byte2++;
	}
	return r;
}


void* mymemchr(void* addr, int chr, size_t size) {
	unsigned char* byte = (unsigned char*)addr;
	void* ret = NULL;
	for (size_t i = 0; i < size && ret == NULL; i++) {
		if (*byte == (unsigned char)chr) {
			ret = byte;
		}
		byte++;
	}
	return ret;
}


char* mystrstr(const char* addr1, const char* addr2) {
	char* ret = NULL;
	char* tmp = NULL;
	while (*addr1 && *addr2) {
		if (*addr1 == *addr2) {
			ret = addr1;
			tmp = addr2;
			while (*addr1 == *tmp) {
				tmp++;
				addr1++;
				if (!*tmp) {
					goto exit;
				}
			}
			ret = NULL;

		}
		addr1++;
	}
exit:
	return ret;
}

int mystrcmp(char* string1, char* string2) {
	// unlike the original strcmp, my implementation returns 1 if string1 is equal to string2
	// if string1 is not equal to string2 it returns 0

	int r = 1;
	unsigned char* byte1 = (unsigned char*)string1;
	unsigned char* byte2 = (unsigned char*)string2;
	while (r == 1) {
		if ((*byte1 != *byte2) || ((*byte1 == 0x00 && *byte2 != 0x00) || (*byte2 == 0x00 && *byte1 != 0x00))) {
			r = 0;
		}
		byte1++;
		byte2++;
	}
	return r;
}