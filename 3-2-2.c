#include "apue.h"
#include <fcntl.h>

#define BUFFSIZE 4096 

int main()
{
	int fd, fd1;
	int size;
    char* buf[BUFFSIZE];

	if ((fd = open("file.hole", O_RDONLY)) == -1)
		err_sys("open error");
	if ((size=read(fd, buf, BUFFSIZE)) == -1)
		err_sys("read error");
	else
	{
		printf("OK\n");
		printf("size:%d\n", size);
	    if ((fd1 = creat("file.nohole1", FILE_MODE)) < 0)
		    err_sys("creat error");
		if (write(fd1, buf, size) != size)
		    err_sys("write error");
	}
	close(fd);
	close(fd1);
	exit(0);
}
