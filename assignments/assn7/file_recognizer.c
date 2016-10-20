












int main(int argc, char *argv[])
{
	/* Validate command line arguments and try to open the file. Exit on failure. */
	FILE *fp;

	if(argc != 2){
		printf("Invalid number of command line arguments, expects 2.");
		return 1;
	}
 	fp = fopen(argv[1], "r");
	if(fp == (FILE *) NULL){
		printf("File not found: %s", argv[1]);
		return 1;
	}else{
		/* call functions to recognize file format */
	}
	return 0;
}
	
