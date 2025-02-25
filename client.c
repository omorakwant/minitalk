#include "minitalk.h"

// void handler(int signum)
// {
// 	printf("got signal %d \n", signum);
// 	exit(0);
// }
int main()
{
	int a;
	printf("entre d ipd server");
	scanf("%d",&a);

	kill(a,SIGUSR1);

	// signal(SIGINT, handler);
	// while(1)
	// {
	// 	printf("working\n");
	// 	sleep(1);
	// }
}