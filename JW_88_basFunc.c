#include "JW_88_basFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char bsBreakChar(char x) { for (char t = 0, ar[] = { ' ', '\r', '\n', '\0' }; t < 3; ) if (x == ar[t++]) return 1; return 0; }
char vergCharP(char* x, char* y) { for (;; x++, y++) if (*x == '\0') return *y == '\0'; else if (*y == '\0' || *x != *y) return 0; }
int charCp(char* x, char* y) { int t = 0; while ((*x++ = *y++) != '\0') t++; return t; }
char isNoF(char x) { return x >= '0' && x <= '9'; }

char vergCharPH(char* x, char* y) {
	for (;;) {
		if (*x == '\0') return *y == '\0';
		else if (*y == '\0') return 0;
		if (*x != *y)
			if (*x >= 'a' && *x <= 'z') { if (*x - ('a' - 'A') != *y) return 0; }
			else if (*x >= 'A' && *x <= 'Z') { if (*x + ('a' - 'A') != *y) return 0; }
			else return 0;
		x++, y++;
	}
}

int timeDiff(unsigned int x, unsigned int y) {
	if (y < x) x -= y;
	else x += 1 + ((unsigned int)(-1) - y);
	if (y = x > (unsigned int)(-1) / 2) x = ((unsigned int)(-1) - x) + 1;
	return x * (1 - (y * 2));
}