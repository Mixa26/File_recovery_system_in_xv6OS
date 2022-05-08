#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
	int i;
	char *result = malloc(64*14);
	//char matrix[64][14];
	//char *result;
	//result = matrix[0];
	int k;	
	int j;	

	if(argc < 2){
		k = lsdel(".", result);
		if (k == 0)
		{
			printf("Nothing recoverable has been deleted in this directory.\n");
			exit();
		}
		else if (k == -1)
		{
			printf("Non existent directory.\n");
		}
		for (j = 0; j < k; j++)
			printf("%s\n", result+(14*j));
			//printf("%s\n", result[j]);
			
	}
	for(i=1; i<argc; i++)
	{
		k = lsdel(argv[i], result);
		if (k == 0)
		{
			printf("Nothing recoverable has been deleted in this directory.\n");
			exit();
		}
		else if (k == -1)
		{
			printf("Non existent directory.\n");
		}
		for (j = 0; j < k; j++)
			printf("%s\n", result+(14*j));
			//printf("%s\n", result[j]);
			
	}

	exit();
}
