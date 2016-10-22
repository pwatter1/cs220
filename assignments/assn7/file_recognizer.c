#include <stdio.h>
#include <stdint.h>
#include <string.h>

int file_recognizer(char str[])
{
	FILE *op;
	op = fopen("Output.txt", "a");     //result appended to end of file

	/* list of file signatures */
	char gif[] = {"474946383961"};     //6 bytes
	char gif2[] = {"474946383761"};    //6
	char elf[] = {"7f454c46"};         //4
	char pdf[] = {"25504446"};         //4
	char zip[] = {"504b"};             //2
	char java[] = {"cafebabe"};        //4
	char png[] = {"89504e470d0a1a0a"}; //8
	
	/* little edian, switch byte order, convert to string */
	char full_sig[8];	
	uint32_t rev = htonl(*(uint32_t *) str);
	sprintf(full_sig, "%x", rev);
	printf("%s\n", full_sig);
	
	if((memcmp(full_sig, gif, 6) == 0) || (memcmp(full_sig, gif2, 6) == 0)){
		fprintf(op, "This is a GIF file.\n"); //correct
	}
	else if(memcmp(full_sig, elf, 4) == 0){
		fprintf(op, "This is an ELF file.\n"); //correct
	}
	else if(memcmp(full_sig, pdf, 4) == 0){
		fprintf(op, "This is a PDF file.\n"); //correct
	}
	else if(memcmp(full_sig, zip, 2) == 0){
		fprintf(op, "This is a ZIP file.\n"); //correct
	}
	else if(memcmp(full_sig, java, 4) == 0){
		fprintf(op, "This is a Java class file.\n"); //failing
	}
	else if(memcmp(full_sig, png, 8) == 0){
		fprintf(op, "This is a PNG file.\n"); //correct
	}else{
		fprintf(op, "File type unknown.\n");
	}
	
	printf("%02x%02x%02x%02x\n",str[0],str[1],str[2],str[3]); 
	return 0;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(argv[1], "rb");

	if(argc != 2){
		/* more than one input file other than program name */
		printf("Invalid input\n");
		return 1;
	}if(fp == (FILE *) NULL){
		/* could not open/read file correctly */
		printf("Invalid input\n");
		return 1;
	}else{
		/* read out first hex bytes and send to function */
		char sigs[8];
		fread(&sigs, sizeof(unsigned char), 8, fp);
	
		int i = 0;
		for(i; i<8; i++){
			printf("i: %02x\n", sigs[i]);
		}
		/* file_recognizer(sigs);*/
	}
	fclose(fp);
	return 0;
}
	
