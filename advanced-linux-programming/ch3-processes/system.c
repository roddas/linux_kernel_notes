#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv)
{
	printf("%d\n",system("ls -l /"));
	
	return EXIT_SUCCESS;
}
