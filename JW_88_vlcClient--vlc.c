#include "JW_88_vlcClient--vlc.h"

static void srcWrkF(void* o) {
	unsigned int tim;
	int tD;
	pthread_mutex_lock(&srcSetMut);
	if (retF()) return;
	srcState = srcSet != 1, srcSet = 1, tim = srcSetTime;
	if (!init) init = 1;
	else rcPassF((void*)mainBasString[mainBStr_clear], _RCTPCV_detach(rcType_string), NULL);
	pthread_mutex_unlock(&srcSetMut);
	for (;;) {
		if ((tD = timeDiff(tim + 600, mainTime)) && tD > 0) sleep(tD / 100), usleep((tD % 100) * 10000);
		pthread_mutex_lock(&srcSetMut);
		if (retF()) return;
		if (!srcState) srcState = 1;
		if (srcSet == 2) {
			rcPassF((void*)mainBasString[mainBStr_clear], _RCTPCV_detach(rcType_string), NULL), srcSet = 1, tim = srcSetTime, pthread_mutex_unlock(&srcSetMut);
			continue;
		}
		srcSet = 3, srcPssTypeF(), sleep(1), pthread_mutex_lock(&srcSetMut);
		if ((srcSet == 3 && !(srcSet = -1)) || retF()) return;
		rcPassF((void*)mainBasString[mainBStr_clear], _RCTPCV_detach(rcType_string), NULL), srcSet = 1, tim = srcSetTime, pthread_mutex_unlock(&srcSetMut);
	}
}

char vlcClosePlayer() {
	switch (vlcMode) {
	case vlcMod_on: srcClose(); break;
	} return prepCloseV = 1;
}

void vlcClearF() {
	switch (vlcMode) {
	case vlcMod_on: init = 0; break;
	} rcPassF((void*)mainBasString[mainBStr_clear], _RCTPCV_detach(rcType_string), NULL);

	prepWorkOpen(sleepOne, NULL);
	vlcMode = vlcMod_off; prepCloseV = 2;
}

static void srcClose() {
	pthread_mutex_lock(&srcSetMut);
	char x = srcSet > 2 || (srcSet && !(srcState % 2));
	if (srcSet) srcSet = -1, srcSetTime = mainTime;
	pthread_mutex_unlock(&srcSetMut);
}

static vlcModEn srcModF() {
	return vlcMod_on;
}

static void srcPssTypeF() {
	void *arg; rcTypeEn type;
	type = _RCTPCV_detach(rcType_rcStr), arg = (void*)rcStrGet(), ((rcStrStr*)arg)->l = rcAddcp(((rcStrStr*)arg)->b, "udp://:1234");
	pthread_mutex_unlock(&srcSetMut);
	rcPassF(arg, type, NULL);
}

char vlcSrcPssF(char* buf, int bufL, unsigned int tim) {
	int x;
	sourceL = charCp(source, buf);
	if ((x = fehF(srcModF())) != vlcMode && vlcMode) return vlcClosePlayer();
	switch (!vlcMode && (vlcMode = x), vlcMode) {

	case vlcMod_on: {
		signed char yy;
		pthread_mutex_lock(&srcSetMut);
		if (srcSet == -1) yy = srcSet = 2;
		else if ((yy = srcSet) % 2 || (!srcSet && (srcState = 2))) srcSet++;
		srcSetTime = tim;
		pthread_mutex_unlock(&srcSetMut);
		if (!yy) prepWorkOpen(srcWrkF, NULL);
	} break;

	} return 1;
}

static vlcModEn fehF(vlcModEn x) {
	switch (x) {
	case vlcMod_on: fehFSrc(); break;
	}
	return x;
}

static void fehFSrc() {
	system("killall feh");
	system("xdotool mousemove 9999 9999");
	if (source[4] == 'O') fehMes(1, 0);
	else fehMesChan((source[3] - '0') * 100 + (source[4] - '0') * 10 + (source[5] - '0'));
}

char vlcSrcCF(char* buf, int bufL) { 
	if (bufL < 5 || buf[0] != 'v' || buf[1] != 'l' || buf[2] != 'c') return 0;
	if (bufL >= 6 && buf[3] == ' ' && buf[4] == 'O' && ((bufL == 6 && buf[5] == 'N') || (bufL == 7 && buf[5] == 'F' && buf[6] == 'F'))) return 1;
	else if (bufL == 6 && isNoF(buf[3]) && isNoF(buf[4]) && isNoF(buf[5])) return 1;
	return 0;
}