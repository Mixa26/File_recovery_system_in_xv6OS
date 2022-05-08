#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
	int k;

	if (argc == 2)
	{
		k = rec(argv[1]);
	}
	else if (argc < 2)
	{
		printf("rec: Usage: rec <filename>.\n");
	}
	else 
	{
		printf("rec: Too many arguments.\n");
	}

	if (k == 0)
	{
		printf("rec: Inode restored successfully.\n");
	}	
	else if (k == -1)
	{
		printf("rec: Bad filepath.\n");
	}
	else if (k == -2)
	{
		printf("rec: File not found.\n");
	}
	else if (k == -3)
	{
		printf("rec: Inode has been used for something else.\n");
	}
	else if (k == -4)
	{
		printf("rec: Some memory blocks have been used.\n");
	}
	exit();
}
