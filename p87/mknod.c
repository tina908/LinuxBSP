#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int arc, char *argv[])
{
	int ret;
	ret = mknod("/dev/test",S_IRWXU | S_IRWXG | S_IRWXO | S_IFCHR, (240<<8) | 1);
	if(ret<0)
	{
		perror("mknod()");
//		return 1;
		return EACCES;
	}
	ret = open("/dev/test",O_RDONLY);
	if(ret<0)
	{
		perror("open()");
		return 2;
	}
	return 0;
}
