#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
	int fileDescriptor, bytes, i, k;
	char* a;

	if (argc == 3)
	{
		open(argv[1], 0x200);
			
		fileDescriptor = open(argv[1], 0x001);

		bytes = atoi(argv[2]);
	
		a = (char*)malloc(bytes);

 		k = 0;
		i = 0;
		if (i+512 < bytes)
		{
			for (i = 0; i+512< bytes; i+=512, k++)
			{
				memset(a, 'a'+ k, bytes);
				write(fileDescriptor, a, bytes);
			}
			memset(a, 'a'+ k, bytes % i);
			write(fileDescriptor, a, bytes % i);
		}
		else
		{
			memset(a, 'a'+ k, bytes);
			write(fileDescriptor, a, bytes);
		}
		exit();	
	}
	else
		printf("writer: Usage: writer <filename> <bytes>\n");
	exit();
}
