#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>

const char *program_name = NULL;

void usage(FILE *, int);

int main(int argc, char **argv)
{
	int next_option;
	// A string listing valid short options letters
	const struct option long_options[] = {
		{"help",0,NULL,'h'},
		{"output",1,NULL,'o'},
		{"verbose",0,NULL,'v'},
		{NULL,0,NULL,0} // Required at the end of array
	};
	
	// An array describing valid shorts options letters
	const char * short_options = "ho:v";
	// The name of the file to receive program output, or NULL for standard output
	const char *output_filename = NULL;
	// Wether to display verbose messages
	int verbose = 0;
	program_name = argv[0];
	
	do{
		next_option = getopt_long(argc, argv, short_options, long_options,NULL);
		switch(next_option){
			case 'h' : {usage(stdout,0);}
			case 'o' : {
				output_filename = optarg;
				puts(output_filename);
				break;
			}
			case 'v':{
				verbose = 1;
				break;
			}
			case '?':{
				usage(stderr,1);
			}
			default:{
				abort();
			}
		}
	}while(next_option != -1);
		
	if(verbose){
		for(int i = optind; i < argc;i++ ){
			printf("Argument: %s\n",argv[i]);
		}
	}
	
	return EXIT_SUCCESS;
}

/* 
 * Prints usage information for this program to STREAM (typically stdout or stderr),
 * and exit) the program with EXIT_CODE. Does not return
 * */
void usage(FILE *stream, int exit_code)
{
	fprintf(stream," Usage %s: options [ inputfile ... ]\n",program_name);
	fprintf(stream,
	"  -h  --help    Display this usage information.\n"
	"  -o  --output    Write output to file.\n"
	"  -v  --verbose    Print verbose messages.\n"	
	);
	exit(exit_code);
}
