#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char ** argv)
{
	pid_t child = fork();
	
	if(child  > 0){
		/* This is the parent process. Sleep for a minute */
		sleep(60);
	}else{
		/* This is the child process. Exit immediately */
		exit(0);
	}
	return EXIT_SUCCESS;
}
