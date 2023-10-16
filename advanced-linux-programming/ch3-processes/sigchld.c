#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

sig_atomic_t child_exit_status;

void clean_up_child_process(int);

int main(int argc, char ** argv)
{
	
	/* Handle SIGCHLD by calling clean_up_child_proces. */
	struct sigaction sigchld_action;
	memset(&sigchld_action, 0 , sizeof(sigchld_action));
	sigchld_action.sa_handler = &clean_up_child_process;
	sigaction(SIGCHLD, &sigchld_action,NULL);
	
	pid_t child = fork();
	
	if(child  > 0){
		/* This is the parent process. Sleep for a minute */
		sleep(60);
	}else{
		puts("This is the child process.");
		/* Exit immediately */
		exit(0);
	}
	
	return EXIT_SUCCESS;
}

void clean_up_child_process(int signal_number)
{
	/* Clean up the child process */
	int status;
	wait(&status);
	/* Store its exit status in a global variable */
	child_exit_status = status;
	puts("Handling the SIGCHLD signal..");
}
