#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

static int MAX_STRING_LENGTH = 20;

void quickSortString(int,char []);
int cmpstr(const void *a,const void *b){
	return strcmp(*(char **)a,*(char **)b);
}


int main(int argc,char *argv[]){
	char *fileName, dataType;
	int dataSize = 0;

	if(argc == 4){
		dataType = argv[1][0];
		dataSize = atoi(argv[2]);
		fileName = argv[3];
	}else
		printf("Usage:%s s|i|f n fileName\n",argv[0]);

	switch(dataType){
		case 's':
			quickSortString(dataSize,fileName);
			break;
		default:
			printf("Wrong input type :%c \n",dataType);
	}
	return 0;
}

void quickSortString(int dataSize,char fileName[]){
	char stringData[dataSize][MAX_STRING_LENGTH]; 
	char *stringDataPointer[dataSize]; 
	FILE *fp = fopen(fileName,"r");
	int i=0;
	long usednsec;
	struct timespec startTime,endTime;

	for(i=0;fgets(stringData[i],MAX_STRING_LENGTH,fp) != NULL;i++)
		printf("%s",stringData[i]);
		;
	for(i=0;i<dataSize;i++)
		stringDataPointer[i]=stringData[i];
		;

	clock_gettime(CLOCK_REALTIME,&startTime);

	qsort(stringDataPointer,dataSize,sizeof(char *),cmpstr);

	clock_gettime(CLOCK_REALTIME,&endTime);
	usednsec = (endTime.tv_sec-startTime.tv_sec)*1000000000+endTime.tv_nsec-startTime.tv_nsec;
	printf("use time : %ld ns\n",usednsec);
	for(i=0;i<dataSize;i++)
		printf("%s",stringDataPointer[i]);
}

