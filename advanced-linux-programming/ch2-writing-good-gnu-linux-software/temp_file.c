#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

/* A handle for a temporary file created with write_temp_file.
 * In this implementation, it's  just a file descriptor
 * 
 * */
typedef int temp_file_handle;

temp_file_handle write_temp_file(char *, size_t );
char *read_temp_file( temp_file_handle , size_t *);

int main(int argc, char **argv)
{
	/*
	 *  a handle for temporary file created with a write_temp_file. In this implementation
	 * , it's just a file descriptor.
	 * 
	 * 
	 * writes LENGTH bytes from buffer into a temporary file. The temporary file is immediately unlinked.
	 * Returns a handle to the temporary file.
	 * 
	 * */
	 char str[] = "Olá a todos, este é um arquivo temporário";
	 size_t size = strlen(str);
	 temp_file_handle fd = write_temp_file(str,size);
	 char *out = read_temp_file(fd,&size);
	 puts(out);
	 
	return EXIT_SUCCESS;
}

temp_file_handle write_temp_file(char *buffer, size_t length)
{
	 /*
	  * Create the filename and file. The XXXXXX will be replaced with characters
	  * that make the filename unique.
	  * */
	  char temp_filename[] = "/tmp/temp_file.XXXXXX";
	  int fd = mkstemp(temp_filename);
	  
	  /*
	   * Unlink the file immediately, so that it will be removed when the file 
	   * descriptor is closed.
	   * */
	   unlink(temp_filename);
	  
	  /*
	   * Write the number of bytes to the file first.
	   * */
	   write(fd, &length,sizeof(length));
	   
	   /*
	    * Now write the data itself */
	   write(fd,buffer, length);
	    
	    /* Use the file descriptor as the handle for the temporary file */
	    
	    return fd;
}

/*
 * Reads the contents of a temporary file TEMP_FILE created with write_temp_file.
 * The return value is a newly allocated buffer of  those contents, which the caller must
 * deallocate with free.
 * LENGTH is set to the size of the contents, in bytes. 
 * The temporary file is removed.
 * */
 
 char *read_temp_file( temp_file_handle temp_file, size_t *length)
 {
	 /* the TEMP_FILE handle is a file descriptor, to the temporary file */
	 int fd = temp_file;
	 /* Rewind to the beginning of the file */
	 lseek(fd, 0, SEEK_SET);
	 /* Read the size of the data in the temporary file */
	 read(fd, length, sizeof(*length));
	 /* Allocate a buffer and read the data */
	 char *buffer = (char *)malloc(*length);
	 read(fd,buffer, *length);
	 /* close the file descriptor, wich will cause the temporary file to go away */
	 
	 close(fd);
	 return buffer;	 
 }
