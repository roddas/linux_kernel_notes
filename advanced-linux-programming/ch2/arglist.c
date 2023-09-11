#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	printf("The name of this program is '%s.'\n",argv[0]);
	printf("This program was invoked with %d arguments.\n",argc-1);
	
	/* Where any  command-line arguments specified? */
	if(argc > 1){
		printf("The arguments are:\n");
		for(int i = 1; i < argc;i++){
			puts(argv[i]);
		}
	}
	return EXIT_SUCCESS;
}
