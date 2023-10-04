#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>

char *read_from_file(const char *,size_t );

int main(int argc, char **argv)
{
	char *file = read_from_file("/etc/passwd",100);
	if(file == NULL)
	{
		printf("%s\n",strerror(errno));
		exit(-1);
	}
	puts(file);
	return EXIT_SUCCESS;
}
char *read_from_file(const char *filename, size_t  length){
	
	char *buffer = NULL;
	int fd;
	ssize_t bytes_read;
	
	/* Allocate the buffer */
	buffer = (char *)malloc(length);
	if(buffer == NULL)
	{
		return NULL;	
	}
	
	/* Open the file */
	fd = open(filename,O_RDONLY);
	if(fd == -1){
		/* Open failed. Deallocate buffer before returning */
		free(buffer);
		return NULL;
	}
	
	/* Read the data */
	bytes_read = read(fd, buffer, length);
	if(bytes_read != length){
		/* Read failed. Deallocate buffer and close fd before returning */
		free(buffer);
		close(fd);
		return NULL;
	}
	
	/* Everything's fine. Close the file and return the buffer */
	close(fd);
	return buffer;
}
