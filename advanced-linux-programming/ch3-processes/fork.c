#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char ** argv)
{
	pid_t child_pid;
	
	printf("the main program process ID is %d\n",(int)getpid());
	
	child_pid = fork();
	if(child_pid != 0){
		printf("this is the parent process, with ID %d\n",(int) getpid());
		printf("this is the child process, with ID %d\n",(int)child_pid);
	}else{
		printf("this is the child process, with ID %d\n",(int)child_pid);
	}
	
	return EXIT_SUCCESS;
}
