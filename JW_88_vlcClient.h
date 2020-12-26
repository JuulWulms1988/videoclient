#ifndef JW_88_vlcClient_H_   
#define JW_88_vlcClient_H_

#include "JW_88_workerThreads.h"
#include "JW_88_tcpServer.h"
#include "JW_88_basfunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

//global declarations
typedef enum { vlcMod_off, vlcMod_on } vlcModEn;
	//main
		enum { mainBStr_shtdwn, mainBStr_clear};
		extern const char* mainBasString[];
		extern unsigned int mainTime;


	//Executor
		extern void execBegin();
		extern char* execBufgetP(char x);
		extern char execBufgetN(char* x);
		

	//Prep
		enum { prepMainWorker };

		extern __workerTh_ prepWorkObj;
		extern char prepCloseV;
		extern char prepFunc(char bufP, int* bufLP, int* bTimP);
		extern void prepWorkOpen(basUniF p, void* o);
		extern char prepPassF(char x, int l, unsigned int t, char flagForceW2FrcTke3Bth);
		extern void prepBegin();
				

	//NetClient
		extern void netCBegin();
				

	//vlc
		extern vlcModEn vlcMode;
		extern char vlcClosePlayer();
		extern char vlcSrcCF(char* buf, int bufL);
		extern char vlcOffCF(char* buf);
		extern char vlcSysOffCF(char* buf);
		extern char vlcSrcPssF(char* buf, int bufL, unsigned int tim);
		extern void vlcClearF();
		

	//feh
		extern void fehMes(short x, char y);
		extern void fehMesChan(short x);


	//rc socket
		#define _RCTPCV_join(x) (x*2)
		#define _RCTPCV_detach(x) (x*2+1)
		typedef struct rcStrStr { int l; char b[1000]; }rcStrStr;
		typedef enum { rcType_none, rcType_string, rcType_rcStr, rcType_stringOn, rcType_stringOff, rcType_stringAdd } rcTypeEn;
		extern rcStrStr rcStrS[4];
		extern void rcBegin();
		extern int rcPassF(void* passV, rcTypeEn passT, char* buf);
		extern int rcAddcp(char* x, char* y);
		extern rcStrStr* rcStrGet();
		extern void rcStrRet(rcStrStr* x);


#endif