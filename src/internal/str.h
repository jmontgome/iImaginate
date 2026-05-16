\#ifndef STR_H
#define STR_H

#define MAX_STRING_LENGTH 1024

#include "types.h"

// To do:
//	Add safe and unsafe string calls

s64 strLen(const char* str);
s64 strIndexOf(const char* str, const char ch);

s8 strIsNumber(const char* str);
s8 strContains(const char* str, const char ch);
s8 strMatches(const char* strA, const char* strB);

char* strConcatAlloc(const char* strA, const char* strB);

#endif
