#include <stdio.h>
#include <stdlib.h>

int MAX_STRING_SIZE =20;

void printUsage(char appName[]);
int generateString(int,char *); 
int generateInt(int,char *); 
int generateFloat(int,char *); 

int main(int argc,char *argv[]){

	int rowSize = 0;
	char dataType,*fileName;
	if(argc == 5){
		printf("%s\n",argv[1]);
		dataType = argv[1][0];
		printf("%s\n",argv[2]);
		rowSize = atoi(argv[2]);
		printf("%s\n",argv[3]);
		printf("%s\n",argv[4]);
		fileName=argv[4];
		printf("%d\n",2%5);
	}else{
		printf("%s\n","wrong number arguments!");
		printUsage(argv[0]);
	}

	switch(dataType){
		case 's':
			generateString(rowSize,fileName);
			break;
		case 'i':
			generateInt(rowSize,fileName);
			break;
		case 'f':
			generateFloat(rowSize,fileName);
			break;
		default:{
			printf("%s%c\n","input wrong data type:",dataType);
			printUsage(argv[1]);
				}
	}
	printf("%s\n","hello,world!");
	return 0;
}

void printUsage(char appName[]){
	printf("%s%s%s\n","Usage:",appName," -c|i|f -n -f a.out");
}

int generateString(int rowSize,char *fileName){
	int i=0,j=0,randomColSize=0;
	char dataArray[rowSize][MAX_STRING_SIZE+1];
	char randomChar = '\0';
	FILE *fp;
    
	fp=fopen(fileName,"w");
	for(i=0;i<rowSize;i++){
		randomColSize = rand()%MAX_STRING_SIZE;
		if(randomColSize == 0)
			randomColSize =1;
		for(j=0;j<randomColSize;j++){
			dataArray[i][j] = (rand()%58+65);
		}
		dataArray[i][j] = '\n';
		printf("%s \n",dataArray[i]);
		fputs(dataArray[i],fp);
	}
	fclose(fp);
}

int generateInt(int rowSize,char *fileName){
	int i=0;
	int dataArray[rowSize];
	FILE *fp;
    
	fp=fopen(fileName,"w");
	for(i=0;i<rowSize;i++){
		dataArray[i] = rand();
		printf("%d \n",dataArray[i]);
		fprintf(fp,"%d\n",dataArray[i]);
	}
	fclose(fp);
}

int generateFloat(int rowSize,char *fileName){
	int i=0;
	float dataArray[rowSize];
	FILE *fp;
    
	fp=fopen(fileName,"w");
	for(i=0;i<rowSize;i++){
		dataArray[i] = rand()*1.0f/RAND_MAX;
		printf("%f \n",dataArray[i]);
		fprintf(fp,"%f\n",dataArray[i]);
	}
	fclose(fp);
}

