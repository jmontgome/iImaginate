#include <stdlib.h>

#include "types.h"
#include "str.h"

u64 strLen(char* str) {
	if (!str) return 0;

	for (int i = 0; i < MAX_STRING_LENGTH; i++) {
		if (str[i] == '\0') {
			return i;
		}
	}

	return MAX_STRING_LENGTH;
}
u64 strIndexOf(char* str, char ch) {
	if (!str) return 0;
	
	for (int i = 0; i < strLen(str); i++) {
		if (str[i] == ch) {
			return i;
		}
	}
	return -1;
}

u8 strIsNumber(char* str) {
	if (!str) return 0;

	for (int i = 0; i < strLen(str); i++) {
		if ((char)str[i] == '-' && i == 0) {
			 continue;
		}
		if ((char)str[i] < 0x30 || (char)str[i] > 0x39) {
			return 0;
		}
	}
	return 1;
}
u8 strContains(char* str, char ch) {
	int index = strIndexOf(str, ch);
	if (index == -1) {
		return 0;
	}
	else {
		return 1;
	}
}
u8 strMatches(char* strA, char* strB) {
	if (!strA || !strB) return 0;

	int len1 = strLen(strA);
	int len2 = strLen(strB);

	if (len1 != len2) return 0;

	for (int i = 0; i < len1; i++) {
		if (strA[i] != strB[i]) return 0;
	}
	return 1;
}

char* strConcat_M(char* strA, char* strB) {
	if (strA && strB) {
		int len1 = strLen(strA);
		int len2 = strLen(strB);
		char* newStr = malloc(sizeof(char) * (len1 + len2 + 1));
		for (int i = 0; i < len1; i++) {
			if (strA[i] != '\0') {
				newStr[i] = strA[i];
			}
		}
		for (int a = 0; a < len2; a++) {
			if (strB[a] != '\0') {
				newStr[a + len1] = strB[a];
			}
		}
		newStr[len1 + len2] = '\0';
		return newStr;
	}
}

void freeStr(char* str) {
	str = NULL;
	free(str);
}
