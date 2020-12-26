#include "JW_88_vlcClient.h"

static char execBuf[3000];

static void* open();
static void func(char* buf, int bufL, int funcTime);

void execBegin() { static pthread_t p; pthread_create(&p, NULL, open, NULL); }
char* execBufgetP(char x) { return execBuf + x * 1000; }
char execBufgetN(char* x) { return (x - execBuf) / 1000; }