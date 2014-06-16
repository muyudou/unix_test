#include "apue.h"
#include <fcntl.h>

char buf1[]="abcdefghij";
char buf2[]="ABCDEFGHIJ";

int main()
{
	int fd;

	if ((fd = creat("file.nohole", FILE_MODE)) < 0)
		err_sys("create error");
	if (write(fd, buf1, 10) != 10)
		err_sys("buf1 write error");

	if (write(fd, buf2, 10) != 10)
		err_sys("buf2 write error");
	exit(0);
}
