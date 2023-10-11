#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

sig_atomic_t sigusr1_count = 0;
void handler(int );

int main(int argc, char ** argv)
{
	struct sigaction sa;
	memset(&sa,0,sizeof(sa));
	sa.sa_handler = &handler;
	
	while(1)
		sigaction(SIGUSR1, &sa, NULL);
	
	return EXIT_SUCCESS;
}
void handler(int signal_number){
	if(++sigusr1_count == 3)
	{
		printf("SIGUSR1  was triggered %d times. Alright! I'm done.",sigusr1_count);
		exit(EXIT_SUCCESS);
	}
}

/*
 * To execute this program, open the terminal and type:
 * kill -s SIGUSR1 $(pidof ./executable)
 * */
