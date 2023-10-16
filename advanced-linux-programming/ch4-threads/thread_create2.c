#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct {
	char character;
	int count;
}params;

void *char_print(void *);

int main(int argc, char ** argv)
{
	pthread_t thread_id1,thread_id2;
	params thread_param1,thread_param2;
	
	thread_param1.character = 'x';
	thread_param1.count = 300;
	pthread_create(&thread_id1, NULL, &char_print,&thread_param1);
	
	thread_param2.character = 'o';
	thread_param2.count = 300;
	pthread_create(&thread_id2, NULL, &char_print,&thread_param2);
	
	/* Make sure the first thread has finished. */
	pthread_join(thread_id1,NULL);
	/* Make sure the second thread has finished. */
	pthread_join(thread_id2,NULL);
	
	return EXIT_SUCCESS;
}
void *char_print(void *parameters)
{
	params *p = (params *)parameters;
	for(int i = 0; i < p->count; i++)
		fputc(p->character,stderr);
	
	return NULL;
}
