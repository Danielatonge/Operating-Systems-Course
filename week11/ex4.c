#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main()
{
	/* open source file*/
	int src = open("ex1.txt", O_RDONLY);
	if (src == -1)
	{
		printf("Error in opening the file 'ex1.txt'\n");
	}

	/* open destination file*/
	int dest = open("ex1.memcpy.txt", O_RDWR | O_CREAT, (mode_t)0777);
	if (dest == -1)
	{
		printf("Error in opening the file 'ex1.memcpy.txt'\n");
	}

	/* get the size of the source file*/
	struct stat src_buff;
	if (fstat(src, &src_buff) != 0)
	{
		perror("Unable to get stats of the file\n");
    	return 1;
	}
	size_t srcsize = src_buff.st_size;

	void *in = mmap(NULL, srcsize, PROT_READ, MAP_SHARED, src, 0);
  void *out = mmap(NULL, srcsize, PROT_WRITE | PROT_READ, MAP_SHARED, dest, 0);

    if (in == MAP_FAILED){
      close(src);
    	perror("Could not mmap");
    	return 1;
  	}

  	if (out == MAP_FAILED){
		  close(src);
		  close(dest);
    	perror("Could not mmap");
    	return 1;
  	}

    ftruncate(dest, srcsize);
  	/* copy the string from source map to destination map*/
  	memcpy(out, in, srcsize);


  	if (msync(out, srcsize, MS_SYNC) != 0)
  	{
  		close(src);
  		close(dest);
  		printf("Could not sync.\n");
  		return 1;
  	}

  	/*unmap*/
  	int unmap_src = munmap(in, srcsize);
  	if (unmap_src != 0)
  	{
  		close(src);
    	perror("Could not munmap the file\n");
    	return 1;
  	}

  	int unmap_dest = munmap(out, srcsize);
  	if (unmap_dest != 0)
  	{
  		close(dest);
    	perror("Could not munmap the file\n");
    	return 1;
  	}

  	close(src);
  	close(dest);

	return 0;
}
