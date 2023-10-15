#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>

int spawn(char *, char **);

int main(int argc, char ** argv)
{
	int child_status;
	 /* The argument list to pass to the "ls" command */
	 char *arg_list [] = {
		 "ls","-l","/",NULL
	 };
	spawn("ls", arg_list);
	wait(&child_status);
	
	if(WIFEXITED(child_status))
		puts("Done with main program.");
	else
		puts("The child exited abnormally.");
	return EXIT_SUCCESS;
}

int spawn(char *program, char ** arg_list){
	pid_t child_pid;
	
	/* Duplicate this process */
	child_pid = fork();
	if(child_pid != 0)
		/* This is the parent process. */
		return child_pid;
	
	/* Now execute the PROGRAM, searching for it in the path. */
	execvp(program, arg_list);
	/* The execvp function return only if an errors occurs.  */
	fprintf(stderr,"An error occured in execvp\n");
	abort();
}
