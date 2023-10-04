#include<stdio.h>
#include<stdlib.h>

/* The ENVIRON variable contains the environment */
extern char ** environ;

int main(int argc, char **argv)
{
	for(char **var = environ; *var ;var++){
		printf("%s\n",*var);
	}
	return EXIT_SUCCESS;
}
