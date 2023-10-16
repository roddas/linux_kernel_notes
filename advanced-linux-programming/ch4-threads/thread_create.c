#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_xs(void *);

int main(int argc, char ** argv)
{
	pthread_t thread_id;
	int count = 0;
	
	/* Create a new thread. The new thread will run the print_xs function */
	pthread_create(&thread_id, NULL, &print_xs,NULL);
	
	/* Print o's continuosly to stderr */
	while(count++ < 100)
		fputc('o',stderr);
	return EXIT_SUCCESS;
}

/* Prints x's to stderr and the parameter is unused. Does not return */
void *print_xs(void *unused)
{
	while(1)
		fputc('x',stderr);
	return NULL;
}
