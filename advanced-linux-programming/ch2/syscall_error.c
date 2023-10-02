#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<unistd.h>
#include<errno.h>

void chown_file(char *,uid_t, gid_t);

int main(int argc, char **argv)
{
	chown_file("/etc/passwd",getuid(),-1);
	return EXIT_SUCCESS;
}
void chown_file(char * path,uid_t user_id, gid_t group){
	int ret = chown(path, user_id, group);
	
	if(ret){
		/* Save the errno because it's clobbered by the next system call.  */
		int error_code = errno;
		/* The operation didn't succeded; chown shout return -1 on error */
		assert(ret == -1);
		/*  Check the value of errno, and take appropriate action */
		switch(error_code)
		{
			case EPERM: /* Permission denied */
			case EROFS: /* PATH is on a ready-only file system */
			case ENAMETOOLONG: /* PATH is too long */
			case ENOENT: /* PATH does not exists*/
			case ENOTDIR: /* A component of PATH is not a directory */
			case EACCES: /* A component of PATH if not accessible */
			
			/* Something's wrong with the file. Print an error message */
			fprintf(stderr,"Error changing ownership of %s: %s\n",path,strerror(error_code));
			/* Don't end the program; perhaps give the user a chance to choose another file...  */
			break;
			
			case EFAULT: /* Path contains an invalid memory address. This is probably a bug. */
				abort();
			
			case ENOMEM: /* Ran out of kernel memory */
				fprintf(stderr,"%s\n",strerror(error_code));
				exit(-1);
			
			default: /* Some other, unexpected, error code. We've tried to handle all possible error codes; if we've missed one,
			that's a bug */
			abort();
			
		}
	}
}
