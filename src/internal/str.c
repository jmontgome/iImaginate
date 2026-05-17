#include "../global.h"

size_t strLen(const char* str) {
	if (!str) return 0;

	size_t len = 0;
	for (int i = 0; i < MAX_STRING_LENGTH; i++) {
		if (str[i] == '\0') {
			return len;
		}
		len++;
	}

	return MAX_STRING_LENGTH;
}
s64 strIndexOf(const char* str, const char ch) {
	if (!str) return 0;
	
	s64 len = strLen(str);
	for (s64 i = 0; i < len; i++) {
		if (str[i] == ch) {
			return i;
		}
	}
	return -1;
}

s8 strIsNumber(const char* str) {
	if (!str) return 0;
	if (str[0] == '-' && str[1] == '\0') return 0;

	s64 len = strLen(str);
	for (int i = 0; i < len; i++) {
		if ((char)str[i] == '-' && i == 0) {
			 continue;
		}
		if ((char)str[i] < 0x30 || (char)str[i] > 0x39) {
			return 0;
		}
	}
	return 1;
}
s8 strContains(const char* str, const char ch) {
	return strIndexOf(str, ch) != -1;
}
s8 strMatches(const char* strA, const char* strB) {
	if (!strA || !strB) return 0;
	
	s64 len1 = strLen(strA);
	s64 len2 = strLen(strB);

	if (len1 != len2) return 0;

	for (s64 i = 0; i < len1; i++) {
		if (strA[i] != strB[i]) return 0;
	}
	return 1;
}

char* strConcatAlloc(const char* strA, const char* strB) {
	if (strA && strB) {
		s64 len1 = strLen(strA);
		s64 len2 = strLen(strB);
		char* newStr = malloc(sizeof(char) * (len1 + len2 + 1));
		for (s64 i = 0; i < len1; i++) {
			newStr[i] = strA[i];
		}
		for (s64 a = 0; a < len2; a++) {
			newStr[a + len1] = strB[a];
		}
		newStr[len1 + len2] = '\0';
		return newStr;
	}
	return NULL;
}
