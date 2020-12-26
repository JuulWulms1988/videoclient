#include "JW_88_vlcClient.h"

__workerTh_ mainWork;

const char* mainBasString[] = { "shutdown", "clear" };
unsigned int mainTime = 0;

static void* timF() { for (;;) mainTime++, usleep(10000); }

int main() {
	//load
		//Prep
			prepBegin();
			
		
		//VLC:
			rcBegin();
			

		//Executor:
			execBegin();
			
			
		//Timer
			{ pthread_t t; pthread_create(&t, NULL, timF, NULL); pthread_detach(t); }
			

		//Netclient
			netCBegin();
			

	return 0;
}