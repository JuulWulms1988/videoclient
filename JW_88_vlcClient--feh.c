#include "JW_88_vlcClient--feh.h"

extern void fehMes(short x, char y) {
	if (y) system("killall feh");
	const char* z;
	switch (x) {
	case 0: z = "n.png &"; break;
	case 1: z = "u.png &"; break;
	} charCp(str + 14, (char*)z);
	system(str);
}

extern void fehMesChan(short x) {
	char t = 0;
	if (x / 100) str[14] = (x / 100) + '0', t++, x %= 100;
	if (x / 10) str[14 + t++] = (x / 10) + '0', x %= 10;
	else if (t) str[15] = '0', t++;
	str[14 + t] = x + '0'; x = t;
	charCp(str + 15 + x, ".png &");
	system(str);
}