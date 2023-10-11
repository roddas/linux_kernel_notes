#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

/*
 * Spawn a child process running a new program. PROGRAM  is the name
 * of the program ro run; the path will be searched for this program.
 * ARG_LIST  is a NULL-terminated list of character strings to be 
 * passwed as the program's argument list. Returns the process ID of the 
 * spawned process.
 * */
int spawn(char *, char **);

int main(int argc, char ** argv)
{

	 /* The argument list to pass to the "ls" command */
	 char *arg_list [] = {
		 "ls","-l","/",NULL
	 };
	spawn("ls", arg_list);
	puts("Done with main program.");
	
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
