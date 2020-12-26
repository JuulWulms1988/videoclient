#include "JW_88_vlcClient--exec.h"

static void* open() { 
	fehMes(0, 0);
	int bTim, bufL;
	for (char x = 0;;) x = prepFunc(x, &bufL, &bTim), func(execBufgetP(x), bufL, bTim);
}

static void func(char* buf, int bufL, int funcTime) {
	if (vlcOffCF(buf) && (!vlcMode || (fehMes(0, 1), vlcClosePlayer()))) return;
	if (vlcSrcCF(buf, bufL) && vlcSrcPssF(buf, bufL, funcTime)) return;
}