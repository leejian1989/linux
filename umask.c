#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include "ourhdr.h"

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main()
{
	umask(0);
	if(creat("foo",RWRWRW)<0)
		printf("foo error\n");
	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	if(creat("bar",RWRWRW)<0)
		printf("bar error\n");
}

